#ifndef MDC_CODE_GEN_H
#define MDC_CODE_GEN_H

#define MDCGEN_API static

#include "mdc_string_view.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

MDCGEN_API bool mdcgen_is_struct_definition(const_string_view_t str);
MDCGEN_API const_string_view_t mdcgen_get_struct_tag(struct mdc_const_string_view struct_definition);
MDCGEN_API struct mdc_string_view mdcgen_identifier_safe_typename(struct mdc_const_string_view generic, struct mdc_string_view memory);
MDCGEN_API struct mdc_string_view mdcgen_compile_generic_struct(struct mdc_const_string_view generic_struct, struct mdc_const_string_view generic_arg, struct mdc_string_view memory);
MDCGEN_API string_view_t mdcgen_header_guard_begin(const_string_view_t name, string_view_t memory);
MDCGEN_API string_view_t mdcgen_header_guard_end(const_string_view_t name, string_view_t memory);
MDCGEN_API string_view_t mdcgen_write(const_string_view_t code, string_view_t memory);
MDCGEN_API string_view_t mdcgen_Generic_struct_begin(const_string_view_t name, string_view_t memory);
MDCGEN_API string_view_t mdcgen_Generic_struct_match(const_string_view_t struct_tag, const const_string_view_t *generic_args, size_t generic_args_count, string_view_t memory);
MDCGEN_API string_view_t mdcgen_Generic_struct_end(string_view_t memory);

MDCGEN_API string_view_t mdcgen_Generic_func_begin(const_string_view_t name, string_view_t memory);
MDCGEN_API string_view_t mdcgen_Generic_func_match(const_string_view_t func_name, const const_string_view_t *generic_args, size_t generic_args_count, string_view_t memory);
MDCGEN_API string_view_t mdcgen_Generic_func_end(string_view_t memory);

MDCGEN_API struct mdc_string_view mdcgen_compile_generic_structs(const_string_view_t generic_struct, const const_string_view_t *generic_args, ssize_t generic_args_count, string_view_t memory);
MDCGEN_API struct mdc_string_view mdcgen_compile_generic_funcs(const_string_view_t generic_func, const const_string_view_t *generic_args, ssize_t generic_args_count, string_view_t memory);

#if defined(MDC_CODE_GEN_IMPLEMENTATION)

#if !defined(MDC_GENERIC)
#   define MDC_GENERIC(...)
#endif

#define MDC_STRINGIFY(X) #X

static struct mdc_string_view mdc_read_file_to_string_view(const char *path, const struct mdc_string_view memory) {
    FILE *file = fopen(path, "r");
    if (file == NULL) {
        return (mdc_string_view_t){};
    }
    fseek(file, 0, SEEK_END);
    size_t size = ftell(file);
    rewind(file);
    char *data = memory.data;
    ssize_t read = 0;
    while ((read = fread(data, 1, size, file)) > 0) {
        data += read;
        size -= read;
    }
    fclose(file);
    return memory;
}

bool mdcgen_is_struct_definition(const const_string_view_t str) {
    return mdc_sv_index_of(str, SV("struct")) >= 0
        && mdc_sv_index_of(str, SV("{")) >= 0
        && mdc_sv_index_of(str, SV("}")) >= 0;
}

const_string_view_t mdcgen_get_struct_tag(const struct mdc_const_string_view struct_definition) {
    const ssize_t index_of_struct = mdc_sv_index_of(struct_definition, MDC_SV("struct"));
    assert(index_of_struct >= 0 && "Invalid Argument expected a struct definition");
    const ssize_t index_of_name = index_of_struct + sizeof("struct") - 1;

    struct mdc_const_string_view name = mdc_sv_trim_const(
        mdc_sv_slice_const(struct_definition, index_of_name, struct_definition.length)
    );
    const ssize_t index_of_bracket = mdc_sv_index_of(name, MDC_SV("{"));
    if (index_of_bracket < 0) return name;
    name = mdc_sv_trim_const(
        mdc_sv_slice_const(name, index_of_struct, index_of_bracket - 1)
    );
    return name;
}

struct mdc_const_string_view mdcgen_get_func_name(struct mdc_const_string_view func) {
    while (func.data[0] != ' ') func = sv_slice_const(func, 1, func.length);

    const ssize_t index_of_bracket = mdc_sv_index_of(func, MDC_SV("("));
    if (index_of_bracket < 0) return func;
    return mdc_sv_trim_const(
        mdc_sv_slice_const(func, 0, index_of_bracket)
    );
}

