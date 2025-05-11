#ifndef MDC_CODE_GEN_H
#define MDC_CODE_GEN_H

#define MDCGEN_API static

#include "mdc_string_view.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

MDCGEN_API const_string_view_t mdcgen_get_struct_tag(struct mdc_const_string_view struct_definition);
MDCGEN_API const_string_view_t mdcgen_get_func_name(struct mdc_const_string_view func);
MDCGEN_API struct mdc_string_view mdcgen_identifier_safe_typename(struct mdc_const_string_view generic, struct mdc_string_view memory);
MDCGEN_API struct mdc_string_view mdcgen_compile_generic_struct(struct mdc_const_string_view generic_struct, struct mdc_const_string_view generic_arg, struct mdc_const_string_view type_arg, struct mdc_string_view memory);
MDCGEN_API string_view_t mdcgen_header_guard_begin(const_string_view_t name, string_view_t memory);
MDCGEN_API string_view_t mdcgen_header_guard_end(const_string_view_t name, string_view_t memory);
MDCGEN_API string_view_t mdcgen_write(const_string_view_t code, string_view_t memory);
MDCGEN_API string_view_t mdcgen_Generic_struct_begin(const_string_view_t name, const const_string_view_t *generic_args, size_t generic_args_count, string_view_t memory);
MDCGEN_API string_view_t mdcgen_Generic_struct_match(const_string_view_t struct_tag, const const_string_view_t *generic_args, size_t generic_args_count, const const_string_view_t *type_args, size_t type_args_count, string_view_t memory);
MDCGEN_API string_view_t mdcgen_Generic_struct_end(string_view_t memory);
MDCGEN_API string_view_t mdcgen_Generic_func_begin(const_string_view_t name, string_view_t memory);
MDCGEN_API string_view_t mdcgen_Generic_func_match(const_string_view_t func_name, const const_string_view_t *generic_args, size_t generic_args_count, string_view_t memory);
MDCGEN_API string_view_t mdcgen_Generic_func_end(string_view_t memory);

// TODO: This approach results in combinatorial explosion when using multiple generic arguments.
MDCGEN_API struct mdc_string_view mdcgen_compile_generic_structs(const_string_view_t generic_struct,
    const const_string_view_t *generic_args, ssize_t generic_args_count,
    const const_string_view_t *type_args, ssize_t type_args_count, string_view_t memory);
// TODO: This approach results in combinatorial explosion when using multiple generic arguments.
MDCGEN_API struct mdc_string_view mdcgen_compile_generic_funcs(const_string_view_t generic_func,
    const const_string_view_t *generic_args, ssize_t generic_args_count,
    const const_string_view_t *type_args, ssize_t type_args_count, string_view_t memory);

#if defined(MDC_CODE_GEN_IMPLEMENTATION)

#if !defined(MDC_GENERIC)
#   define MDC_GENERIC(...)
#endif

#define MDC_STRINGIFY(X) #X

#define MDCGEN_BUFFER_SIZE (1 << 15)
#define MDCGEN_NEW_BUFFER() SV_BUFFER(MDCGEN_BUFFER_SIZE)

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
    return mdc_sv_format("%.*s", memory, code.length, code.data);
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

string_view_t mdcgen_Generic_struct_begin(const const_string_view_t name, const const_string_view_t *generic_args, const size_t generic_args_count, const string_view_t memory) {
    ssize_t written = 0;
    written += mdc_sv_format("#define %.*s(", sv_slice(memory, 0, memory.length), (int) name.length, name.data).length;
    for (ssize_t i = 0; i < generic_args_count; i++) {
        const const_string_view_t generic_arg = generic_args[i];
        written += mdc_sv_format("%.*s", sv_slice(memory, written, memory.length), (int) generic_arg.length, generic_arg.data).length;
        if (i < generic_args_count - 1) {
            written += mdc_sv_format(", ", sv_slice(memory, written, memory.length)).length;
        }
    }
    written += mdc_sv_format(") typeof(\\\n", sv_slice(memory, written, memory.length)).length;
    return sv_slice(memory, 0, written);
}

