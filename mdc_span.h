#ifndef MDC_SPAN_G
#define MDC_SPAN_G
#if !defined(MDC_SPAN_NO_SHORT_NAMES)
#   define span mdc_span
#   define const_span mdc_const_span
#   define span_new mdc_span_new
#   define span_slice mdc_span_slice
#endif //MDC_SPAN_NO_SHORT_NAMES

#define mdc_span_new(T, ...)\
((span(T)) { .data = (T[]){__VA_ARGS__}, .length = sizeof((T[]){__VA_ARGS__}) / sizeof(T) })

#include <stdint.h>

#define mdc_const_span(T) typeof(_Generic( (*((T*)NULL)) \
,   char: (*(struct mdc_const_span_char *)NULL)\
,   void*: (*(struct mdc_const_span_void_star *)NULL)\
,   uint8_t: (*(struct mdc_const_span_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_const_span_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_const_span_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_const_span_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_const_span_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_const_span_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_const_span_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_const_span_int64_t *)NULL)\
,   float: (*(struct mdc_const_span_float *)NULL)\
,   double: (*(struct mdc_const_span_double *)NULL)\
))
struct mdc_const_span_char {
const char *data;
size_t length;
};

struct mdc_const_span_void_star {
const void* *data;
size_t length;
};

struct mdc_const_span_uint8_t {
const uint8_t *data;
size_t length;
};

struct mdc_const_span_int8_t {
const int8_t *data;
size_t length;
};

struct mdc_const_span_uint16_t {
const uint16_t *data;
size_t length;
};

struct mdc_const_span_int16_t {
const int16_t *data;
size_t length;
};

struct mdc_const_span_uint32_t {
const uint32_t *data;
size_t length;
};

struct mdc_const_span_int32_t {
const int32_t *data;
size_t length;
};

struct mdc_const_span_uint64_t {
const uint64_t *data;
size_t length;
};

struct mdc_const_span_int64_t {
const int64_t *data;
size_t length;
};

struct mdc_const_span_float {
const float *data;
size_t length;
};

struct mdc_const_span_double {
const double *data;
size_t length;
};

#define mdc_span(T) typeof(_Generic( (*((T*)NULL)) \
,   char: (*(struct mdc_span_char *)NULL)\
,   void*: (*(struct mdc_span_void_star *)NULL)\
,   uint8_t: (*(struct mdc_span_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_span_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_span_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_span_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_span_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_span_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_span_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_span_int64_t *)NULL)\
,   float: (*(struct mdc_span_float *)NULL)\
,   double: (*(struct mdc_span_double *)NULL)\
))
struct mdc_span_char {
   union {
       struct {
           char *data;
           size_t length;
       };
       mdc_const_span(char) as_const;
   };
};

struct mdc_span_void_star {
   union {
       struct {
           void* *data;
           size_t length;
       };
       mdc_const_span(void*) as_const;
   };
};

struct mdc_span_uint8_t {
   union {
       struct {
           uint8_t *data;
           size_t length;
       };
       mdc_const_span(uint8_t) as_const;
   };
};

struct mdc_span_int8_t {
   union {
       struct {
           int8_t *data;
           size_t length;
       };
       mdc_const_span(int8_t) as_const;
   };
};

struct mdc_span_uint16_t {
   union {
       struct {
           uint16_t *data;
           size_t length;
       };
       mdc_const_span(uint16_t) as_const;
   };
};

struct mdc_span_int16_t {
   union {
       struct {
           int16_t *data;
           size_t length;
       };
       mdc_const_span(int16_t) as_const;
   };
};

struct mdc_span_uint32_t {
   union {
       struct {
           uint32_t *data;
           size_t length;
       };
       mdc_const_span(uint32_t) as_const;
   };
};

struct mdc_span_int32_t {
   union {
       struct {
           int32_t *data;
           size_t length;
       };
       mdc_const_span(int32_t) as_const;
   };
};

struct mdc_span_uint64_t {
   union {
       struct {
           uint64_t *data;
           size_t length;
       };
       mdc_const_span(uint64_t) as_const;
   };
};