struct mdc_string_view mdcgen_identifier_safe_typename(const struct mdc_const_string_view generic, const struct mdc_string_view memory) {
    struct mdc_string_view id_safe_generic = mdc_sv_clone(generic, memory);
    id_safe_generic = mdc_sv_trim(id_safe_generic);
    id_safe_generic = mdc_sv_replace(id_safe_generic.as_const, SV("*"), SV("_star"), memory);
    id_safe_generic = mdc_sv_replace(id_safe_generic.as_const, SV("{"), SV(""), memory);
    id_safe_generic = mdc_sv_replace(id_safe_generic.as_const, SV("}"), SV(""), memory);
    id_safe_generic = mdc_sv_replace(id_safe_generic.as_const, SV(";"), SV(""), memory);
    id_safe_generic = mdc_sv_replace(id_safe_generic.as_const, SV(" "), SV(""), memory);
    return id_safe_generic;
}

string_view_t mdcgen_write(const const_string_view_t code, const string_view_t memory) {
    return mdc_sv_format("%.*s\n", memory, code.length, code.data);
}

string_view_t mdcgen_header_guard_begin(const const_string_view_t name, const string_view_t memory) {
    return mdc_sv_format("#ifndef %.*s\n#define %.*s\n",
        mdc_sv_slice(memory, 0, memory.length),
        (int) name.length, name.data,
        (int) name.length, name.data,
        (int) name.length, name.data
    );
}

string_view_t mdcgen_header_guard_end(const const_string_view_t name, const string_view_t memory) {
    return mdc_sv_format("#endif //%.*s\n",
        mdc_sv_slice(memory, 0, memory.length),
        (int) name.length, name.data
    );
}

string_view_t mdcgen_Generic_struct_begin(const const_string_view_t name, const string_view_t memory) {
    return mdc_sv_format("#define %.*s(T) typeof(_Generic( (*((T*)NULL)) \\\n",
        mdc_sv_slice(memory, 0, memory.length),
        (int) name.length, name.data
    );
}

string_view_t mdcgen_Generic_struct_match(const const_string_view_t struct_tag, const const_string_view_t *generic_args, const size_t generic_args_count, const string_view_t memory) {
    ssize_t written = 0;
    for (ssize_t i = 0; i < generic_args_count; i++) {
        const const_string_view_t generic_arg = generic_args[i];
        const const_string_view_t id_safe_arg = mdcgen_identifier_safe_typename(generic_arg, SV_BUFFER(4096)).as_const;
        written += mdc_sv_format(
            ",   %.*s: (*(struct %.*s_%.*s *)NULL)\\\n",
            mdc_sv_slice(memory, written, memory.length),
            (int) generic_arg.length, generic_arg.data,
            (int) struct_tag.length, struct_tag.data,
            (int) id_safe_arg.length, id_safe_arg.data
        ).length;
    }
    return sv_slice(memory, 0, written);
}

string_view_t mdcgen_Generic_struct_end(const string_view_t memory) {
    return mdcgen_write(SV("))"), memory);
}

string_view_t mdcgen_Generic_func_begin(const const_string_view_t name, const string_view_t memory) {
    return mdc_sv_format("#define %.*s(T) _Generic( (*((T*)NULL)) \\\n",
        mdc_sv_slice(memory, 0, memory.length),
        (int) name.length, name.data
    );
}

string_view_t mdcgen_Generic_func_match(const const_string_view_t func_name, const const_string_view_t *generic_args, const size_t generic_args_count, const string_view_t memory) {
    ssize_t written = 0;
    for (ssize_t i = 0; i < generic_args_count; i++) {
        const const_string_view_t generic_arg = generic_args[i];
        const const_string_view_t id_safe_arg = mdcgen_identifier_safe_typename(generic_arg, SV_BUFFER(4096)).as_const;
        written += mdc_sv_format(
            ",   %.*s: %.*s_%.*s\\\n",
            mdc_sv_slice(memory, written, memory.length),
            (int) generic_arg.length, generic_arg.data,
            (int) func_name.length, func_name.data,
            (int) id_safe_arg.length, id_safe_arg.data
        ).length;
    }
    return sv_slice(memory, 0, written);
}

string_view_t mdcgen_Generic_func_end(const string_view_t memory) {
    return mdcgen_write(SV(")"), memory);
}