static string_view_t mdcgen_Generic_struct_match_recurse(const const_string_view_t struct_tag,
    const const_string_view_t *generic_args, const size_t generic_args_count,
    const const_string_view_t *type_args, const size_t type_args_count,
    const const_string_view_t current_name,
    const string_view_t memory) {
    if (generic_args_count == 1) {
        ssize_t written = 0;
        written += mdc_sv_format("_Generic( (*((%.*s*)NULL)) \\\n", sv_slice(memory, written, memory.length),
            (int) generic_args->length, generic_args->data
        ).length;
        for (ssize_t j = 0; j < type_args_count; j++) {
            const const_string_view_t type_arg = type_args[j];
            const const_string_view_t id_safe_arg = mdcgen_identifier_safe_typename(
                mdc_sv_format("%.*s_%.*s", sv_slice(memory, written, memory.length), (int) current_name.length, current_name.data, (int) type_arg.length, type_arg.data).as_const
            , MDCGEN_NEW_BUFFER()).as_const;
            written += mdc_sv_format(
                ",   %.*s: (*(struct %.*s%.*s *)NULL)\\\n",
                sv_slice(memory, written, memory.length),
                (int) type_arg.length, type_arg.data,
                (int) struct_tag.length, struct_tag.data,
                (int) id_safe_arg.length, id_safe_arg.data
            ).length;
        }
        return sv_slice(memory, 0, written);
    }

    const const_string_view_t generic_arg = generic_args[generic_args_count - 1];
    ssize_t written = 0;
    written += mdc_sv_format("_Generic( (*((%.*s*)NULL)) \\\n", sv_slice(memory, written, memory.length),
        (int) generic_arg.length, generic_arg.data
    ).length;

    for (ssize_t i = 0; i < type_args_count; i++) {
        const const_string_view_t type_arg = type_args[i];
        const const_string_view_t id_safe_arg = mdcgen_identifier_safe_typename(
            mdc_sv_format("%.*s_%.*s", sv_slice(memory, written, memory.length), (int) current_name.length, current_name.data, (int) type_arg.length, type_arg.data).as_const
        , MDCGEN_NEW_BUFFER()).as_const;
        written += mdc_sv_format(", %.*s: ", sv_slice(memory, written, memory.length), (int) type_arg.length, type_arg.data).length;
        written += mdcgen_Generic_struct_match_recurse(struct_tag, generic_args, generic_args_count - 1, type_args, type_args_count, id_safe_arg, sv_slice(memory, written, memory.length)).length;
        written += mdc_sv_format(")\\\n", sv_slice(memory, written, memory.length)).length;
    }
    return sv_slice(memory, 0, written);
}
string_view_t mdcgen_Generic_struct_match(const const_string_view_t struct_tag,
    const const_string_view_t *generic_args, const size_t generic_args_count,
    const const_string_view_t *type_args, const size_t type_args_count, const string_view_t memory) {
    return mdcgen_Generic_struct_match_recurse(struct_tag, generic_args, generic_args_count, type_args, type_args_count, SV(""), memory);
}

string_view_t mdcgen_Generic_struct_end(const string_view_t memory) {
    ssize_t written = 0;
    written += mdcgen_write(SV("))\n"), sv_slice(memory, written, memory.length)).length;
    return sv_slice(memory, 0, written);
}

string_view_t mdcgen_Generic_func_begin(const const_string_view_t name, const string_view_t memory) {
    return mdc_sv_format("#define %.*s(T) _Generic( (*((T*)NULL)) \\\n",
        sv_slice(memory, 0, memory.length),
        (int) name.length, name.data
    );
}

