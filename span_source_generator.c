#define MDC_STRING_VIEW_IMPLEMENTATION
#define MDC_CODE_GEN_IMPLEMENTATION
#include <stdio.h>
#include "mdc_string_view.h"
#include "mdc_code_gen.h"

static const_string_view_t stdint_typenames[] = {
    SV("char"),
    SV("void*"),
    SV("uint8_t"),
    SV("int8_t"),
    SV("uint16_t"),
    SV("int16_t"),
    SV("uint32_t"),
    SV("int32_t"),
    SV("uint64_t"),
    SV("int64_t"),
    SV("float"),
    SV("double"),
};

#if !defined(ARRAY_SIZE)
#   define ARRAY_SIZE(X) (sizeof(X) / sizeof(X[0]))
#endif

#define RVALUE_ADDR(X) ((typeof(X)[1]){X})

int main(const int argc, char **argv) {

    const_string_view_t const CONST_SPAN_T_STRUCT = SV(
        "struct mdc_const_span {" "\n"
            "const T *data;" "\n"
            "size_t length;" "\n"
        "};" "\n"
    );

    const_string_view_t const SPAN_T_STRUCT = SV(
        "struct mdc_span {" "\n"
        "   union {" "\n"
        "       struct {" "\n"
        "           T *data;" "\n"
        "           size_t length;" "\n"
        "       };" "\n"
        "       mdc_const_span(T) as_const;" "\n"
        "   };" "\n"
        "};" "\n"
    );

    const_string_view_t const SHORT_NAMES = SV(
        "#if !defined(MDC_SPAN_NO_SHORT_NAMES)" "\n"
        "#   define span mdc_span" "\n"
        "#   define const_span mdc_const_span" "\n"
        "#   define span_new mdc_span_new" "\n"
        "#   define span_slice mdc_span_slice" "\n"
        "#endif //MDC_SPAN_NO_SHORT_NAMES" "\n"
    );

    const_string_view_t const SPAN_LITERAL = SV(
        "#define mdc_span_new(T, ...)\\" "\n"
        "((span(T)) { .data = (T[]){__VA_ARGS__}, .length = sizeof((T[]){__VA_ARGS__}) / sizeof(T) })" "\n"
    );

    const_string_view_t const SPAN_SLICE = SV(
        "mdc_span(T) mdc_span_slice(mdc_span(T) _span, size_t offset, size_t count) {" "\n"
        "   return (mdc_span(T)) {" "\n"
        "       .data = _span.data + offset," "\n"
        "       .length = count" "\n"
        "   };" "\n"
        "}" "\n"
    );

    const_string_view_t const TUPLE2_STRUCT = SV(
        "struct mdc_tuple2 {" "\n"
        "   T1 t1;" "\n"
        "   T2 t2;" "\n"
        "};" "\n"
    );

    const_string_view_t const TUPLE3_T_STRUCT = SV(
        "struct mdc_tuple3 {" "\n"
        "   T1 t1;" "\n"
        "   T2 t2;" "\n"
        "   T3 t3;" "\n"
        "};" "\n"
    );

    const char *output_file = "mdc_span.h";
    const char *output_dir = "C:/Users/caita/CLionProjects/untitled/";
    char *fullpath = malloc(strlen(output_dir) + strlen(output_file) + 1);
    strcpy(fullpath, output_dir);
    strcat(fullpath, output_file);

    FILE *f = fopen(fullpath, "w");
    const string_view_t buffer = SV_BUFFER(100*4096);
    string_view_t window = buffer;
    string_view_t result = {};

    result = mdcgen_header_guard_begin(SV("MDC_SPAN_G"), window);
    window = sv_slice(window, result.length, buffer.length);

    result = mdcgen_write(SHORT_NAMES, window);
    window = sv_slice(window, result.length, buffer.length);

    result = mdcgen_write(SPAN_LITERAL, window);
    window = sv_slice(window, result.length, buffer.length);

    result = mdcgen_write(SV("#include <stdint.h>\n"), window);
    window = sv_slice(window, result.length, buffer.length);

    result = mdcgen_compile_generic_structs(CONST_SPAN_T_STRUCT, &SV("T"), 1, stdint_typenames, ARRAY_SIZE(stdint_typenames), window);
    window = sv_slice(window, result.length, buffer.length);

    result = mdcgen_compile_generic_structs(SPAN_T_STRUCT, &SV("T"), 1, stdint_typenames, ARRAY_SIZE(stdint_typenames), window);
    window = sv_slice(window, result.length, buffer.length);

    result = mdcgen_compile_generic_funcs(SPAN_SLICE, &SV("T"), 1, stdint_typenames, ARRAY_SIZE(stdint_typenames), window);
    window = sv_slice(window, result.length, buffer.length);

    result = mdcgen_compile_generic_structs(TUPLE2_STRUCT, (const_string_view_t[]){ SV("T1"), SV("T2") }, 2, stdint_typenames, ARRAY_SIZE(stdint_typenames), window);
    window = sv_slice(window, result.length, buffer.length);

    result = mdcgen_compile_generic_structs(TUPLE3_T_STRUCT, (const_string_view_t[]){ SV("T1"), SV("T2"), SV("T3") }, 3, stdint_typenames, ARRAY_SIZE(stdint_typenames), window);
    window = sv_slice(window, result.length, buffer.length);


    result = mdcgen_header_guard_end(SV("MDC_SPAN_G"), window);
    window = sv_slice(window, result.length, buffer.length);

    fprintf(f, "%.*s\n", (int) buffer.length, buffer.data);
    fclose(f);

    char *command = malloc(strlen("gcc -fsyntax-only -std=c2x -c ") + strlen(fullpath) + 1);
    strcpy(command, "gcc -fsyntax-only -std=c2x -c ");
    strcat(command, fullpath);
    system(command);
    free(command);
    free(fullpath);
    return 0;
}