struct mdc_string_view mdcgen_compile_generic_struct(const struct mdc_const_string_view generic_struct, const struct mdc_const_string_view generic_arg, const struct mdc_string_view memory) {
    const struct mdc_const_string_view id_safe_generic = mdcgen_identifier_safe_typename(generic_arg, SV_BUFFER(4096)).as_const;
    const struct mdc_const_string_view struct_tag = mdcgen_get_struct_tag(generic_struct);
    struct mdc_const_string_view compiled_generic = generic_struct;
    compiled_generic = mdc_sv_replace(compiled_generic,
        struct_tag,
        mdc_sv_format("%.*s_%.*s", SV_BUFFER(4096),
            (int)struct_tag.length, struct_tag.data,
            (int)id_safe_generic.length, id_safe_generic.data).as_const,
        SV_BUFFER(4096)
    ).as_const;
    compiled_generic = mdc_sv_replace(compiled_generic,
        MDC_SV("T"),
        generic_arg,
        SV_BUFFER(4096)
    ).as_const;
    return mdc_sv_format("%.*s\n", memory, (int) compiled_generic.length, compiled_generic.data);
}

struct mdc_string_view mdcgen_compile_generic_func(const struct mdc_const_string_view generic_func, const struct mdc_const_string_view generic_arg, const struct mdc_string_view memory) {
    const struct mdc_const_string_view id_safe_generic = mdcgen_identifier_safe_typename(generic_arg, SV_BUFFER(4096)).as_const;
    const struct mdc_const_string_view func_name = mdcgen_get_func_name(generic_func);
    struct mdc_const_string_view compiled_generic = generic_func;
    compiled_generic = mdc_sv_replace(compiled_generic,
        func_name,
        mdc_sv_format("%.*s_%.*s", SV_BUFFER(4096),
            (int)func_name.length, func_name.data,
            (int)id_safe_generic.length, id_safe_generic.data).as_const,
        SV_BUFFER(4096)
    ).as_const;
    compiled_generic = mdc_sv_replace(compiled_generic,
        MDC_SV("T"),
        generic_arg,
        SV_BUFFER(4096)
    ).as_const;
    return mdc_sv_format("%.*s\n", memory, (int) compiled_generic.length, compiled_generic.data);
}

string_view_t mdcgen_compile_generic_structs(const const_string_view_t generic_struct, const const_string_view_t *generic_args, const ssize_t generic_args_count, const string_view_t memory) {
    ssize_t written = 0;
    const_string_view_t struct_tag = mdcgen_get_struct_tag(generic_struct);
    written += mdcgen_Generic_struct_begin(struct_tag, mdc_sv_slice(memory, written, memory.length)).length;
    written += mdcgen_Generic_struct_match(struct_tag, generic_args, generic_args_count, mdc_sv_slice(memory, written, memory.length)).length;
    written += mdcgen_Generic_struct_end(mdc_sv_slice(memory, written, memory.length)).length;
    for (ssize_t i = 0; i < generic_args_count; i++) {
        const const_string_view_t generic_arg = generic_args[i];
        written += mdcgen_compile_generic_struct(generic_struct,
            generic_arg,
            mdc_sv_slice(memory, written, memory.length)
        ).length;
    }
    return mdc_sv_slice(memory, 0, written);
}

string_view_t mdcgen_compile_generic_funcs(const const_string_view_t generic_func, const const_string_view_t *generic_args, const ssize_t generic_args_count, const string_view_t memory) {
    ssize_t written = 0;
    const const_string_view_t func_name = mdcgen_get_func_name(generic_func);
    written += mdcgen_Generic_func_begin(func_name, mdc_sv_slice(memory, written, memory.length)).length;
    written += mdcgen_Generic_func_match(func_name, generic_args, generic_args_count, mdc_sv_slice(memory, written, memory.length)).length;
    written += mdcgen_Generic_func_end(mdc_sv_slice(memory, written, memory.length)).length;
    for (ssize_t i = 0; i < generic_args_count; i++) {
        const const_string_view_t generic_arg = generic_args[i];
        written += mdcgen_compile_generic_func(generic_func,
            generic_arg,
            mdc_sv_slice(memory, written, memory.length)
        ).length;
    }
    return mdc_sv_slice(memory, 0, written);
}

#endif //MDC_CODE_GEN_IMPLEMENTATION
#endif //MDC_CODE_GEN_H