string_view_t mdcgen_Generic_func_match(const const_string_view_t func_name, const const_string_view_t *generic_args, const size_t generic_args_count, const string_view_t memory) {
    ssize_t written = 0;
    for (ssize_t i = 0; i < generic_args_count; i++) {
        const const_string_view_t generic_arg = generic_args[i];
        const const_string_view_t id_safe_arg = mdcgen_identifier_safe_typename(generic_arg, MDCGEN_NEW_BUFFER()).as_const;
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
    return mdcgen_write(SV(")\n"), memory);
}

struct mdc_string_view mdcgen_compile_generic_struct(const struct mdc_const_string_view generic_struct, const struct mdc_const_string_view generic_arg, const struct mdc_const_string_view type_arg, const struct mdc_string_view memory) {
    const struct mdc_const_string_view id_safe_typename = mdcgen_identifier_safe_typename(type_arg, MDCGEN_NEW_BUFFER()).as_const;
    const struct mdc_const_string_view struct_tag = mdcgen_get_struct_tag(generic_struct);
    struct mdc_const_string_view compiled_generic = generic_struct;
    compiled_generic = mdc_sv_replace(compiled_generic,
        struct_tag,
        mdc_sv_format("%.*s_%.*s", MDCGEN_NEW_BUFFER(),
            (int)struct_tag.length, struct_tag.data,
            (int)id_safe_typename.length, id_safe_typename.data).as_const,
        MDCGEN_NEW_BUFFER()
    ).as_const;
    compiled_generic = mdc_sv_replace(compiled_generic,
        generic_arg,
        type_arg,
        MDCGEN_NEW_BUFFER()
    ).as_const;
    return mdc_sv_format("%.*s\n", memory, (int) compiled_generic.length, compiled_generic.data);
}

static struct mdc_string_view mdcgen_compile_generic_func(const struct mdc_const_string_view generic_func, const const_string_view_t generic_arg, const const_string_view_t type_arg, const struct mdc_string_view memory) {
    const struct mdc_const_string_view id_safe_typename = mdcgen_identifier_safe_typename(type_arg, MDCGEN_NEW_BUFFER()).as_const;
    const struct mdc_const_string_view func_name = mdcgen_get_func_name(generic_func);
    struct mdc_const_string_view compiled_generic = generic_func;
    compiled_generic = mdc_sv_replace(compiled_generic,
        func_name,
        mdc_sv_format("%.*s_%.*s", MDCGEN_NEW_BUFFER(),
            (int)func_name.length, func_name.data,
            (int)id_safe_typename.length, id_safe_typename.data).as_const,
        MDCGEN_NEW_BUFFER()
    ).as_const;
    compiled_generic = mdc_sv_replace(compiled_generic,
        generic_arg,
        type_arg,
        MDCGEN_NEW_BUFFER()
    ).as_const;
    return mdc_sv_format("%.*s\n", memory, (int) compiled_generic.length, compiled_generic.data);
}

static size_t mdcgen_compile_generic_structs_recurse(
    const const_string_view_t generic_struct,
    const const_string_view_t *generic_args, const ssize_t generic_args_count,
    const const_string_view_t *type_args, const ssize_t type_args_count,
    const string_view_t memory) {

    const const_string_view_t generic_arg = generic_args[generic_args_count - 1];

    if (generic_args_count == 1) {
        ssize_t written = 0;
        for (ssize_t i = 0; i < type_args_count; i++) {
            const const_string_view_t type_arg = type_args[i];
            written += mdcgen_compile_generic_struct(generic_struct,
                generic_arg,
                type_arg,
                sv_slice(memory, written, memory.length)
            ).length;
        }
        return written;
    }

    ssize_t writen = 0;
    for (ssize_t i = 0; i < type_args_count; i++) {
        const const_string_view_t type_arg = type_args[i];
        const const_string_view_t result = mdc_sv_clone(
            mdcgen_compile_generic_struct(
                generic_struct, generic_arg, type_arg, sv_slice(memory, writen, memory.length)
            ).as_const,
            MDCGEN_NEW_BUFFER()
        ).as_const;

        writen += mdcgen_compile_generic_structs_recurse(result,
            generic_args, generic_args_count - 1,
            type_args, type_args_count,
            sv_slice(memory, writen, memory.length)
        );
    }
    return writen;
}

string_view_t mdcgen_compile_generic_structs(const const_string_view_t generic_struct,
    const const_string_view_t *generic_args, const ssize_t generic_args_count,
    const const_string_view_t *type_args, const ssize_t type_args_count, const string_view_t memory) {
    ssize_t written = 0;
    const const_string_view_t struct_tag = mdcgen_get_struct_tag(generic_struct);
    written += mdcgen_Generic_struct_begin(struct_tag, generic_args, generic_args_count, sv_slice(memory, written, memory.length)).length;
    written += mdcgen_Generic_struct_match(struct_tag, generic_args, generic_args_count, type_args, type_args_count, mdc_sv_slice(memory, written, memory.length)).length;
    written += mdcgen_Generic_struct_end(mdc_sv_slice(memory, written, memory.length)).length;

    written += mdcgen_compile_generic_structs_recurse(generic_struct,
        generic_args, generic_args_count,
        type_args, type_args_count,
        mdc_sv_slice(memory, written, memory.length)
    );

    return mdc_sv_slice(memory, 0, written);
}

string_view_t mdcgen_compile_generic_funcs(
    const const_string_view_t generic_func,
    const const_string_view_t *generic_args,
    const ssize_t generic_args_count,
    const const_string_view_t *type_args,
    const ssize_t type_args_count,
    const string_view_t memory)
{
    ssize_t written = 0;
    const const_string_view_t func_name = mdcgen_get_func_name(generic_func);
    written += mdcgen_Generic_func_begin(func_name, mdc_sv_slice(memory, written, memory.length)).length;
    written += mdcgen_Generic_func_match(func_name, type_args, type_args_count, mdc_sv_slice(memory, written, memory.length)).length;
    written += mdcgen_Generic_func_end(mdc_sv_slice(memory, written, memory.length)).length;
    for (ssize_t i = 0; i < type_args_count; i++)
    for (ssize_t j = 0; j < generic_args_count; j++) {
        const const_string_view_t type_arg = type_args[i];
        const const_string_view_t generic_arg = generic_args[j];
        written += mdcgen_compile_generic_func(generic_func,
            generic_arg,
            type_arg,
            mdc_sv_slice(memory, written, memory.length)
        ).length;
    }
    return mdc_sv_slice(memory, 0, written);
}

#endif //MDC_CODE_GEN_IMPLEMENTATION
#endif //MDC_CODE_GEN_H
