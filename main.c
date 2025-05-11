#include <stdio.h>
#include "mdc_code_gen.h"
#include "mdc_string_view.h"
#include "mdc_span.h"

typedef struct pointf {
    float x;
    float y;
} pointf_t;

typedef struct point {
    double x;
    double y;
} point_t;

int main(const int argc, char **argv) {
    span(unsigned char) a = span_new(unsigned char, "0123456789");

    printf("A[char] Len: %d Values: [", (int) a.length);
    for (int i = 0; i < a.length; i++) {
        if (i > 0 && i < a.length) printf(", ");
        printf("'%c'", a.data[i]);
    }
    printf("]\n");

    span(unsigned char) b = span_slice(unsigned char)(a, 4, 5);

    printf("B[char] Len: %d Values: [", (int) b.length);
    for (int i = 0; i < b.length; i++) {
        if (i > 0 && i < b.length) printf(", ");
        printf("'%c'", b.data[i]);
    }
    printf("]\n");

    const auto duple = (mdc_tuple2(int,int)) {
        .t1 = 1,
        .t2 = 2
    };

    printf("Tuple: (%d, %d)\n", duple.t1, duple.t2);


    const auto triple = (mdc_tuple3(int,void*,int)) {
        .t1 = 1,
        .t2 = NULL,
        .t3 = 3
    };

    printf("Tuple: (%d, %p, %d)\n", triple.t1, triple.t2, triple.t3);

    return 0;
}