struct mdc_span_int64_t {
   union {
       struct {
           int64_t *data;
           size_t length;
       };
       mdc_const_span(int64_t) as_const;
   };
};

struct mdc_span_float {
   union {
       struct {
           float *data;
           size_t length;
       };
       mdc_const_span(float) as_const;
   };
};

struct mdc_span_double {
   union {
       struct {
           double *data;
           size_t length;
       };
       mdc_const_span(double) as_const;
   };
};

#define mdc_span_slice(T) _Generic( (*((T*)NULL)) \
,   char: mdc_span_slice_char\
,   void*: mdc_span_slice_void_star\
,   uint8_t: mdc_span_slice_uint8_t\
,   int8_t: mdc_span_slice_int8_t\
,   uint16_t: mdc_span_slice_uint16_t\
,   int16_t: mdc_span_slice_int16_t\
,   uint32_t: mdc_span_slice_uint32_t\
,   int32_t: mdc_span_slice_int32_t\
,   uint64_t: mdc_span_slice_uint64_t\
,   int64_t: mdc_span_slice_int64_t\
,   float: mdc_span_slice_float\
,   double: mdc_span_slice_double\
)
mdc_span(char) mdc_span_slice_char(mdc_span(char) _span, size_t offset, size_t count) {
   return (mdc_span(char)) {
       .data = _span.data + offset,
       .length = count
   };
}

mdc_span(void*) mdc_span_slice_void_star(mdc_span(void*) _span, size_t offset, size_t count) {
   return (mdc_span(void*)) {
       .data = _span.data + offset,
       .length = count
   };
}

mdc_span(uint8_t) mdc_span_slice_uint8_t(mdc_span(uint8_t) _span, size_t offset, size_t count) {
   return (mdc_span(uint8_t)) {
       .data = _span.data + offset,
       .length = count
   };
}

mdc_span(int8_t) mdc_span_slice_int8_t(mdc_span(int8_t) _span, size_t offset, size_t count) {
   return (mdc_span(int8_t)) {
       .data = _span.data + offset,
       .length = count
   };
}

mdc_span(uint16_t) mdc_span_slice_uint16_t(mdc_span(uint16_t) _span, size_t offset, size_t count) {
   return (mdc_span(uint16_t)) {
       .data = _span.data + offset,
       .length = count
   };
}

mdc_span(int16_t) mdc_span_slice_int16_t(mdc_span(int16_t) _span, size_t offset, size_t count) {
   return (mdc_span(int16_t)) {
       .data = _span.data + offset,
       .length = count
   };
}

mdc_span(uint32_t) mdc_span_slice_uint32_t(mdc_span(uint32_t) _span, size_t offset, size_t count) {
   return (mdc_span(uint32_t)) {
       .data = _span.data + offset,
       .length = count
   };
}

mdc_span(int32_t) mdc_span_slice_int32_t(mdc_span(int32_t) _span, size_t offset, size_t count) {
   return (mdc_span(int32_t)) {
       .data = _span.data + offset,
       .length = count
   };
}

mdc_span(uint64_t) mdc_span_slice_uint64_t(mdc_span(uint64_t) _span, size_t offset, size_t count) {
   return (mdc_span(uint64_t)) {
       .data = _span.data + offset,
       .length = count
   };
}

mdc_span(int64_t) mdc_span_slice_int64_t(mdc_span(int64_t) _span, size_t offset, size_t count) {
   return (mdc_span(int64_t)) {
       .data = _span.data + offset,
       .length = count
   };
}

mdc_span(float) mdc_span_slice_float(mdc_span(float) _span, size_t offset, size_t count) {
   return (mdc_span(float)) {
       .data = _span.data + offset,
       .length = count
   };
}

mdc_span(double) mdc_span_slice_double(mdc_span(double) _span, size_t offset, size_t count) {
   return (mdc_span(double)) {
       .data = _span.data + offset,
       .length = count
   };
}

#endif //MDC_SPAN_G

