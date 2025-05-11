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
#define mdc_const_span(T) typeof(\
_Generic( (*((T*)NULL)) \
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

#define mdc_span(T) typeof(\
_Generic( (*((T*)NULL)) \
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

#define mdc_tuple2(T1, T2) typeof(\
_Generic( (*((T2*)NULL)) \
, char: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple2_char_char *)NULL)\
,   void*: (*(struct mdc_tuple2_char_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple2_char_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple2_char_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple2_char_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple2_char_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple2_char_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple2_char_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple2_char_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple2_char_int64_t *)NULL)\
,   float: (*(struct mdc_tuple2_char_float *)NULL)\
,   double: (*(struct mdc_tuple2_char_double *)NULL)\
)\
, void*: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple2_void_star_char *)NULL)\
,   void*: (*(struct mdc_tuple2_void_star_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple2_void_star_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple2_void_star_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple2_void_star_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple2_void_star_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple2_void_star_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple2_void_star_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple2_void_star_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple2_void_star_int64_t *)NULL)\
,   float: (*(struct mdc_tuple2_void_star_float *)NULL)\
,   double: (*(struct mdc_tuple2_void_star_double *)NULL)\
)\
, uint8_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple2_uint8_t_char *)NULL)\
,   void*: (*(struct mdc_tuple2_uint8_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple2_uint8_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple2_uint8_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple2_uint8_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple2_uint8_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple2_uint8_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple2_uint8_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple2_uint8_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple2_uint8_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple2_uint8_t_float *)NULL)\
,   double: (*(struct mdc_tuple2_uint8_t_double *)NULL)\
)\
, int8_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple2_int8_t_char *)NULL)\
,   void*: (*(struct mdc_tuple2_int8_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple2_int8_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple2_int8_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple2_int8_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple2_int8_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple2_int8_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple2_int8_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple2_int8_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple2_int8_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple2_int8_t_float *)NULL)\
,   double: (*(struct mdc_tuple2_int8_t_double *)NULL)\
)\
, uint16_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple2_uint16_t_char *)NULL)\
,   void*: (*(struct mdc_tuple2_uint16_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple2_uint16_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple2_uint16_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple2_uint16_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple2_uint16_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple2_uint16_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple2_uint16_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple2_uint16_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple2_uint16_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple2_uint16_t_float *)NULL)\
,   double: (*(struct mdc_tuple2_uint16_t_double *)NULL)\
)\
, int16_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple2_int16_t_char *)NULL)\
,   void*: (*(struct mdc_tuple2_int16_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple2_int16_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple2_int16_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple2_int16_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple2_int16_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple2_int16_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple2_int16_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple2_int16_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple2_int16_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple2_int16_t_float *)NULL)\
,   double: (*(struct mdc_tuple2_int16_t_double *)NULL)\
)\
, uint32_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple2_uint32_t_char *)NULL)\
,   void*: (*(struct mdc_tuple2_uint32_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple2_uint32_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple2_uint32_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple2_uint32_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple2_uint32_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple2_uint32_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple2_uint32_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple2_uint32_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple2_uint32_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple2_uint32_t_float *)NULL)\
,   double: (*(struct mdc_tuple2_uint32_t_double *)NULL)\
)\
, int32_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple2_int32_t_char *)NULL)\
,   void*: (*(struct mdc_tuple2_int32_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple2_int32_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple2_int32_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple2_int32_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple2_int32_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple2_int32_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple2_int32_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple2_int32_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple2_int32_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple2_int32_t_float *)NULL)\
,   double: (*(struct mdc_tuple2_int32_t_double *)NULL)\
)\
, uint64_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple2_uint64_t_char *)NULL)\
,   void*: (*(struct mdc_tuple2_uint64_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple2_uint64_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple2_uint64_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple2_uint64_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple2_uint64_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple2_uint64_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple2_uint64_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple2_uint64_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple2_uint64_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple2_uint64_t_float *)NULL)\
,   double: (*(struct mdc_tuple2_uint64_t_double *)NULL)\
)\
, int64_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple2_int64_t_char *)NULL)\
,   void*: (*(struct mdc_tuple2_int64_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple2_int64_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple2_int64_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple2_int64_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple2_int64_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple2_int64_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple2_int64_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple2_int64_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple2_int64_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple2_int64_t_float *)NULL)\
,   double: (*(struct mdc_tuple2_int64_t_double *)NULL)\
)\
, float: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple2_float_char *)NULL)\
,   void*: (*(struct mdc_tuple2_float_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple2_float_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple2_float_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple2_float_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple2_float_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple2_float_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple2_float_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple2_float_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple2_float_int64_t *)NULL)\
,   float: (*(struct mdc_tuple2_float_float *)NULL)\
,   double: (*(struct mdc_tuple2_float_double *)NULL)\
)\
, double: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple2_double_char *)NULL)\
,   void*: (*(struct mdc_tuple2_double_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple2_double_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple2_double_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple2_double_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple2_double_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple2_double_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple2_double_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple2_double_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple2_double_int64_t *)NULL)\
,   float: (*(struct mdc_tuple2_double_float *)NULL)\
,   double: (*(struct mdc_tuple2_double_double *)NULL)\
)\
))
struct mdc_tuple2_char_char {
   char t1;
   char t2;
};


struct mdc_tuple2_char_void_star {
   void* t1;
   char t2;
};


struct mdc_tuple2_char_uint8_t {
   uint8_t t1;
   char t2;
};


struct mdc_tuple2_char_int8_t {
   int8_t t1;
   char t2;
};


struct mdc_tuple2_char_uint16_t {
   uint16_t t1;
   char t2;
};


struct mdc_tuple2_char_int16_t {
   int16_t t1;
   char t2;
};


struct mdc_tuple2_char_uint32_t {
   uint32_t t1;
   char t2;
};


struct mdc_tuple2_char_int32_t {
   int32_t t1;
   char t2;
};


struct mdc_tuple2_char_uint64_t {
   uint64_t t1;
   char t2;
};


struct mdc_tuple2_char_int64_t {
   int64_t t1;
   char t2;
};


struct mdc_tuple2_char_float {
   float t1;
   char t2;
};


struct mdc_tuple2_char_double {
   double t1;
   char t2;
};


struct mdc_tuple2_void_star_char {
   char t1;
   void* t2;
};


struct mdc_tuple2_void_star_void_star {
   void* t1;
   void* t2;
};


struct mdc_tuple2_void_star_uint8_t {
   uint8_t t1;
   void* t2;
};


struct mdc_tuple2_void_star_int8_t {
   int8_t t1;
   void* t2;
};


struct mdc_tuple2_void_star_uint16_t {
   uint16_t t1;
   void* t2;
};


struct mdc_tuple2_void_star_int16_t {
   int16_t t1;
   void* t2;
};


struct mdc_tuple2_void_star_uint32_t {
   uint32_t t1;
   void* t2;
};


struct mdc_tuple2_void_star_int32_t {
   int32_t t1;
   void* t2;
};


struct mdc_tuple2_void_star_uint64_t {
   uint64_t t1;
   void* t2;
};


struct mdc_tuple2_void_star_int64_t {
   int64_t t1;
   void* t2;
};


struct mdc_tuple2_void_star_float {
   float t1;
   void* t2;
};


struct mdc_tuple2_void_star_double {
   double t1;
   void* t2;
};


struct mdc_tuple2_uint8_t_char {
   char t1;
   uint8_t t2;
};


struct mdc_tuple2_uint8_t_void_star {
   void* t1;
   uint8_t t2;
};


struct mdc_tuple2_uint8_t_uint8_t {
   uint8_t t1;
   uint8_t t2;
};


struct mdc_tuple2_uint8_t_int8_t {
   int8_t t1;
   uint8_t t2;
};


struct mdc_tuple2_uint8_t_uint16_t {
   uint16_t t1;
   uint8_t t2;
};


struct mdc_tuple2_uint8_t_int16_t {
   int16_t t1;
   uint8_t t2;
};


struct mdc_tuple2_uint8_t_uint32_t {
   uint32_t t1;
   uint8_t t2;
};


struct mdc_tuple2_uint8_t_int32_t {
   int32_t t1;
   uint8_t t2;
};


struct mdc_tuple2_uint8_t_uint64_t {
   uint64_t t1;
   uint8_t t2;
};


struct mdc_tuple2_uint8_t_int64_t {
   int64_t t1;
   uint8_t t2;
};


struct mdc_tuple2_uint8_t_float {
   float t1;
   uint8_t t2;
};


struct mdc_tuple2_uint8_t_double {
   double t1;
   uint8_t t2;
};


struct mdc_tuple2_int8_t_char {
   char t1;
   int8_t t2;
};


struct mdc_tuple2_int8_t_void_star {
   void* t1;
   int8_t t2;
};


struct mdc_tuple2_int8_t_uint8_t {
   uint8_t t1;
   int8_t t2;
};


struct mdc_tuple2_int8_t_int8_t {
   int8_t t1;
   int8_t t2;
};


struct mdc_tuple2_int8_t_uint16_t {
   uint16_t t1;
   int8_t t2;
};


struct mdc_tuple2_int8_t_int16_t {
   int16_t t1;
   int8_t t2;
};


struct mdc_tuple2_int8_t_uint32_t {
   uint32_t t1;
   int8_t t2;
};


struct mdc_tuple2_int8_t_int32_t {
   int32_t t1;
   int8_t t2;
};


struct mdc_tuple2_int8_t_uint64_t {
   uint64_t t1;
   int8_t t2;
};


struct mdc_tuple2_int8_t_int64_t {
   int64_t t1;
   int8_t t2;
};


struct mdc_tuple2_int8_t_float {
   float t1;
   int8_t t2;
};


struct mdc_tuple2_int8_t_double {
   double t1;
   int8_t t2;
};


struct mdc_tuple2_uint16_t_char {
   char t1;
   uint16_t t2;
};


struct mdc_tuple2_uint16_t_void_star {
   void* t1;
   uint16_t t2;
};


struct mdc_tuple2_uint16_t_uint8_t {
   uint8_t t1;
   uint16_t t2;
};


struct mdc_tuple2_uint16_t_int8_t {
   int8_t t1;
   uint16_t t2;
};


struct mdc_tuple2_uint16_t_uint16_t {
   uint16_t t1;
   uint16_t t2;
};


struct mdc_tuple2_uint16_t_int16_t {
   int16_t t1;
   uint16_t t2;
};


struct mdc_tuple2_uint16_t_uint32_t {
   uint32_t t1;
   uint16_t t2;
};


struct mdc_tuple2_uint16_t_int32_t {
   int32_t t1;
   uint16_t t2;
};


struct mdc_tuple2_uint16_t_uint64_t {
   uint64_t t1;
   uint16_t t2;
};


struct mdc_tuple2_uint16_t_int64_t {
   int64_t t1;
   uint16_t t2;
};


struct mdc_tuple2_uint16_t_float {
   float t1;
   uint16_t t2;
};


struct mdc_tuple2_uint16_t_double {
   double t1;
   uint16_t t2;
};


struct mdc_tuple2_int16_t_char {
   char t1;
   int16_t t2;
};


struct mdc_tuple2_int16_t_void_star {
   void* t1;
   int16_t t2;
};


struct mdc_tuple2_int16_t_uint8_t {
   uint8_t t1;
   int16_t t2;
};


struct mdc_tuple2_int16_t_int8_t {
   int8_t t1;
   int16_t t2;
};


struct mdc_tuple2_int16_t_uint16_t {
   uint16_t t1;
   int16_t t2;
};


struct mdc_tuple2_int16_t_int16_t {
   int16_t t1;
   int16_t t2;
};


struct mdc_tuple2_int16_t_uint32_t {
   uint32_t t1;
   int16_t t2;
};


struct mdc_tuple2_int16_t_int32_t {
   int32_t t1;
   int16_t t2;
};


struct mdc_tuple2_int16_t_uint64_t {
   uint64_t t1;
   int16_t t2;
};


struct mdc_tuple2_int16_t_int64_t {
   int64_t t1;
   int16_t t2;
};


struct mdc_tuple2_int16_t_float {
   float t1;
   int16_t t2;
};


struct mdc_tuple2_int16_t_double {
   double t1;
   int16_t t2;
};


struct mdc_tuple2_uint32_t_char {
   char t1;
   uint32_t t2;
};


struct mdc_tuple2_uint32_t_void_star {
   void* t1;
   uint32_t t2;
};


struct mdc_tuple2_uint32_t_uint8_t {
   uint8_t t1;
   uint32_t t2;
};


struct mdc_tuple2_uint32_t_int8_t {
   int8_t t1;
   uint32_t t2;
};


struct mdc_tuple2_uint32_t_uint16_t {
   uint16_t t1;
   uint32_t t2;
};


struct mdc_tuple2_uint32_t_int16_t {
   int16_t t1;
   uint32_t t2;
};


struct mdc_tuple2_uint32_t_uint32_t {
   uint32_t t1;
   uint32_t t2;
};


struct mdc_tuple2_uint32_t_int32_t {
   int32_t t1;
   uint32_t t2;
};


struct mdc_tuple2_uint32_t_uint64_t {
   uint64_t t1;
   uint32_t t2;
};


struct mdc_tuple2_uint32_t_int64_t {
   int64_t t1;
   uint32_t t2;
};


struct mdc_tuple2_uint32_t_float {
   float t1;
   uint32_t t2;
};


struct mdc_tuple2_uint32_t_double {
   double t1;
   uint32_t t2;
};


struct mdc_tuple2_int32_t_char {
   char t1;
   int32_t t2;
};


struct mdc_tuple2_int32_t_void_star {
   void* t1;
   int32_t t2;
};


struct mdc_tuple2_int32_t_uint8_t {
   uint8_t t1;
   int32_t t2;
};


struct mdc_tuple2_int32_t_int8_t {
   int8_t t1;
   int32_t t2;
};


struct mdc_tuple2_int32_t_uint16_t {
   uint16_t t1;
   int32_t t2;
};


struct mdc_tuple2_int32_t_int16_t {
   int16_t t1;
   int32_t t2;
};


struct mdc_tuple2_int32_t_uint32_t {
   uint32_t t1;
   int32_t t2;
};


struct mdc_tuple2_int32_t_int32_t {
   int32_t t1;
   int32_t t2;
};


struct mdc_tuple2_int32_t_uint64_t {
   uint64_t t1;
   int32_t t2;
};


struct mdc_tuple2_int32_t_int64_t {
   int64_t t1;
   int32_t t2;
};


struct mdc_tuple2_int32_t_float {
   float t1;
   int32_t t2;
};


struct mdc_tuple2_int32_t_double {
   double t1;
   int32_t t2;
};


struct mdc_tuple2_uint64_t_char {
   char t1;
   uint64_t t2;
};


struct mdc_tuple2_uint64_t_void_star {
   void* t1;
   uint64_t t2;
};


struct mdc_tuple2_uint64_t_uint8_t {
   uint8_t t1;
   uint64_t t2;
};


struct mdc_tuple2_uint64_t_int8_t {
   int8_t t1;
   uint64_t t2;
};


struct mdc_tuple2_uint64_t_uint16_t {
   uint16_t t1;
   uint64_t t2;
};


struct mdc_tuple2_uint64_t_int16_t {
   int16_t t1;
   uint64_t t2;
};


struct mdc_tuple2_uint64_t_uint32_t {
   uint32_t t1;
   uint64_t t2;
};


struct mdc_tuple2_uint64_t_int32_t {
   int32_t t1;
   uint64_t t2;
};


struct mdc_tuple2_uint64_t_uint64_t {
   uint64_t t1;
   uint64_t t2;
};


struct mdc_tuple2_uint64_t_int64_t {
   int64_t t1;
   uint64_t t2;
};


struct mdc_tuple2_uint64_t_float {
   float t1;
   uint64_t t2;
};


struct mdc_tuple2_uint64_t_double {
   double t1;
   uint64_t t2;
};


struct mdc_tuple2_int64_t_char {
   char t1;
   int64_t t2;
};


struct mdc_tuple2_int64_t_void_star {
   void* t1;
   int64_t t2;
};


struct mdc_tuple2_int64_t_uint8_t {
   uint8_t t1;
   int64_t t2;
};


struct mdc_tuple2_int64_t_int8_t {
   int8_t t1;
   int64_t t2;
};


struct mdc_tuple2_int64_t_uint16_t {
   uint16_t t1;
   int64_t t2;
};


struct mdc_tuple2_int64_t_int16_t {
   int16_t t1;
   int64_t t2;
};


struct mdc_tuple2_int64_t_uint32_t {
   uint32_t t1;
   int64_t t2;
};


struct mdc_tuple2_int64_t_int32_t {
   int32_t t1;
   int64_t t2;
};


struct mdc_tuple2_int64_t_uint64_t {
   uint64_t t1;
   int64_t t2;
};


struct mdc_tuple2_int64_t_int64_t {
   int64_t t1;
   int64_t t2;
};


struct mdc_tuple2_int64_t_float {
   float t1;
   int64_t t2;
};


struct mdc_tuple2_int64_t_double {
   double t1;
   int64_t t2;
};


struct mdc_tuple2_float_char {
   char t1;
   float t2;
};


struct mdc_tuple2_float_void_star {
   void* t1;
   float t2;
};


struct mdc_tuple2_float_uint8_t {
   uint8_t t1;
   float t2;
};


struct mdc_tuple2_float_int8_t {
   int8_t t1;
   float t2;
};


struct mdc_tuple2_float_uint16_t {
   uint16_t t1;
   float t2;
};


struct mdc_tuple2_float_int16_t {
   int16_t t1;
   float t2;
};


struct mdc_tuple2_float_uint32_t {
   uint32_t t1;
   float t2;
};


struct mdc_tuple2_float_int32_t {
   int32_t t1;
   float t2;
};


struct mdc_tuple2_float_uint64_t {
   uint64_t t1;
   float t2;
};


struct mdc_tuple2_float_int64_t {
   int64_t t1;
   float t2;
};


struct mdc_tuple2_float_float {
   float t1;
   float t2;
};


struct mdc_tuple2_float_double {
   double t1;
   float t2;
};


struct mdc_tuple2_double_char {
   char t1;
   double t2;
};


struct mdc_tuple2_double_void_star {
   void* t1;
   double t2;
};


struct mdc_tuple2_double_uint8_t {
   uint8_t t1;
   double t2;
};


struct mdc_tuple2_double_int8_t {
   int8_t t1;
   double t2;
};


struct mdc_tuple2_double_uint16_t {
   uint16_t t1;
   double t2;
};


struct mdc_tuple2_double_int16_t {
   int16_t t1;
   double t2;
};


struct mdc_tuple2_double_uint32_t {
   uint32_t t1;
   double t2;
};


struct mdc_tuple2_double_int32_t {
   int32_t t1;
   double t2;
};


struct mdc_tuple2_double_uint64_t {
   uint64_t t1;
   double t2;
};


struct mdc_tuple2_double_int64_t {
   int64_t t1;
   double t2;
};


struct mdc_tuple2_double_float {
   float t1;
   double t2;
};


struct mdc_tuple2_double_double {
   double t1;
   double t2;
};


#define mdc_tuple3(T1, T2, T3) typeof(\
_Generic( (*((T3*)NULL)) \
, char: _Generic( (*((T2*)NULL)) \
, char: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_char_char_char *)NULL)\
,   void*: (*(struct mdc_tuple3_char_char_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_char_char_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_char_char_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_char_char_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_char_char_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_char_char_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_char_char_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_char_char_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_char_char_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_char_char_float *)NULL)\
,   double: (*(struct mdc_tuple3_char_char_double *)NULL)\
)\
, void*: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_char_void_star_char *)NULL)\
,   void*: (*(struct mdc_tuple3_char_void_star_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_char_void_star_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_char_void_star_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_char_void_star_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_char_void_star_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_char_void_star_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_char_void_star_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_char_void_star_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_char_void_star_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_char_void_star_float *)NULL)\
,   double: (*(struct mdc_tuple3_char_void_star_double *)NULL)\
)\
, uint8_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_char_uint8_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_char_uint8_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_char_uint8_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_char_uint8_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_char_uint8_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_char_uint8_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_char_uint8_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_char_uint8_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_char_uint8_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_char_uint8_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_char_uint8_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_char_uint8_t_double *)NULL)\
)\
, int8_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_char_int8_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_char_int8_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_char_int8_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_char_int8_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_char_int8_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_char_int8_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_char_int8_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_char_int8_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_char_int8_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_char_int8_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_char_int8_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_char_int8_t_double *)NULL)\
)\
, uint16_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_char_uint16_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_char_uint16_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_char_uint16_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_char_uint16_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_char_uint16_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_char_uint16_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_char_uint16_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_char_uint16_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_char_uint16_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_char_uint16_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_char_uint16_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_char_uint16_t_double *)NULL)\
)\
, int16_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_char_int16_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_char_int16_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_char_int16_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_char_int16_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_char_int16_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_char_int16_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_char_int16_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_char_int16_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_char_int16_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_char_int16_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_char_int16_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_char_int16_t_double *)NULL)\
)\
, uint32_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_char_uint32_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_char_uint32_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_char_uint32_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_char_uint32_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_char_uint32_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_char_uint32_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_char_uint32_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_char_uint32_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_char_uint32_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_char_uint32_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_char_uint32_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_char_uint32_t_double *)NULL)\
)\
, int32_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_char_int32_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_char_int32_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_char_int32_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_char_int32_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_char_int32_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_char_int32_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_char_int32_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_char_int32_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_char_int32_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_char_int32_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_char_int32_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_char_int32_t_double *)NULL)\
)\
, uint64_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_char_uint64_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_char_uint64_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_char_uint64_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_char_uint64_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_char_uint64_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_char_uint64_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_char_uint64_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_char_uint64_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_char_uint64_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_char_uint64_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_char_uint64_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_char_uint64_t_double *)NULL)\
)\
, int64_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_char_int64_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_char_int64_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_char_int64_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_char_int64_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_char_int64_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_char_int64_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_char_int64_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_char_int64_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_char_int64_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_char_int64_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_char_int64_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_char_int64_t_double *)NULL)\
)\
, float: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_char_float_char *)NULL)\
,   void*: (*(struct mdc_tuple3_char_float_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_char_float_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_char_float_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_char_float_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_char_float_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_char_float_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_char_float_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_char_float_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_char_float_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_char_float_float *)NULL)\
,   double: (*(struct mdc_tuple3_char_float_double *)NULL)\
)\
, double: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_char_double_char *)NULL)\
,   void*: (*(struct mdc_tuple3_char_double_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_char_double_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_char_double_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_char_double_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_char_double_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_char_double_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_char_double_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_char_double_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_char_double_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_char_double_float *)NULL)\
,   double: (*(struct mdc_tuple3_char_double_double *)NULL)\
)\
)\
, void*: _Generic( (*((T2*)NULL)) \
, char: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_void_star_char_char *)NULL)\
,   void*: (*(struct mdc_tuple3_void_star_char_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_void_star_char_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_void_star_char_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_void_star_char_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_void_star_char_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_void_star_char_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_void_star_char_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_void_star_char_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_void_star_char_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_void_star_char_float *)NULL)\
,   double: (*(struct mdc_tuple3_void_star_char_double *)NULL)\
)\
, void*: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_void_star_void_star_char *)NULL)\
,   void*: (*(struct mdc_tuple3_void_star_void_star_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_void_star_void_star_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_void_star_void_star_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_void_star_void_star_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_void_star_void_star_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_void_star_void_star_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_void_star_void_star_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_void_star_void_star_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_void_star_void_star_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_void_star_void_star_float *)NULL)\
,   double: (*(struct mdc_tuple3_void_star_void_star_double *)NULL)\
)\
, uint8_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_void_star_uint8_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_void_star_uint8_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_void_star_uint8_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_void_star_uint8_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_void_star_uint8_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_void_star_uint8_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_void_star_uint8_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_void_star_uint8_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_void_star_uint8_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_void_star_uint8_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_void_star_uint8_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_void_star_uint8_t_double *)NULL)\
)\
, int8_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_void_star_int8_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_void_star_int8_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_void_star_int8_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_void_star_int8_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_void_star_int8_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_void_star_int8_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_void_star_int8_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_void_star_int8_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_void_star_int8_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_void_star_int8_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_void_star_int8_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_void_star_int8_t_double *)NULL)\
)\
, uint16_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_void_star_uint16_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_void_star_uint16_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_void_star_uint16_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_void_star_uint16_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_void_star_uint16_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_void_star_uint16_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_void_star_uint16_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_void_star_uint16_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_void_star_uint16_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_void_star_uint16_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_void_star_uint16_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_void_star_uint16_t_double *)NULL)\
)\
, int16_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_void_star_int16_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_void_star_int16_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_void_star_int16_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_void_star_int16_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_void_star_int16_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_void_star_int16_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_void_star_int16_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_void_star_int16_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_void_star_int16_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_void_star_int16_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_void_star_int16_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_void_star_int16_t_double *)NULL)\
)\
, uint32_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_void_star_uint32_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_void_star_uint32_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_void_star_uint32_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_void_star_uint32_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_void_star_uint32_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_void_star_uint32_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_void_star_uint32_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_void_star_uint32_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_void_star_uint32_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_void_star_uint32_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_void_star_uint32_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_void_star_uint32_t_double *)NULL)\
)\
, int32_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_void_star_int32_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_void_star_int32_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_void_star_int32_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_void_star_int32_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_void_star_int32_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_void_star_int32_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_void_star_int32_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_void_star_int32_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_void_star_int32_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_void_star_int32_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_void_star_int32_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_void_star_int32_t_double *)NULL)\
)\
, uint64_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_void_star_uint64_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_void_star_uint64_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_void_star_uint64_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_void_star_uint64_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_void_star_uint64_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_void_star_uint64_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_void_star_uint64_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_void_star_uint64_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_void_star_uint64_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_void_star_uint64_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_void_star_uint64_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_void_star_uint64_t_double *)NULL)\
)\
, int64_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_void_star_int64_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_void_star_int64_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_void_star_int64_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_void_star_int64_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_void_star_int64_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_void_star_int64_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_void_star_int64_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_void_star_int64_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_void_star_int64_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_void_star_int64_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_void_star_int64_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_void_star_int64_t_double *)NULL)\
)\
, float: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_void_star_float_char *)NULL)\
,   void*: (*(struct mdc_tuple3_void_star_float_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_void_star_float_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_void_star_float_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_void_star_float_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_void_star_float_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_void_star_float_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_void_star_float_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_void_star_float_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_void_star_float_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_void_star_float_float *)NULL)\
,   double: (*(struct mdc_tuple3_void_star_float_double *)NULL)\
)\
, double: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_void_star_double_char *)NULL)\
,   void*: (*(struct mdc_tuple3_void_star_double_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_void_star_double_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_void_star_double_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_void_star_double_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_void_star_double_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_void_star_double_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_void_star_double_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_void_star_double_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_void_star_double_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_void_star_double_float *)NULL)\
,   double: (*(struct mdc_tuple3_void_star_double_double *)NULL)\
)\
)\
, uint8_t: _Generic( (*((T2*)NULL)) \
, char: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_uint8_t_char_char *)NULL)\
,   void*: (*(struct mdc_tuple3_uint8_t_char_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_uint8_t_char_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_uint8_t_char_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_uint8_t_char_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_uint8_t_char_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_uint8_t_char_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_uint8_t_char_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_uint8_t_char_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_uint8_t_char_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_uint8_t_char_float *)NULL)\
,   double: (*(struct mdc_tuple3_uint8_t_char_double *)NULL)\
)\
, void*: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_uint8_t_void_star_char *)NULL)\
,   void*: (*(struct mdc_tuple3_uint8_t_void_star_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_uint8_t_void_star_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_uint8_t_void_star_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_uint8_t_void_star_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_uint8_t_void_star_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_uint8_t_void_star_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_uint8_t_void_star_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_uint8_t_void_star_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_uint8_t_void_star_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_uint8_t_void_star_float *)NULL)\
,   double: (*(struct mdc_tuple3_uint8_t_void_star_double *)NULL)\
)\
, uint8_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_uint8_t_uint8_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_uint8_t_uint8_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_uint8_t_uint8_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_uint8_t_uint8_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_uint8_t_uint8_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_uint8_t_uint8_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_uint8_t_uint8_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_uint8_t_uint8_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_uint8_t_uint8_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_uint8_t_uint8_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_uint8_t_uint8_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_uint8_t_uint8_t_double *)NULL)\
)\
, int8_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_uint8_t_int8_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_uint8_t_int8_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_uint8_t_int8_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_uint8_t_int8_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_uint8_t_int8_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_uint8_t_int8_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_uint8_t_int8_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_uint8_t_int8_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_uint8_t_int8_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_uint8_t_int8_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_uint8_t_int8_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_uint8_t_int8_t_double *)NULL)\
)\
, uint16_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_uint8_t_uint16_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_uint8_t_uint16_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_uint8_t_uint16_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_uint8_t_uint16_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_uint8_t_uint16_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_uint8_t_uint16_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_uint8_t_uint16_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_uint8_t_uint16_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_uint8_t_uint16_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_uint8_t_uint16_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_uint8_t_uint16_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_uint8_t_uint16_t_double *)NULL)\
)\
, int16_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_uint8_t_int16_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_uint8_t_int16_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_uint8_t_int16_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_uint8_t_int16_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_uint8_t_int16_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_uint8_t_int16_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_uint8_t_int16_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_uint8_t_int16_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_uint8_t_int16_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_uint8_t_int16_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_uint8_t_int16_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_uint8_t_int16_t_double *)NULL)\
)\
, uint32_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_uint8_t_uint32_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_uint8_t_uint32_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_uint8_t_uint32_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_uint8_t_uint32_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_uint8_t_uint32_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_uint8_t_uint32_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_uint8_t_uint32_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_uint8_t_uint32_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_uint8_t_uint32_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_uint8_t_uint32_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_uint8_t_uint32_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_uint8_t_uint32_t_double *)NULL)\
)\
, int32_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_uint8_t_int32_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_uint8_t_int32_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_uint8_t_int32_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_uint8_t_int32_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_uint8_t_int32_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_uint8_t_int32_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_uint8_t_int32_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_uint8_t_int32_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_uint8_t_int32_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_uint8_t_int32_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_uint8_t_int32_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_uint8_t_int32_t_double *)NULL)\
)\
, uint64_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_uint8_t_uint64_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_uint8_t_uint64_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_uint8_t_uint64_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_uint8_t_uint64_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_uint8_t_uint64_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_uint8_t_uint64_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_uint8_t_uint64_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_uint8_t_uint64_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_uint8_t_uint64_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_uint8_t_uint64_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_uint8_t_uint64_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_uint8_t_uint64_t_double *)NULL)\
)\
, int64_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_uint8_t_int64_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_uint8_t_int64_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_uint8_t_int64_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_uint8_t_int64_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_uint8_t_int64_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_uint8_t_int64_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_uint8_t_int64_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_uint8_t_int64_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_uint8_t_int64_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_uint8_t_int64_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_uint8_t_int64_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_uint8_t_int64_t_double *)NULL)\
)\
, float: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_uint8_t_float_char *)NULL)\
,   void*: (*(struct mdc_tuple3_uint8_t_float_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_uint8_t_float_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_uint8_t_float_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_uint8_t_float_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_uint8_t_float_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_uint8_t_float_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_uint8_t_float_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_uint8_t_float_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_uint8_t_float_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_uint8_t_float_float *)NULL)\
,   double: (*(struct mdc_tuple3_uint8_t_float_double *)NULL)\
)\
, double: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_uint8_t_double_char *)NULL)\
,   void*: (*(struct mdc_tuple3_uint8_t_double_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_uint8_t_double_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_uint8_t_double_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_uint8_t_double_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_uint8_t_double_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_uint8_t_double_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_uint8_t_double_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_uint8_t_double_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_uint8_t_double_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_uint8_t_double_float *)NULL)\
,   double: (*(struct mdc_tuple3_uint8_t_double_double *)NULL)\
)\
)\
, int8_t: _Generic( (*((T2*)NULL)) \
, char: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_int8_t_char_char *)NULL)\
,   void*: (*(struct mdc_tuple3_int8_t_char_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_int8_t_char_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_int8_t_char_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_int8_t_char_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_int8_t_char_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_int8_t_char_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_int8_t_char_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_int8_t_char_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_int8_t_char_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_int8_t_char_float *)NULL)\
,   double: (*(struct mdc_tuple3_int8_t_char_double *)NULL)\
)\
, void*: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_int8_t_void_star_char *)NULL)\
,   void*: (*(struct mdc_tuple3_int8_t_void_star_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_int8_t_void_star_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_int8_t_void_star_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_int8_t_void_star_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_int8_t_void_star_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_int8_t_void_star_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_int8_t_void_star_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_int8_t_void_star_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_int8_t_void_star_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_int8_t_void_star_float *)NULL)\
,   double: (*(struct mdc_tuple3_int8_t_void_star_double *)NULL)\
)\
, uint8_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_int8_t_uint8_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_int8_t_uint8_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_int8_t_uint8_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_int8_t_uint8_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_int8_t_uint8_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_int8_t_uint8_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_int8_t_uint8_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_int8_t_uint8_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_int8_t_uint8_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_int8_t_uint8_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_int8_t_uint8_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_int8_t_uint8_t_double *)NULL)\
)\
, int8_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_int8_t_int8_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_int8_t_int8_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_int8_t_int8_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_int8_t_int8_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_int8_t_int8_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_int8_t_int8_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_int8_t_int8_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_int8_t_int8_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_int8_t_int8_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_int8_t_int8_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_int8_t_int8_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_int8_t_int8_t_double *)NULL)\
)\
, uint16_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_int8_t_uint16_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_int8_t_uint16_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_int8_t_uint16_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_int8_t_uint16_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_int8_t_uint16_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_int8_t_uint16_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_int8_t_uint16_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_int8_t_uint16_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_int8_t_uint16_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_int8_t_uint16_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_int8_t_uint16_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_int8_t_uint16_t_double *)NULL)\
)\
, int16_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_int8_t_int16_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_int8_t_int16_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_int8_t_int16_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_int8_t_int16_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_int8_t_int16_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_int8_t_int16_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_int8_t_int16_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_int8_t_int16_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_int8_t_int16_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_int8_t_int16_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_int8_t_int16_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_int8_t_int16_t_double *)NULL)\
)\
, uint32_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_int8_t_uint32_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_int8_t_uint32_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_int8_t_uint32_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_int8_t_uint32_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_int8_t_uint32_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_int8_t_uint32_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_int8_t_uint32_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_int8_t_uint32_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_int8_t_uint32_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_int8_t_uint32_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_int8_t_uint32_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_int8_t_uint32_t_double *)NULL)\
)\
, int32_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_int8_t_int32_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_int8_t_int32_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_int8_t_int32_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_int8_t_int32_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_int8_t_int32_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_int8_t_int32_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_int8_t_int32_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_int8_t_int32_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_int8_t_int32_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_int8_t_int32_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_int8_t_int32_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_int8_t_int32_t_double *)NULL)\
)\
, uint64_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_int8_t_uint64_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_int8_t_uint64_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_int8_t_uint64_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_int8_t_uint64_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_int8_t_uint64_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_int8_t_uint64_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_int8_t_uint64_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_int8_t_uint64_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_int8_t_uint64_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_int8_t_uint64_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_int8_t_uint64_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_int8_t_uint64_t_double *)NULL)\
)\
, int64_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_int8_t_int64_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_int8_t_int64_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_int8_t_int64_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_int8_t_int64_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_int8_t_int64_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_int8_t_int64_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_int8_t_int64_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_int8_t_int64_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_int8_t_int64_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_int8_t_int64_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_int8_t_int64_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_int8_t_int64_t_double *)NULL)\
)\
, float: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_int8_t_float_char *)NULL)\
,   void*: (*(struct mdc_tuple3_int8_t_float_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_int8_t_float_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_int8_t_float_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_int8_t_float_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_int8_t_float_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_int8_t_float_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_int8_t_float_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_int8_t_float_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_int8_t_float_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_int8_t_float_float *)NULL)\
,   double: (*(struct mdc_tuple3_int8_t_float_double *)NULL)\
)\
, double: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_int8_t_double_char *)NULL)\
,   void*: (*(struct mdc_tuple3_int8_t_double_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_int8_t_double_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_int8_t_double_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_int8_t_double_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_int8_t_double_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_int8_t_double_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_int8_t_double_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_int8_t_double_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_int8_t_double_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_int8_t_double_float *)NULL)\
,   double: (*(struct mdc_tuple3_int8_t_double_double *)NULL)\
)\
)\
, uint16_t: _Generic( (*((T2*)NULL)) \
, char: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_uint16_t_char_char *)NULL)\
,   void*: (*(struct mdc_tuple3_uint16_t_char_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_uint16_t_char_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_uint16_t_char_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_uint16_t_char_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_uint16_t_char_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_uint16_t_char_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_uint16_t_char_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_uint16_t_char_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_uint16_t_char_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_uint16_t_char_float *)NULL)\
,   double: (*(struct mdc_tuple3_uint16_t_char_double *)NULL)\
)\
, void*: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_uint16_t_void_star_char *)NULL)\
,   void*: (*(struct mdc_tuple3_uint16_t_void_star_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_uint16_t_void_star_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_uint16_t_void_star_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_uint16_t_void_star_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_uint16_t_void_star_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_uint16_t_void_star_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_uint16_t_void_star_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_uint16_t_void_star_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_uint16_t_void_star_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_uint16_t_void_star_float *)NULL)\
,   double: (*(struct mdc_tuple3_uint16_t_void_star_double *)NULL)\
)\
, uint8_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_uint16_t_uint8_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_uint16_t_uint8_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_uint16_t_uint8_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_uint16_t_uint8_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_uint16_t_uint8_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_uint16_t_uint8_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_uint16_t_uint8_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_uint16_t_uint8_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_uint16_t_uint8_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_uint16_t_uint8_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_uint16_t_uint8_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_uint16_t_uint8_t_double *)NULL)\
)\
, int8_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_uint16_t_int8_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_uint16_t_int8_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_uint16_t_int8_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_uint16_t_int8_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_uint16_t_int8_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_uint16_t_int8_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_uint16_t_int8_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_uint16_t_int8_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_uint16_t_int8_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_uint16_t_int8_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_uint16_t_int8_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_uint16_t_int8_t_double *)NULL)\
)\
, uint16_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_uint16_t_uint16_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_uint16_t_uint16_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_uint16_t_uint16_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_uint16_t_uint16_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_uint16_t_uint16_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_uint16_t_uint16_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_uint16_t_uint16_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_uint16_t_uint16_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_uint16_t_uint16_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_uint16_t_uint16_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_uint16_t_uint16_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_uint16_t_uint16_t_double *)NULL)\
)\
, int16_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_uint16_t_int16_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_uint16_t_int16_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_uint16_t_int16_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_uint16_t_int16_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_uint16_t_int16_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_uint16_t_int16_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_uint16_t_int16_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_uint16_t_int16_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_uint16_t_int16_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_uint16_t_int16_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_uint16_t_int16_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_uint16_t_int16_t_double *)NULL)\
)\
, uint32_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_uint16_t_uint32_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_uint16_t_uint32_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_uint16_t_uint32_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_uint16_t_uint32_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_uint16_t_uint32_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_uint16_t_uint32_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_uint16_t_uint32_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_uint16_t_uint32_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_uint16_t_uint32_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_uint16_t_uint32_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_uint16_t_uint32_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_uint16_t_uint32_t_double *)NULL)\
)\
, int32_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_uint16_t_int32_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_uint16_t_int32_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_uint16_t_int32_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_uint16_t_int32_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_uint16_t_int32_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_uint16_t_int32_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_uint16_t_int32_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_uint16_t_int32_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_uint16_t_int32_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_uint16_t_int32_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_uint16_t_int32_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_uint16_t_int32_t_double *)NULL)\
)\
, uint64_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_uint16_t_uint64_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_uint16_t_uint64_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_uint16_t_uint64_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_uint16_t_uint64_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_uint16_t_uint64_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_uint16_t_uint64_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_uint16_t_uint64_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_uint16_t_uint64_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_uint16_t_uint64_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_uint16_t_uint64_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_uint16_t_uint64_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_uint16_t_uint64_t_double *)NULL)\
)\
, int64_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_uint16_t_int64_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_uint16_t_int64_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_uint16_t_int64_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_uint16_t_int64_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_uint16_t_int64_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_uint16_t_int64_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_uint16_t_int64_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_uint16_t_int64_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_uint16_t_int64_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_uint16_t_int64_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_uint16_t_int64_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_uint16_t_int64_t_double *)NULL)\
)\
, float: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_uint16_t_float_char *)NULL)\
,   void*: (*(struct mdc_tuple3_uint16_t_float_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_uint16_t_float_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_uint16_t_float_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_uint16_t_float_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_uint16_t_float_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_uint16_t_float_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_uint16_t_float_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_uint16_t_float_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_uint16_t_float_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_uint16_t_float_float *)NULL)\
,   double: (*(struct mdc_tuple3_uint16_t_float_double *)NULL)\
)\
, double: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_uint16_t_double_char *)NULL)\
,   void*: (*(struct mdc_tuple3_uint16_t_double_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_uint16_t_double_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_uint16_t_double_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_uint16_t_double_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_uint16_t_double_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_uint16_t_double_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_uint16_t_double_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_uint16_t_double_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_uint16_t_double_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_uint16_t_double_float *)NULL)\
,   double: (*(struct mdc_tuple3_uint16_t_double_double *)NULL)\
)\
)\
, int16_t: _Generic( (*((T2*)NULL)) \
, char: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_int16_t_char_char *)NULL)\
,   void*: (*(struct mdc_tuple3_int16_t_char_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_int16_t_char_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_int16_t_char_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_int16_t_char_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_int16_t_char_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_int16_t_char_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_int16_t_char_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_int16_t_char_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_int16_t_char_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_int16_t_char_float *)NULL)\
,   double: (*(struct mdc_tuple3_int16_t_char_double *)NULL)\
)\
, void*: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_int16_t_void_star_char *)NULL)\
,   void*: (*(struct mdc_tuple3_int16_t_void_star_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_int16_t_void_star_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_int16_t_void_star_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_int16_t_void_star_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_int16_t_void_star_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_int16_t_void_star_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_int16_t_void_star_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_int16_t_void_star_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_int16_t_void_star_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_int16_t_void_star_float *)NULL)\
,   double: (*(struct mdc_tuple3_int16_t_void_star_double *)NULL)\
)\
, uint8_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_int16_t_uint8_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_int16_t_uint8_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_int16_t_uint8_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_int16_t_uint8_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_int16_t_uint8_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_int16_t_uint8_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_int16_t_uint8_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_int16_t_uint8_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_int16_t_uint8_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_int16_t_uint8_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_int16_t_uint8_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_int16_t_uint8_t_double *)NULL)\
)\
, int8_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_int16_t_int8_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_int16_t_int8_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_int16_t_int8_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_int16_t_int8_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_int16_t_int8_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_int16_t_int8_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_int16_t_int8_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_int16_t_int8_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_int16_t_int8_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_int16_t_int8_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_int16_t_int8_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_int16_t_int8_t_double *)NULL)\
)\
, uint16_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_int16_t_uint16_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_int16_t_uint16_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_int16_t_uint16_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_int16_t_uint16_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_int16_t_uint16_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_int16_t_uint16_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_int16_t_uint16_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_int16_t_uint16_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_int16_t_uint16_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_int16_t_uint16_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_int16_t_uint16_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_int16_t_uint16_t_double *)NULL)\
)\
, int16_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_int16_t_int16_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_int16_t_int16_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_int16_t_int16_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_int16_t_int16_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_int16_t_int16_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_int16_t_int16_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_int16_t_int16_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_int16_t_int16_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_int16_t_int16_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_int16_t_int16_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_int16_t_int16_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_int16_t_int16_t_double *)NULL)\
)\
, uint32_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_int16_t_uint32_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_int16_t_uint32_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_int16_t_uint32_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_int16_t_uint32_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_int16_t_uint32_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_int16_t_uint32_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_int16_t_uint32_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_int16_t_uint32_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_int16_t_uint32_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_int16_t_uint32_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_int16_t_uint32_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_int16_t_uint32_t_double *)NULL)\
)\
, int32_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_int16_t_int32_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_int16_t_int32_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_int16_t_int32_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_int16_t_int32_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_int16_t_int32_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_int16_t_int32_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_int16_t_int32_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_int16_t_int32_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_int16_t_int32_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_int16_t_int32_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_int16_t_int32_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_int16_t_int32_t_double *)NULL)\
)\
, uint64_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_int16_t_uint64_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_int16_t_uint64_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_int16_t_uint64_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_int16_t_uint64_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_int16_t_uint64_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_int16_t_uint64_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_int16_t_uint64_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_int16_t_uint64_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_int16_t_uint64_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_int16_t_uint64_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_int16_t_uint64_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_int16_t_uint64_t_double *)NULL)\
)\
, int64_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_int16_t_int64_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_int16_t_int64_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_int16_t_int64_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_int16_t_int64_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_int16_t_int64_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_int16_t_int64_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_int16_t_int64_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_int16_t_int64_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_int16_t_int64_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_int16_t_int64_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_int16_t_int64_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_int16_t_int64_t_double *)NULL)\
)\
, float: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_int16_t_float_char *)NULL)\
,   void*: (*(struct mdc_tuple3_int16_t_float_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_int16_t_float_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_int16_t_float_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_int16_t_float_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_int16_t_float_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_int16_t_float_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_int16_t_float_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_int16_t_float_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_int16_t_float_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_int16_t_float_float *)NULL)\
,   double: (*(struct mdc_tuple3_int16_t_float_double *)NULL)\
)\
, double: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_int16_t_double_char *)NULL)\
,   void*: (*(struct mdc_tuple3_int16_t_double_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_int16_t_double_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_int16_t_double_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_int16_t_double_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_int16_t_double_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_int16_t_double_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_int16_t_double_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_int16_t_double_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_int16_t_double_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_int16_t_double_float *)NULL)\
,   double: (*(struct mdc_tuple3_int16_t_double_double *)NULL)\
)\
)\
, uint32_t: _Generic( (*((T2*)NULL)) \
, char: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_uint32_t_char_char *)NULL)\
,   void*: (*(struct mdc_tuple3_uint32_t_char_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_uint32_t_char_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_uint32_t_char_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_uint32_t_char_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_uint32_t_char_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_uint32_t_char_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_uint32_t_char_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_uint32_t_char_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_uint32_t_char_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_uint32_t_char_float *)NULL)\
,   double: (*(struct mdc_tuple3_uint32_t_char_double *)NULL)\
)\
, void*: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_uint32_t_void_star_char *)NULL)\
,   void*: (*(struct mdc_tuple3_uint32_t_void_star_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_uint32_t_void_star_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_uint32_t_void_star_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_uint32_t_void_star_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_uint32_t_void_star_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_uint32_t_void_star_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_uint32_t_void_star_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_uint32_t_void_star_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_uint32_t_void_star_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_uint32_t_void_star_float *)NULL)\
,   double: (*(struct mdc_tuple3_uint32_t_void_star_double *)NULL)\
)\
, uint8_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_uint32_t_uint8_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_uint32_t_uint8_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_uint32_t_uint8_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_uint32_t_uint8_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_uint32_t_uint8_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_uint32_t_uint8_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_uint32_t_uint8_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_uint32_t_uint8_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_uint32_t_uint8_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_uint32_t_uint8_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_uint32_t_uint8_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_uint32_t_uint8_t_double *)NULL)\
)\
, int8_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_uint32_t_int8_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_uint32_t_int8_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_uint32_t_int8_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_uint32_t_int8_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_uint32_t_int8_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_uint32_t_int8_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_uint32_t_int8_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_uint32_t_int8_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_uint32_t_int8_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_uint32_t_int8_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_uint32_t_int8_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_uint32_t_int8_t_double *)NULL)\
)\
, uint16_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_uint32_t_uint16_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_uint32_t_uint16_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_uint32_t_uint16_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_uint32_t_uint16_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_uint32_t_uint16_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_uint32_t_uint16_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_uint32_t_uint16_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_uint32_t_uint16_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_uint32_t_uint16_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_uint32_t_uint16_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_uint32_t_uint16_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_uint32_t_uint16_t_double *)NULL)\
)\
, int16_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_uint32_t_int16_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_uint32_t_int16_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_uint32_t_int16_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_uint32_t_int16_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_uint32_t_int16_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_uint32_t_int16_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_uint32_t_int16_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_uint32_t_int16_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_uint32_t_int16_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_uint32_t_int16_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_uint32_t_int16_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_uint32_t_int16_t_double *)NULL)\
)\
, uint32_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_uint32_t_uint32_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_uint32_t_uint32_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_uint32_t_uint32_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_uint32_t_uint32_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_uint32_t_uint32_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_uint32_t_uint32_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_uint32_t_uint32_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_uint32_t_uint32_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_uint32_t_uint32_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_uint32_t_uint32_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_uint32_t_uint32_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_uint32_t_uint32_t_double *)NULL)\
)\
, int32_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_uint32_t_int32_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_uint32_t_int32_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_uint32_t_int32_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_uint32_t_int32_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_uint32_t_int32_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_uint32_t_int32_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_uint32_t_int32_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_uint32_t_int32_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_uint32_t_int32_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_uint32_t_int32_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_uint32_t_int32_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_uint32_t_int32_t_double *)NULL)\
)\
, uint64_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_uint32_t_uint64_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_uint32_t_uint64_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_uint32_t_uint64_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_uint32_t_uint64_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_uint32_t_uint64_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_uint32_t_uint64_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_uint32_t_uint64_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_uint32_t_uint64_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_uint32_t_uint64_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_uint32_t_uint64_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_uint32_t_uint64_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_uint32_t_uint64_t_double *)NULL)\
)\
, int64_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_uint32_t_int64_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_uint32_t_int64_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_uint32_t_int64_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_uint32_t_int64_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_uint32_t_int64_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_uint32_t_int64_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_uint32_t_int64_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_uint32_t_int64_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_uint32_t_int64_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_uint32_t_int64_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_uint32_t_int64_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_uint32_t_int64_t_double *)NULL)\
)\
, float: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_uint32_t_float_char *)NULL)\
,   void*: (*(struct mdc_tuple3_uint32_t_float_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_uint32_t_float_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_uint32_t_float_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_uint32_t_float_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_uint32_t_float_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_uint32_t_float_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_uint32_t_float_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_uint32_t_float_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_uint32_t_float_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_uint32_t_float_float *)NULL)\
,   double: (*(struct mdc_tuple3_uint32_t_float_double *)NULL)\
)\
, double: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_uint32_t_double_char *)NULL)\
,   void*: (*(struct mdc_tuple3_uint32_t_double_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_uint32_t_double_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_uint32_t_double_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_uint32_t_double_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_uint32_t_double_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_uint32_t_double_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_uint32_t_double_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_uint32_t_double_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_uint32_t_double_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_uint32_t_double_float *)NULL)\
,   double: (*(struct mdc_tuple3_uint32_t_double_double *)NULL)\
)\
)\
, int32_t: _Generic( (*((T2*)NULL)) \
, char: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_int32_t_char_char *)NULL)\
,   void*: (*(struct mdc_tuple3_int32_t_char_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_int32_t_char_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_int32_t_char_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_int32_t_char_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_int32_t_char_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_int32_t_char_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_int32_t_char_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_int32_t_char_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_int32_t_char_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_int32_t_char_float *)NULL)\
,   double: (*(struct mdc_tuple3_int32_t_char_double *)NULL)\
)\
, void*: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_int32_t_void_star_char *)NULL)\
,   void*: (*(struct mdc_tuple3_int32_t_void_star_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_int32_t_void_star_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_int32_t_void_star_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_int32_t_void_star_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_int32_t_void_star_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_int32_t_void_star_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_int32_t_void_star_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_int32_t_void_star_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_int32_t_void_star_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_int32_t_void_star_float *)NULL)\
,   double: (*(struct mdc_tuple3_int32_t_void_star_double *)NULL)\
)\
, uint8_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_int32_t_uint8_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_int32_t_uint8_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_int32_t_uint8_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_int32_t_uint8_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_int32_t_uint8_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_int32_t_uint8_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_int32_t_uint8_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_int32_t_uint8_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_int32_t_uint8_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_int32_t_uint8_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_int32_t_uint8_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_int32_t_uint8_t_double *)NULL)\
)\
, int8_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_int32_t_int8_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_int32_t_int8_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_int32_t_int8_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_int32_t_int8_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_int32_t_int8_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_int32_t_int8_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_int32_t_int8_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_int32_t_int8_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_int32_t_int8_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_int32_t_int8_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_int32_t_int8_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_int32_t_int8_t_double *)NULL)\
)\
, uint16_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_int32_t_uint16_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_int32_t_uint16_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_int32_t_uint16_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_int32_t_uint16_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_int32_t_uint16_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_int32_t_uint16_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_int32_t_uint16_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_int32_t_uint16_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_int32_t_uint16_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_int32_t_uint16_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_int32_t_uint16_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_int32_t_uint16_t_double *)NULL)\
)\
, int16_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_int32_t_int16_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_int32_t_int16_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_int32_t_int16_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_int32_t_int16_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_int32_t_int16_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_int32_t_int16_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_int32_t_int16_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_int32_t_int16_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_int32_t_int16_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_int32_t_int16_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_int32_t_int16_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_int32_t_int16_t_double *)NULL)\
)\
, uint32_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_int32_t_uint32_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_int32_t_uint32_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_int32_t_uint32_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_int32_t_uint32_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_int32_t_uint32_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_int32_t_uint32_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_int32_t_uint32_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_int32_t_uint32_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_int32_t_uint32_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_int32_t_uint32_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_int32_t_uint32_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_int32_t_uint32_t_double *)NULL)\
)\
, int32_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_int32_t_int32_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_int32_t_int32_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_int32_t_int32_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_int32_t_int32_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_int32_t_int32_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_int32_t_int32_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_int32_t_int32_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_int32_t_int32_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_int32_t_int32_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_int32_t_int32_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_int32_t_int32_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_int32_t_int32_t_double *)NULL)\
)\
, uint64_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_int32_t_uint64_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_int32_t_uint64_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_int32_t_uint64_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_int32_t_uint64_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_int32_t_uint64_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_int32_t_uint64_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_int32_t_uint64_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_int32_t_uint64_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_int32_t_uint64_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_int32_t_uint64_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_int32_t_uint64_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_int32_t_uint64_t_double *)NULL)\
)\
, int64_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_int32_t_int64_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_int32_t_int64_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_int32_t_int64_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_int32_t_int64_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_int32_t_int64_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_int32_t_int64_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_int32_t_int64_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_int32_t_int64_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_int32_t_int64_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_int32_t_int64_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_int32_t_int64_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_int32_t_int64_t_double *)NULL)\
)\
, float: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_int32_t_float_char *)NULL)\
,   void*: (*(struct mdc_tuple3_int32_t_float_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_int32_t_float_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_int32_t_float_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_int32_t_float_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_int32_t_float_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_int32_t_float_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_int32_t_float_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_int32_t_float_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_int32_t_float_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_int32_t_float_float *)NULL)\
,   double: (*(struct mdc_tuple3_int32_t_float_double *)NULL)\
)\
, double: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_int32_t_double_char *)NULL)\
,   void*: (*(struct mdc_tuple3_int32_t_double_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_int32_t_double_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_int32_t_double_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_int32_t_double_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_int32_t_double_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_int32_t_double_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_int32_t_double_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_int32_t_double_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_int32_t_double_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_int32_t_double_float *)NULL)\
,   double: (*(struct mdc_tuple3_int32_t_double_double *)NULL)\
)\
)\
, uint64_t: _Generic( (*((T2*)NULL)) \
, char: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_uint64_t_char_char *)NULL)\
,   void*: (*(struct mdc_tuple3_uint64_t_char_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_uint64_t_char_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_uint64_t_char_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_uint64_t_char_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_uint64_t_char_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_uint64_t_char_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_uint64_t_char_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_uint64_t_char_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_uint64_t_char_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_uint64_t_char_float *)NULL)\
,   double: (*(struct mdc_tuple3_uint64_t_char_double *)NULL)\
)\
, void*: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_uint64_t_void_star_char *)NULL)\
,   void*: (*(struct mdc_tuple3_uint64_t_void_star_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_uint64_t_void_star_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_uint64_t_void_star_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_uint64_t_void_star_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_uint64_t_void_star_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_uint64_t_void_star_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_uint64_t_void_star_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_uint64_t_void_star_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_uint64_t_void_star_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_uint64_t_void_star_float *)NULL)\
,   double: (*(struct mdc_tuple3_uint64_t_void_star_double *)NULL)\
)\
, uint8_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_uint64_t_uint8_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_uint64_t_uint8_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_uint64_t_uint8_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_uint64_t_uint8_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_uint64_t_uint8_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_uint64_t_uint8_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_uint64_t_uint8_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_uint64_t_uint8_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_uint64_t_uint8_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_uint64_t_uint8_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_uint64_t_uint8_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_uint64_t_uint8_t_double *)NULL)\
)\
, int8_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_uint64_t_int8_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_uint64_t_int8_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_uint64_t_int8_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_uint64_t_int8_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_uint64_t_int8_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_uint64_t_int8_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_uint64_t_int8_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_uint64_t_int8_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_uint64_t_int8_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_uint64_t_int8_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_uint64_t_int8_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_uint64_t_int8_t_double *)NULL)\
)\
, uint16_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_uint64_t_uint16_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_uint64_t_uint16_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_uint64_t_uint16_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_uint64_t_uint16_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_uint64_t_uint16_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_uint64_t_uint16_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_uint64_t_uint16_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_uint64_t_uint16_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_uint64_t_uint16_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_uint64_t_uint16_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_uint64_t_uint16_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_uint64_t_uint16_t_double *)NULL)\
)\
, int16_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_uint64_t_int16_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_uint64_t_int16_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_uint64_t_int16_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_uint64_t_int16_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_uint64_t_int16_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_uint64_t_int16_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_uint64_t_int16_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_uint64_t_int16_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_uint64_t_int16_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_uint64_t_int16_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_uint64_t_int16_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_uint64_t_int16_t_double *)NULL)\
)\
, uint32_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_uint64_t_uint32_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_uint64_t_uint32_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_uint64_t_uint32_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_uint64_t_uint32_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_uint64_t_uint32_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_uint64_t_uint32_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_uint64_t_uint32_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_uint64_t_uint32_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_uint64_t_uint32_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_uint64_t_uint32_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_uint64_t_uint32_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_uint64_t_uint32_t_double *)NULL)\
)\
, int32_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_uint64_t_int32_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_uint64_t_int32_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_uint64_t_int32_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_uint64_t_int32_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_uint64_t_int32_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_uint64_t_int32_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_uint64_t_int32_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_uint64_t_int32_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_uint64_t_int32_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_uint64_t_int32_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_uint64_t_int32_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_uint64_t_int32_t_double *)NULL)\
)\
, uint64_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_uint64_t_uint64_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_uint64_t_uint64_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_uint64_t_uint64_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_uint64_t_uint64_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_uint64_t_uint64_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_uint64_t_uint64_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_uint64_t_uint64_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_uint64_t_uint64_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_uint64_t_uint64_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_uint64_t_uint64_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_uint64_t_uint64_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_uint64_t_uint64_t_double *)NULL)\
)\
, int64_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_uint64_t_int64_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_uint64_t_int64_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_uint64_t_int64_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_uint64_t_int64_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_uint64_t_int64_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_uint64_t_int64_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_uint64_t_int64_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_uint64_t_int64_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_uint64_t_int64_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_uint64_t_int64_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_uint64_t_int64_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_uint64_t_int64_t_double *)NULL)\
)\
, float: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_uint64_t_float_char *)NULL)\
,   void*: (*(struct mdc_tuple3_uint64_t_float_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_uint64_t_float_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_uint64_t_float_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_uint64_t_float_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_uint64_t_float_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_uint64_t_float_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_uint64_t_float_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_uint64_t_float_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_uint64_t_float_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_uint64_t_float_float *)NULL)\
,   double: (*(struct mdc_tuple3_uint64_t_float_double *)NULL)\
)\
, double: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_uint64_t_double_char *)NULL)\
,   void*: (*(struct mdc_tuple3_uint64_t_double_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_uint64_t_double_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_uint64_t_double_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_uint64_t_double_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_uint64_t_double_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_uint64_t_double_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_uint64_t_double_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_uint64_t_double_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_uint64_t_double_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_uint64_t_double_float *)NULL)\
,   double: (*(struct mdc_tuple3_uint64_t_double_double *)NULL)\
)\
)\
, int64_t: _Generic( (*((T2*)NULL)) \
, char: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_int64_t_char_char *)NULL)\
,   void*: (*(struct mdc_tuple3_int64_t_char_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_int64_t_char_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_int64_t_char_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_int64_t_char_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_int64_t_char_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_int64_t_char_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_int64_t_char_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_int64_t_char_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_int64_t_char_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_int64_t_char_float *)NULL)\
,   double: (*(struct mdc_tuple3_int64_t_char_double *)NULL)\
)\
, void*: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_int64_t_void_star_char *)NULL)\
,   void*: (*(struct mdc_tuple3_int64_t_void_star_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_int64_t_void_star_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_int64_t_void_star_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_int64_t_void_star_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_int64_t_void_star_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_int64_t_void_star_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_int64_t_void_star_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_int64_t_void_star_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_int64_t_void_star_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_int64_t_void_star_float *)NULL)\
,   double: (*(struct mdc_tuple3_int64_t_void_star_double *)NULL)\
)\
, uint8_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_int64_t_uint8_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_int64_t_uint8_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_int64_t_uint8_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_int64_t_uint8_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_int64_t_uint8_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_int64_t_uint8_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_int64_t_uint8_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_int64_t_uint8_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_int64_t_uint8_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_int64_t_uint8_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_int64_t_uint8_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_int64_t_uint8_t_double *)NULL)\
)\
, int8_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_int64_t_int8_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_int64_t_int8_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_int64_t_int8_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_int64_t_int8_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_int64_t_int8_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_int64_t_int8_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_int64_t_int8_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_int64_t_int8_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_int64_t_int8_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_int64_t_int8_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_int64_t_int8_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_int64_t_int8_t_double *)NULL)\
)\
, uint16_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_int64_t_uint16_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_int64_t_uint16_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_int64_t_uint16_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_int64_t_uint16_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_int64_t_uint16_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_int64_t_uint16_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_int64_t_uint16_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_int64_t_uint16_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_int64_t_uint16_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_int64_t_uint16_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_int64_t_uint16_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_int64_t_uint16_t_double *)NULL)\
)\
, int16_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_int64_t_int16_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_int64_t_int16_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_int64_t_int16_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_int64_t_int16_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_int64_t_int16_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_int64_t_int16_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_int64_t_int16_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_int64_t_int16_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_int64_t_int16_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_int64_t_int16_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_int64_t_int16_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_int64_t_int16_t_double *)NULL)\
)\
, uint32_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_int64_t_uint32_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_int64_t_uint32_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_int64_t_uint32_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_int64_t_uint32_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_int64_t_uint32_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_int64_t_uint32_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_int64_t_uint32_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_int64_t_uint32_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_int64_t_uint32_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_int64_t_uint32_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_int64_t_uint32_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_int64_t_uint32_t_double *)NULL)\
)\
, int32_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_int64_t_int32_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_int64_t_int32_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_int64_t_int32_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_int64_t_int32_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_int64_t_int32_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_int64_t_int32_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_int64_t_int32_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_int64_t_int32_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_int64_t_int32_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_int64_t_int32_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_int64_t_int32_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_int64_t_int32_t_double *)NULL)\
)\
, uint64_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_int64_t_uint64_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_int64_t_uint64_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_int64_t_uint64_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_int64_t_uint64_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_int64_t_uint64_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_int64_t_uint64_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_int64_t_uint64_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_int64_t_uint64_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_int64_t_uint64_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_int64_t_uint64_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_int64_t_uint64_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_int64_t_uint64_t_double *)NULL)\
)\
, int64_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_int64_t_int64_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_int64_t_int64_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_int64_t_int64_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_int64_t_int64_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_int64_t_int64_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_int64_t_int64_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_int64_t_int64_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_int64_t_int64_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_int64_t_int64_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_int64_t_int64_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_int64_t_int64_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_int64_t_int64_t_double *)NULL)\
)\
, float: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_int64_t_float_char *)NULL)\
,   void*: (*(struct mdc_tuple3_int64_t_float_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_int64_t_float_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_int64_t_float_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_int64_t_float_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_int64_t_float_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_int64_t_float_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_int64_t_float_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_int64_t_float_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_int64_t_float_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_int64_t_float_float *)NULL)\
,   double: (*(struct mdc_tuple3_int64_t_float_double *)NULL)\
)\
, double: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_int64_t_double_char *)NULL)\
,   void*: (*(struct mdc_tuple3_int64_t_double_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_int64_t_double_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_int64_t_double_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_int64_t_double_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_int64_t_double_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_int64_t_double_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_int64_t_double_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_int64_t_double_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_int64_t_double_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_int64_t_double_float *)NULL)\
,   double: (*(struct mdc_tuple3_int64_t_double_double *)NULL)\
)\
)\
, float: _Generic( (*((T2*)NULL)) \
, char: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_float_char_char *)NULL)\
,   void*: (*(struct mdc_tuple3_float_char_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_float_char_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_float_char_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_float_char_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_float_char_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_float_char_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_float_char_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_float_char_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_float_char_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_float_char_float *)NULL)\
,   double: (*(struct mdc_tuple3_float_char_double *)NULL)\
)\
, void*: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_float_void_star_char *)NULL)\
,   void*: (*(struct mdc_tuple3_float_void_star_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_float_void_star_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_float_void_star_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_float_void_star_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_float_void_star_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_float_void_star_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_float_void_star_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_float_void_star_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_float_void_star_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_float_void_star_float *)NULL)\
,   double: (*(struct mdc_tuple3_float_void_star_double *)NULL)\
)\
, uint8_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_float_uint8_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_float_uint8_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_float_uint8_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_float_uint8_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_float_uint8_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_float_uint8_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_float_uint8_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_float_uint8_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_float_uint8_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_float_uint8_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_float_uint8_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_float_uint8_t_double *)NULL)\
)\
, int8_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_float_int8_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_float_int8_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_float_int8_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_float_int8_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_float_int8_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_float_int8_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_float_int8_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_float_int8_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_float_int8_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_float_int8_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_float_int8_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_float_int8_t_double *)NULL)\
)\
, uint16_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_float_uint16_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_float_uint16_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_float_uint16_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_float_uint16_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_float_uint16_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_float_uint16_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_float_uint16_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_float_uint16_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_float_uint16_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_float_uint16_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_float_uint16_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_float_uint16_t_double *)NULL)\
)\
, int16_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_float_int16_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_float_int16_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_float_int16_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_float_int16_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_float_int16_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_float_int16_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_float_int16_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_float_int16_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_float_int16_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_float_int16_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_float_int16_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_float_int16_t_double *)NULL)\
)\
, uint32_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_float_uint32_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_float_uint32_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_float_uint32_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_float_uint32_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_float_uint32_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_float_uint32_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_float_uint32_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_float_uint32_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_float_uint32_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_float_uint32_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_float_uint32_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_float_uint32_t_double *)NULL)\
)\
, int32_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_float_int32_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_float_int32_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_float_int32_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_float_int32_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_float_int32_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_float_int32_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_float_int32_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_float_int32_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_float_int32_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_float_int32_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_float_int32_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_float_int32_t_double *)NULL)\
)\
, uint64_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_float_uint64_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_float_uint64_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_float_uint64_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_float_uint64_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_float_uint64_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_float_uint64_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_float_uint64_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_float_uint64_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_float_uint64_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_float_uint64_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_float_uint64_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_float_uint64_t_double *)NULL)\
)\
, int64_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_float_int64_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_float_int64_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_float_int64_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_float_int64_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_float_int64_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_float_int64_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_float_int64_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_float_int64_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_float_int64_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_float_int64_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_float_int64_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_float_int64_t_double *)NULL)\
)\
, float: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_float_float_char *)NULL)\
,   void*: (*(struct mdc_tuple3_float_float_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_float_float_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_float_float_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_float_float_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_float_float_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_float_float_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_float_float_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_float_float_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_float_float_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_float_float_float *)NULL)\
,   double: (*(struct mdc_tuple3_float_float_double *)NULL)\
)\
, double: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_float_double_char *)NULL)\
,   void*: (*(struct mdc_tuple3_float_double_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_float_double_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_float_double_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_float_double_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_float_double_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_float_double_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_float_double_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_float_double_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_float_double_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_float_double_float *)NULL)\
,   double: (*(struct mdc_tuple3_float_double_double *)NULL)\
)\
)\
, double: _Generic( (*((T2*)NULL)) \
, char: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_double_char_char *)NULL)\
,   void*: (*(struct mdc_tuple3_double_char_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_double_char_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_double_char_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_double_char_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_double_char_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_double_char_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_double_char_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_double_char_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_double_char_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_double_char_float *)NULL)\
,   double: (*(struct mdc_tuple3_double_char_double *)NULL)\
)\
, void*: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_double_void_star_char *)NULL)\
,   void*: (*(struct mdc_tuple3_double_void_star_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_double_void_star_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_double_void_star_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_double_void_star_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_double_void_star_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_double_void_star_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_double_void_star_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_double_void_star_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_double_void_star_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_double_void_star_float *)NULL)\
,   double: (*(struct mdc_tuple3_double_void_star_double *)NULL)\
)\
, uint8_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_double_uint8_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_double_uint8_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_double_uint8_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_double_uint8_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_double_uint8_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_double_uint8_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_double_uint8_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_double_uint8_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_double_uint8_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_double_uint8_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_double_uint8_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_double_uint8_t_double *)NULL)\
)\
, int8_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_double_int8_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_double_int8_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_double_int8_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_double_int8_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_double_int8_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_double_int8_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_double_int8_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_double_int8_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_double_int8_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_double_int8_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_double_int8_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_double_int8_t_double *)NULL)\
)\
, uint16_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_double_uint16_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_double_uint16_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_double_uint16_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_double_uint16_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_double_uint16_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_double_uint16_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_double_uint16_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_double_uint16_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_double_uint16_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_double_uint16_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_double_uint16_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_double_uint16_t_double *)NULL)\
)\
, int16_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_double_int16_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_double_int16_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_double_int16_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_double_int16_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_double_int16_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_double_int16_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_double_int16_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_double_int16_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_double_int16_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_double_int16_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_double_int16_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_double_int16_t_double *)NULL)\
)\
, uint32_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_double_uint32_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_double_uint32_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_double_uint32_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_double_uint32_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_double_uint32_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_double_uint32_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_double_uint32_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_double_uint32_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_double_uint32_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_double_uint32_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_double_uint32_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_double_uint32_t_double *)NULL)\
)\
, int32_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_double_int32_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_double_int32_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_double_int32_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_double_int32_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_double_int32_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_double_int32_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_double_int32_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_double_int32_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_double_int32_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_double_int32_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_double_int32_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_double_int32_t_double *)NULL)\
)\
, uint64_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_double_uint64_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_double_uint64_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_double_uint64_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_double_uint64_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_double_uint64_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_double_uint64_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_double_uint64_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_double_uint64_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_double_uint64_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_double_uint64_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_double_uint64_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_double_uint64_t_double *)NULL)\
)\
, int64_t: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_double_int64_t_char *)NULL)\
,   void*: (*(struct mdc_tuple3_double_int64_t_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_double_int64_t_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_double_int64_t_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_double_int64_t_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_double_int64_t_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_double_int64_t_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_double_int64_t_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_double_int64_t_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_double_int64_t_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_double_int64_t_float *)NULL)\
,   double: (*(struct mdc_tuple3_double_int64_t_double *)NULL)\
)\
, float: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_double_float_char *)NULL)\
,   void*: (*(struct mdc_tuple3_double_float_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_double_float_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_double_float_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_double_float_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_double_float_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_double_float_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_double_float_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_double_float_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_double_float_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_double_float_float *)NULL)\
,   double: (*(struct mdc_tuple3_double_float_double *)NULL)\
)\
, double: _Generic( (*((T1*)NULL)) \
,   char: (*(struct mdc_tuple3_double_double_char *)NULL)\
,   void*: (*(struct mdc_tuple3_double_double_void_star *)NULL)\
,   uint8_t: (*(struct mdc_tuple3_double_double_uint8_t *)NULL)\
,   int8_t: (*(struct mdc_tuple3_double_double_int8_t *)NULL)\
,   uint16_t: (*(struct mdc_tuple3_double_double_uint16_t *)NULL)\
,   int16_t: (*(struct mdc_tuple3_double_double_int16_t *)NULL)\
,   uint32_t: (*(struct mdc_tuple3_double_double_uint32_t *)NULL)\
,   int32_t: (*(struct mdc_tuple3_double_double_int32_t *)NULL)\
,   uint64_t: (*(struct mdc_tuple3_double_double_uint64_t *)NULL)\
,   int64_t: (*(struct mdc_tuple3_double_double_int64_t *)NULL)\
,   float: (*(struct mdc_tuple3_double_double_float *)NULL)\
,   double: (*(struct mdc_tuple3_double_double_double *)NULL)\
)\
)\
))
struct mdc_tuple3_char_char_char {
   char t1;
   char t2;
   char t3;
};



struct mdc_tuple3_char_char_void_star {
   void* t1;
   char t2;
   char t3;
};



struct mdc_tuple3_char_char_uint8_t {
   uint8_t t1;
   char t2;
   char t3;
};



struct mdc_tuple3_char_char_int8_t {
   int8_t t1;
   char t2;
   char t3;
};



struct mdc_tuple3_char_char_uint16_t {
   uint16_t t1;
   char t2;
   char t3;
};



struct mdc_tuple3_char_char_int16_t {
   int16_t t1;
   char t2;
   char t3;
};



struct mdc_tuple3_char_char_uint32_t {
   uint32_t t1;
   char t2;
   char t3;
};



struct mdc_tuple3_char_char_int32_t {
   int32_t t1;
   char t2;
   char t3;
};



struct mdc_tuple3_char_char_uint64_t {
   uint64_t t1;
   char t2;
   char t3;
};



struct mdc_tuple3_char_char_int64_t {
   int64_t t1;
   char t2;
   char t3;
};



struct mdc_tuple3_char_char_float {
   float t1;
   char t2;
   char t3;
};



struct mdc_tuple3_char_char_double {
   double t1;
   char t2;
   char t3;
};



struct mdc_tuple3_char_void_star_char {
   char t1;
   void* t2;
   char t3;
};



struct mdc_tuple3_char_void_star_void_star {
   void* t1;
   void* t2;
   char t3;
};



struct mdc_tuple3_char_void_star_uint8_t {
   uint8_t t1;
   void* t2;
   char t3;
};



struct mdc_tuple3_char_void_star_int8_t {
   int8_t t1;
   void* t2;
   char t3;
};



struct mdc_tuple3_char_void_star_uint16_t {
   uint16_t t1;
   void* t2;
   char t3;
};



struct mdc_tuple3_char_void_star_int16_t {
   int16_t t1;
   void* t2;
   char t3;
};



struct mdc_tuple3_char_void_star_uint32_t {
   uint32_t t1;
   void* t2;
   char t3;
};



struct mdc_tuple3_char_void_star_int32_t {
   int32_t t1;
   void* t2;
   char t3;
};



struct mdc_tuple3_char_void_star_uint64_t {
   uint64_t t1;
   void* t2;
   char t3;
};



struct mdc_tuple3_char_void_star_int64_t {
   int64_t t1;
   void* t2;
   char t3;
};



struct mdc_tuple3_char_void_star_float {
   float t1;
   void* t2;
   char t3;
};



struct mdc_tuple3_char_void_star_double {
   double t1;
   void* t2;
   char t3;
};



struct mdc_tuple3_char_uint8_t_char {
   char t1;
   uint8_t t2;
   char t3;
};



struct mdc_tuple3_char_uint8_t_void_star {
   void* t1;
   uint8_t t2;
   char t3;
};



struct mdc_tuple3_char_uint8_t_uint8_t {
   uint8_t t1;
   uint8_t t2;
   char t3;
};



struct mdc_tuple3_char_uint8_t_int8_t {
   int8_t t1;
   uint8_t t2;
   char t3;
};



struct mdc_tuple3_char_uint8_t_uint16_t {
   uint16_t t1;
   uint8_t t2;
   char t3;
};



struct mdc_tuple3_char_uint8_t_int16_t {
   int16_t t1;
   uint8_t t2;
   char t3;
};



struct mdc_tuple3_char_uint8_t_uint32_t {
   uint32_t t1;
   uint8_t t2;
   char t3;
};



struct mdc_tuple3_char_uint8_t_int32_t {
   int32_t t1;
   uint8_t t2;
   char t3;
};



struct mdc_tuple3_char_uint8_t_uint64_t {
   uint64_t t1;
   uint8_t t2;
   char t3;
};



struct mdc_tuple3_char_uint8_t_int64_t {
   int64_t t1;
   uint8_t t2;
   char t3;
};



struct mdc_tuple3_char_uint8_t_float {
   float t1;
   uint8_t t2;
   char t3;
};



struct mdc_tuple3_char_uint8_t_double {
   double t1;
   uint8_t t2;
   char t3;
};



struct mdc_tuple3_char_int8_t_char {
   char t1;
   int8_t t2;
   char t3;
};



struct mdc_tuple3_char_int8_t_void_star {
   void* t1;
   int8_t t2;
   char t3;
};



struct mdc_tuple3_char_int8_t_uint8_t {
   uint8_t t1;
   int8_t t2;
   char t3;
};



struct mdc_tuple3_char_int8_t_int8_t {
   int8_t t1;
   int8_t t2;
   char t3;
};



struct mdc_tuple3_char_int8_t_uint16_t {
   uint16_t t1;
   int8_t t2;
   char t3;
};



struct mdc_tuple3_char_int8_t_int16_t {
   int16_t t1;
   int8_t t2;
   char t3;
};



struct mdc_tuple3_char_int8_t_uint32_t {
   uint32_t t1;
   int8_t t2;
   char t3;
};



struct mdc_tuple3_char_int8_t_int32_t {
   int32_t t1;
   int8_t t2;
   char t3;
};



struct mdc_tuple3_char_int8_t_uint64_t {
   uint64_t t1;
   int8_t t2;
   char t3;
};



struct mdc_tuple3_char_int8_t_int64_t {
   int64_t t1;
   int8_t t2;
   char t3;
};



struct mdc_tuple3_char_int8_t_float {
   float t1;
   int8_t t2;
   char t3;
};



struct mdc_tuple3_char_int8_t_double {
   double t1;
   int8_t t2;
   char t3;
};



struct mdc_tuple3_char_uint16_t_char {
   char t1;
   uint16_t t2;
   char t3;
};



struct mdc_tuple3_char_uint16_t_void_star {
   void* t1;
   uint16_t t2;
   char t3;
};



struct mdc_tuple3_char_uint16_t_uint8_t {
   uint8_t t1;
   uint16_t t2;
   char t3;
};



struct mdc_tuple3_char_uint16_t_int8_t {
   int8_t t1;
   uint16_t t2;
   char t3;
};



struct mdc_tuple3_char_uint16_t_uint16_t {
   uint16_t t1;
   uint16_t t2;
   char t3;
};



struct mdc_tuple3_char_uint16_t_int16_t {
   int16_t t1;
   uint16_t t2;
   char t3;
};



struct mdc_tuple3_char_uint16_t_uint32_t {
   uint32_t t1;
   uint16_t t2;
   char t3;
};



struct mdc_tuple3_char_uint16_t_int32_t {
   int32_t t1;
   uint16_t t2;
   char t3;
};



struct mdc_tuple3_char_uint16_t_uint64_t {
   uint64_t t1;
   uint16_t t2;
   char t3;
};



struct mdc_tuple3_char_uint16_t_int64_t {
   int64_t t1;
   uint16_t t2;
   char t3;
};



struct mdc_tuple3_char_uint16_t_float {
   float t1;
   uint16_t t2;
   char t3;
};



struct mdc_tuple3_char_uint16_t_double {
   double t1;
   uint16_t t2;
   char t3;
};



struct mdc_tuple3_char_int16_t_char {
   char t1;
   int16_t t2;
   char t3;
};



struct mdc_tuple3_char_int16_t_void_star {
   void* t1;
   int16_t t2;
   char t3;
};



struct mdc_tuple3_char_int16_t_uint8_t {
   uint8_t t1;
   int16_t t2;
   char t3;
};



struct mdc_tuple3_char_int16_t_int8_t {
   int8_t t1;
   int16_t t2;
   char t3;
};



struct mdc_tuple3_char_int16_t_uint16_t {
   uint16_t t1;
   int16_t t2;
   char t3;
};



struct mdc_tuple3_char_int16_t_int16_t {
   int16_t t1;
   int16_t t2;
   char t3;
};



struct mdc_tuple3_char_int16_t_uint32_t {
   uint32_t t1;
   int16_t t2;
   char t3;
};



struct mdc_tuple3_char_int16_t_int32_t {
   int32_t t1;
   int16_t t2;
   char t3;
};



struct mdc_tuple3_char_int16_t_uint64_t {
   uint64_t t1;
   int16_t t2;
   char t3;
};



struct mdc_tuple3_char_int16_t_int64_t {
   int64_t t1;
   int16_t t2;
   char t3;
};



struct mdc_tuple3_char_int16_t_float {
   float t1;
   int16_t t2;
   char t3;
};



struct mdc_tuple3_char_int16_t_double {
   double t1;
   int16_t t2;
   char t3;
};



struct mdc_tuple3_char_uint32_t_char {
   char t1;
   uint32_t t2;
   char t3;
};



struct mdc_tuple3_char_uint32_t_void_star {
   void* t1;
   uint32_t t2;
   char t3;
};



struct mdc_tuple3_char_uint32_t_uint8_t {
   uint8_t t1;
   uint32_t t2;
   char t3;
};



struct mdc_tuple3_char_uint32_t_int8_t {
   int8_t t1;
   uint32_t t2;
   char t3;
};



struct mdc_tuple3_char_uint32_t_uint16_t {
   uint16_t t1;
   uint32_t t2;
   char t3;
};



struct mdc_tuple3_char_uint32_t_int16_t {
   int16_t t1;
   uint32_t t2;
   char t3;
};



struct mdc_tuple3_char_uint32_t_uint32_t {
   uint32_t t1;
   uint32_t t2;
   char t3;
};



struct mdc_tuple3_char_uint32_t_int32_t {
   int32_t t1;
   uint32_t t2;
   char t3;
};



struct mdc_tuple3_char_uint32_t_uint64_t {
   uint64_t t1;
   uint32_t t2;
   char t3;
};



struct mdc_tuple3_char_uint32_t_int64_t {
   int64_t t1;
   uint32_t t2;
   char t3;
};



struct mdc_tuple3_char_uint32_t_float {
   float t1;
   uint32_t t2;
   char t3;
};



struct mdc_tuple3_char_uint32_t_double {
   double t1;
   uint32_t t2;
   char t3;
};



struct mdc_tuple3_char_int32_t_char {
   char t1;
   int32_t t2;
   char t3;
};



struct mdc_tuple3_char_int32_t_void_star {
   void* t1;
   int32_t t2;
   char t3;
};



struct mdc_tuple3_char_int32_t_uint8_t {
   uint8_t t1;
   int32_t t2;
   char t3;
};



struct mdc_tuple3_char_int32_t_int8_t {
   int8_t t1;
   int32_t t2;
   char t3;
};



struct mdc_tuple3_char_int32_t_uint16_t {
   uint16_t t1;
   int32_t t2;
   char t3;
};



struct mdc_tuple3_char_int32_t_int16_t {
   int16_t t1;
   int32_t t2;
   char t3;
};



struct mdc_tuple3_char_int32_t_uint32_t {
   uint32_t t1;
   int32_t t2;
   char t3;
};



struct mdc_tuple3_char_int32_t_int32_t {
   int32_t t1;
   int32_t t2;
   char t3;
};



struct mdc_tuple3_char_int32_t_uint64_t {
   uint64_t t1;
   int32_t t2;
   char t3;
};



struct mdc_tuple3_char_int32_t_int64_t {
   int64_t t1;
   int32_t t2;
   char t3;
};



struct mdc_tuple3_char_int32_t_float {
   float t1;
   int32_t t2;
   char t3;
};



struct mdc_tuple3_char_int32_t_double {
   double t1;
   int32_t t2;
   char t3;
};



struct mdc_tuple3_char_uint64_t_char {
   char t1;
   uint64_t t2;
   char t3;
};



struct mdc_tuple3_char_uint64_t_void_star {
   void* t1;
   uint64_t t2;
   char t3;
};



struct mdc_tuple3_char_uint64_t_uint8_t {
   uint8_t t1;
   uint64_t t2;
   char t3;
};



struct mdc_tuple3_char_uint64_t_int8_t {
   int8_t t1;
   uint64_t t2;
   char t3;
};



struct mdc_tuple3_char_uint64_t_uint16_t {
   uint16_t t1;
   uint64_t t2;
   char t3;
};



struct mdc_tuple3_char_uint64_t_int16_t {
   int16_t t1;
   uint64_t t2;
   char t3;
};



struct mdc_tuple3_char_uint64_t_uint32_t {
   uint32_t t1;
   uint64_t t2;
   char t3;
};



struct mdc_tuple3_char_uint64_t_int32_t {
   int32_t t1;
   uint64_t t2;
   char t3;
};



struct mdc_tuple3_char_uint64_t_uint64_t {
   uint64_t t1;
   uint64_t t2;
   char t3;
};



struct mdc_tuple3_char_uint64_t_int64_t {
   int64_t t1;
   uint64_t t2;
   char t3;
};



struct mdc_tuple3_char_uint64_t_float {
   float t1;
   uint64_t t2;
   char t3;
};



struct mdc_tuple3_char_uint64_t_double {
   double t1;
   uint64_t t2;
   char t3;
};



struct mdc_tuple3_char_int64_t_char {
   char t1;
   int64_t t2;
   char t3;
};



struct mdc_tuple3_char_int64_t_void_star {
   void* t1;
   int64_t t2;
   char t3;
};



struct mdc_tuple3_char_int64_t_uint8_t {
   uint8_t t1;
   int64_t t2;
   char t3;
};



struct mdc_tuple3_char_int64_t_int8_t {
   int8_t t1;
   int64_t t2;
   char t3;
};



struct mdc_tuple3_char_int64_t_uint16_t {
   uint16_t t1;
   int64_t t2;
   char t3;
};



struct mdc_tuple3_char_int64_t_int16_t {
   int16_t t1;
   int64_t t2;
   char t3;
};



struct mdc_tuple3_char_int64_t_uint32_t {
   uint32_t t1;
   int64_t t2;
   char t3;
};



struct mdc_tuple3_char_int64_t_int32_t {
   int32_t t1;
   int64_t t2;
   char t3;
};



struct mdc_tuple3_char_int64_t_uint64_t {
   uint64_t t1;
   int64_t t2;
   char t3;
};



struct mdc_tuple3_char_int64_t_int64_t {
   int64_t t1;
   int64_t t2;
   char t3;
};



struct mdc_tuple3_char_int64_t_float {
   float t1;
   int64_t t2;
   char t3;
};



struct mdc_tuple3_char_int64_t_double {
   double t1;
   int64_t t2;
   char t3;
};



struct mdc_tuple3_char_float_char {
   char t1;
   float t2;
   char t3;
};



struct mdc_tuple3_char_float_void_star {
   void* t1;
   float t2;
   char t3;
};



struct mdc_tuple3_char_float_uint8_t {
   uint8_t t1;
   float t2;
   char t3;
};



struct mdc_tuple3_char_float_int8_t {
   int8_t t1;
   float t2;
   char t3;
};



struct mdc_tuple3_char_float_uint16_t {
   uint16_t t1;
   float t2;
   char t3;
};



struct mdc_tuple3_char_float_int16_t {
   int16_t t1;
   float t2;
   char t3;
};



struct mdc_tuple3_char_float_uint32_t {
   uint32_t t1;
   float t2;
   char t3;
};



struct mdc_tuple3_char_float_int32_t {
   int32_t t1;
   float t2;
   char t3;
};



struct mdc_tuple3_char_float_uint64_t {
   uint64_t t1;
   float t2;
   char t3;
};



struct mdc_tuple3_char_float_int64_t {
   int64_t t1;
   float t2;
   char t3;
};



struct mdc_tuple3_char_float_float {
   float t1;
   float t2;
   char t3;
};



struct mdc_tuple3_char_float_double {
   double t1;
   float t2;
   char t3;
};



struct mdc_tuple3_char_double_char {
   char t1;
   double t2;
   char t3;
};



struct mdc_tuple3_char_double_void_star {
   void* t1;
   double t2;
   char t3;
};



struct mdc_tuple3_char_double_uint8_t {
   uint8_t t1;
   double t2;
   char t3;
};



struct mdc_tuple3_char_double_int8_t {
   int8_t t1;
   double t2;
   char t3;
};



struct mdc_tuple3_char_double_uint16_t {
   uint16_t t1;
   double t2;
   char t3;
};



struct mdc_tuple3_char_double_int16_t {
   int16_t t1;
   double t2;
   char t3;
};



struct mdc_tuple3_char_double_uint32_t {
   uint32_t t1;
   double t2;
   char t3;
};



struct mdc_tuple3_char_double_int32_t {
   int32_t t1;
   double t2;
   char t3;
};



struct mdc_tuple3_char_double_uint64_t {
   uint64_t t1;
   double t2;
   char t3;
};



struct mdc_tuple3_char_double_int64_t {
   int64_t t1;
   double t2;
   char t3;
};



struct mdc_tuple3_char_double_float {
   float t1;
   double t2;
   char t3;
};



struct mdc_tuple3_char_double_double {
   double t1;
   double t2;
   char t3;
};



struct mdc_tuple3_void_star_char_char {
   char t1;
   char t2;
   void* t3;
};



struct mdc_tuple3_void_star_char_void_star {
   void* t1;
   char t2;
   void* t3;
};



struct mdc_tuple3_void_star_char_uint8_t {
   uint8_t t1;
   char t2;
   void* t3;
};



struct mdc_tuple3_void_star_char_int8_t {
   int8_t t1;
   char t2;
   void* t3;
};



struct mdc_tuple3_void_star_char_uint16_t {
   uint16_t t1;
   char t2;
   void* t3;
};



struct mdc_tuple3_void_star_char_int16_t {
   int16_t t1;
   char t2;
   void* t3;
};



struct mdc_tuple3_void_star_char_uint32_t {
   uint32_t t1;
   char t2;
   void* t3;
};



struct mdc_tuple3_void_star_char_int32_t {
   int32_t t1;
   char t2;
   void* t3;
};



struct mdc_tuple3_void_star_char_uint64_t {
   uint64_t t1;
   char t2;
   void* t3;
};



struct mdc_tuple3_void_star_char_int64_t {
   int64_t t1;
   char t2;
   void* t3;
};



struct mdc_tuple3_void_star_char_float {
   float t1;
   char t2;
   void* t3;
};



struct mdc_tuple3_void_star_char_double {
   double t1;
   char t2;
   void* t3;
};



struct mdc_tuple3_void_star_void_star_char {
   char t1;
   void* t2;
   void* t3;
};



struct mdc_tuple3_void_star_void_star_void_star {
   void* t1;
   void* t2;
   void* t3;
};



struct mdc_tuple3_void_star_void_star_uint8_t {
   uint8_t t1;
   void* t2;
   void* t3;
};



struct mdc_tuple3_void_star_void_star_int8_t {
   int8_t t1;
   void* t2;
   void* t3;
};



struct mdc_tuple3_void_star_void_star_uint16_t {
   uint16_t t1;
   void* t2;
   void* t3;
};



struct mdc_tuple3_void_star_void_star_int16_t {
   int16_t t1;
   void* t2;
   void* t3;
};



struct mdc_tuple3_void_star_void_star_uint32_t {
   uint32_t t1;
   void* t2;
   void* t3;
};



struct mdc_tuple3_void_star_void_star_int32_t {
   int32_t t1;
   void* t2;
   void* t3;
};



struct mdc_tuple3_void_star_void_star_uint64_t {
   uint64_t t1;
   void* t2;
   void* t3;
};



struct mdc_tuple3_void_star_void_star_int64_t {
   int64_t t1;
   void* t2;
   void* t3;
};



struct mdc_tuple3_void_star_void_star_float {
   float t1;
   void* t2;
   void* t3;
};



struct mdc_tuple3_void_star_void_star_double {
   double t1;
   void* t2;
   void* t3;
};



struct mdc_tuple3_void_star_uint8_t_char {
   char t1;
   uint8_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_uint8_t_void_star {
   void* t1;
   uint8_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_uint8_t_uint8_t {
   uint8_t t1;
   uint8_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_uint8_t_int8_t {
   int8_t t1;
   uint8_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_uint8_t_uint16_t {
   uint16_t t1;
   uint8_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_uint8_t_int16_t {
   int16_t t1;
   uint8_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_uint8_t_uint32_t {
   uint32_t t1;
   uint8_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_uint8_t_int32_t {
   int32_t t1;
   uint8_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_uint8_t_uint64_t {
   uint64_t t1;
   uint8_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_uint8_t_int64_t {
   int64_t t1;
   uint8_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_uint8_t_float {
   float t1;
   uint8_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_uint8_t_double {
   double t1;
   uint8_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_int8_t_char {
   char t1;
   int8_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_int8_t_void_star {
   void* t1;
   int8_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_int8_t_uint8_t {
   uint8_t t1;
   int8_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_int8_t_int8_t {
   int8_t t1;
   int8_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_int8_t_uint16_t {
   uint16_t t1;
   int8_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_int8_t_int16_t {
   int16_t t1;
   int8_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_int8_t_uint32_t {
   uint32_t t1;
   int8_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_int8_t_int32_t {
   int32_t t1;
   int8_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_int8_t_uint64_t {
   uint64_t t1;
   int8_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_int8_t_int64_t {
   int64_t t1;
   int8_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_int8_t_float {
   float t1;
   int8_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_int8_t_double {
   double t1;
   int8_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_uint16_t_char {
   char t1;
   uint16_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_uint16_t_void_star {
   void* t1;
   uint16_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_uint16_t_uint8_t {
   uint8_t t1;
   uint16_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_uint16_t_int8_t {
   int8_t t1;
   uint16_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_uint16_t_uint16_t {
   uint16_t t1;
   uint16_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_uint16_t_int16_t {
   int16_t t1;
   uint16_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_uint16_t_uint32_t {
   uint32_t t1;
   uint16_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_uint16_t_int32_t {
   int32_t t1;
   uint16_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_uint16_t_uint64_t {
   uint64_t t1;
   uint16_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_uint16_t_int64_t {
   int64_t t1;
   uint16_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_uint16_t_float {
   float t1;
   uint16_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_uint16_t_double {
   double t1;
   uint16_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_int16_t_char {
   char t1;
   int16_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_int16_t_void_star {
   void* t1;
   int16_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_int16_t_uint8_t {
   uint8_t t1;
   int16_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_int16_t_int8_t {
   int8_t t1;
   int16_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_int16_t_uint16_t {
   uint16_t t1;
   int16_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_int16_t_int16_t {
   int16_t t1;
   int16_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_int16_t_uint32_t {
   uint32_t t1;
   int16_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_int16_t_int32_t {
   int32_t t1;
   int16_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_int16_t_uint64_t {
   uint64_t t1;
   int16_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_int16_t_int64_t {
   int64_t t1;
   int16_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_int16_t_float {
   float t1;
   int16_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_int16_t_double {
   double t1;
   int16_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_uint32_t_char {
   char t1;
   uint32_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_uint32_t_void_star {
   void* t1;
   uint32_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_uint32_t_uint8_t {
   uint8_t t1;
   uint32_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_uint32_t_int8_t {
   int8_t t1;
   uint32_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_uint32_t_uint16_t {
   uint16_t t1;
   uint32_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_uint32_t_int16_t {
   int16_t t1;
   uint32_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_uint32_t_uint32_t {
   uint32_t t1;
   uint32_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_uint32_t_int32_t {
   int32_t t1;
   uint32_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_uint32_t_uint64_t {
   uint64_t t1;
   uint32_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_uint32_t_int64_t {
   int64_t t1;
   uint32_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_uint32_t_float {
   float t1;
   uint32_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_uint32_t_double {
   double t1;
   uint32_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_int32_t_char {
   char t1;
   int32_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_int32_t_void_star {
   void* t1;
   int32_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_int32_t_uint8_t {
   uint8_t t1;
   int32_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_int32_t_int8_t {
   int8_t t1;
   int32_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_int32_t_uint16_t {
   uint16_t t1;
   int32_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_int32_t_int16_t {
   int16_t t1;
   int32_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_int32_t_uint32_t {
   uint32_t t1;
   int32_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_int32_t_int32_t {
   int32_t t1;
   int32_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_int32_t_uint64_t {
   uint64_t t1;
   int32_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_int32_t_int64_t {
   int64_t t1;
   int32_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_int32_t_float {
   float t1;
   int32_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_int32_t_double {
   double t1;
   int32_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_uint64_t_char {
   char t1;
   uint64_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_uint64_t_void_star {
   void* t1;
   uint64_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_uint64_t_uint8_t {
   uint8_t t1;
   uint64_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_uint64_t_int8_t {
   int8_t t1;
   uint64_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_uint64_t_uint16_t {
   uint16_t t1;
   uint64_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_uint64_t_int16_t {
   int16_t t1;
   uint64_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_uint64_t_uint32_t {
   uint32_t t1;
   uint64_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_uint64_t_int32_t {
   int32_t t1;
   uint64_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_uint64_t_uint64_t {
   uint64_t t1;
   uint64_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_uint64_t_int64_t {
   int64_t t1;
   uint64_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_uint64_t_float {
   float t1;
   uint64_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_uint64_t_double {
   double t1;
   uint64_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_int64_t_char {
   char t1;
   int64_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_int64_t_void_star {
   void* t1;
   int64_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_int64_t_uint8_t {
   uint8_t t1;
   int64_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_int64_t_int8_t {
   int8_t t1;
   int64_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_int64_t_uint16_t {
   uint16_t t1;
   int64_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_int64_t_int16_t {
   int16_t t1;
   int64_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_int64_t_uint32_t {
   uint32_t t1;
   int64_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_int64_t_int32_t {
   int32_t t1;
   int64_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_int64_t_uint64_t {
   uint64_t t1;
   int64_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_int64_t_int64_t {
   int64_t t1;
   int64_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_int64_t_float {
   float t1;
   int64_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_int64_t_double {
   double t1;
   int64_t t2;
   void* t3;
};



struct mdc_tuple3_void_star_float_char {
   char t1;
   float t2;
   void* t3;
};



struct mdc_tuple3_void_star_float_void_star {
   void* t1;
   float t2;
   void* t3;
};



struct mdc_tuple3_void_star_float_uint8_t {
   uint8_t t1;
   float t2;
   void* t3;
};



struct mdc_tuple3_void_star_float_int8_t {
   int8_t t1;
   float t2;
   void* t3;
};



struct mdc_tuple3_void_star_float_uint16_t {
   uint16_t t1;
   float t2;
   void* t3;
};



struct mdc_tuple3_void_star_float_int16_t {
   int16_t t1;
   float t2;
   void* t3;
};



struct mdc_tuple3_void_star_float_uint32_t {
   uint32_t t1;
   float t2;
   void* t3;
};



struct mdc_tuple3_void_star_float_int32_t {
   int32_t t1;
   float t2;
   void* t3;
};



struct mdc_tuple3_void_star_float_uint64_t {
   uint64_t t1;
   float t2;
   void* t3;
};



struct mdc_tuple3_void_star_float_int64_t {
   int64_t t1;
   float t2;
   void* t3;
};



struct mdc_tuple3_void_star_float_float {
   float t1;
   float t2;
   void* t3;
};



struct mdc_tuple3_void_star_float_double {
   double t1;
   float t2;
   void* t3;
};



struct mdc_tuple3_void_star_double_char {
   char t1;
   double t2;
   void* t3;
};



struct mdc_tuple3_void_star_double_void_star {
   void* t1;
   double t2;
   void* t3;
};



struct mdc_tuple3_void_star_double_uint8_t {
   uint8_t t1;
   double t2;
   void* t3;
};



struct mdc_tuple3_void_star_double_int8_t {
   int8_t t1;
   double t2;
   void* t3;
};



struct mdc_tuple3_void_star_double_uint16_t {
   uint16_t t1;
   double t2;
   void* t3;
};



struct mdc_tuple3_void_star_double_int16_t {
   int16_t t1;
   double t2;
   void* t3;
};



struct mdc_tuple3_void_star_double_uint32_t {
   uint32_t t1;
   double t2;
   void* t3;
};



struct mdc_tuple3_void_star_double_int32_t {
   int32_t t1;
   double t2;
   void* t3;
};



struct mdc_tuple3_void_star_double_uint64_t {
   uint64_t t1;
   double t2;
   void* t3;
};



struct mdc_tuple3_void_star_double_int64_t {
   int64_t t1;
   double t2;
   void* t3;
};



struct mdc_tuple3_void_star_double_float {
   float t1;
   double t2;
   void* t3;
};



struct mdc_tuple3_void_star_double_double {
   double t1;
   double t2;
   void* t3;
};



struct mdc_tuple3_uint8_t_char_char {
   char t1;
   char t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_char_void_star {
   void* t1;
   char t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_char_uint8_t {
   uint8_t t1;
   char t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_char_int8_t {
   int8_t t1;
   char t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_char_uint16_t {
   uint16_t t1;
   char t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_char_int16_t {
   int16_t t1;
   char t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_char_uint32_t {
   uint32_t t1;
   char t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_char_int32_t {
   int32_t t1;
   char t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_char_uint64_t {
   uint64_t t1;
   char t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_char_int64_t {
   int64_t t1;
   char t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_char_float {
   float t1;
   char t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_char_double {
   double t1;
   char t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_void_star_char {
   char t1;
   void* t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_void_star_void_star {
   void* t1;
   void* t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_void_star_uint8_t {
   uint8_t t1;
   void* t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_void_star_int8_t {
   int8_t t1;
   void* t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_void_star_uint16_t {
   uint16_t t1;
   void* t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_void_star_int16_t {
   int16_t t1;
   void* t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_void_star_uint32_t {
   uint32_t t1;
   void* t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_void_star_int32_t {
   int32_t t1;
   void* t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_void_star_uint64_t {
   uint64_t t1;
   void* t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_void_star_int64_t {
   int64_t t1;
   void* t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_void_star_float {
   float t1;
   void* t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_void_star_double {
   double t1;
   void* t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_uint8_t_char {
   char t1;
   uint8_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_uint8_t_void_star {
   void* t1;
   uint8_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_uint8_t_uint8_t {
   uint8_t t1;
   uint8_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_uint8_t_int8_t {
   int8_t t1;
   uint8_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_uint8_t_uint16_t {
   uint16_t t1;
   uint8_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_uint8_t_int16_t {
   int16_t t1;
   uint8_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_uint8_t_uint32_t {
   uint32_t t1;
   uint8_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_uint8_t_int32_t {
   int32_t t1;
   uint8_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_uint8_t_uint64_t {
   uint64_t t1;
   uint8_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_uint8_t_int64_t {
   int64_t t1;
   uint8_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_uint8_t_float {
   float t1;
   uint8_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_uint8_t_double {
   double t1;
   uint8_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_int8_t_char {
   char t1;
   int8_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_int8_t_void_star {
   void* t1;
   int8_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_int8_t_uint8_t {
   uint8_t t1;
   int8_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_int8_t_int8_t {
   int8_t t1;
   int8_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_int8_t_uint16_t {
   uint16_t t1;
   int8_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_int8_t_int16_t {
   int16_t t1;
   int8_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_int8_t_uint32_t {
   uint32_t t1;
   int8_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_int8_t_int32_t {
   int32_t t1;
   int8_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_int8_t_uint64_t {
   uint64_t t1;
   int8_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_int8_t_int64_t {
   int64_t t1;
   int8_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_int8_t_float {
   float t1;
   int8_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_int8_t_double {
   double t1;
   int8_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_uint16_t_char {
   char t1;
   uint16_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_uint16_t_void_star {
   void* t1;
   uint16_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_uint16_t_uint8_t {
   uint8_t t1;
   uint16_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_uint16_t_int8_t {
   int8_t t1;
   uint16_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_uint16_t_uint16_t {
   uint16_t t1;
   uint16_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_uint16_t_int16_t {
   int16_t t1;
   uint16_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_uint16_t_uint32_t {
   uint32_t t1;
   uint16_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_uint16_t_int32_t {
   int32_t t1;
   uint16_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_uint16_t_uint64_t {
   uint64_t t1;
   uint16_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_uint16_t_int64_t {
   int64_t t1;
   uint16_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_uint16_t_float {
   float t1;
   uint16_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_uint16_t_double {
   double t1;
   uint16_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_int16_t_char {
   char t1;
   int16_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_int16_t_void_star {
   void* t1;
   int16_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_int16_t_uint8_t {
   uint8_t t1;
   int16_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_int16_t_int8_t {
   int8_t t1;
   int16_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_int16_t_uint16_t {
   uint16_t t1;
   int16_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_int16_t_int16_t {
   int16_t t1;
   int16_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_int16_t_uint32_t {
   uint32_t t1;
   int16_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_int16_t_int32_t {
   int32_t t1;
   int16_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_int16_t_uint64_t {
   uint64_t t1;
   int16_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_int16_t_int64_t {
   int64_t t1;
   int16_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_int16_t_float {
   float t1;
   int16_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_int16_t_double {
   double t1;
   int16_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_uint32_t_char {
   char t1;
   uint32_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_uint32_t_void_star {
   void* t1;
   uint32_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_uint32_t_uint8_t {
   uint8_t t1;
   uint32_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_uint32_t_int8_t {
   int8_t t1;
   uint32_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_uint32_t_uint16_t {
   uint16_t t1;
   uint32_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_uint32_t_int16_t {
   int16_t t1;
   uint32_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_uint32_t_uint32_t {
   uint32_t t1;
   uint32_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_uint32_t_int32_t {
   int32_t t1;
   uint32_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_uint32_t_uint64_t {
   uint64_t t1;
   uint32_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_uint32_t_int64_t {
   int64_t t1;
   uint32_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_uint32_t_float {
   float t1;
   uint32_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_uint32_t_double {
   double t1;
   uint32_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_int32_t_char {
   char t1;
   int32_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_int32_t_void_star {
   void* t1;
   int32_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_int32_t_uint8_t {
   uint8_t t1;
   int32_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_int32_t_int8_t {
   int8_t t1;
   int32_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_int32_t_uint16_t {
   uint16_t t1;
   int32_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_int32_t_int16_t {
   int16_t t1;
   int32_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_int32_t_uint32_t {
   uint32_t t1;
   int32_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_int32_t_int32_t {
   int32_t t1;
   int32_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_int32_t_uint64_t {
   uint64_t t1;
   int32_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_int32_t_int64_t {
   int64_t t1;
   int32_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_int32_t_float {
   float t1;
   int32_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_int32_t_double {
   double t1;
   int32_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_uint64_t_char {
   char t1;
   uint64_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_uint64_t_void_star {
   void* t1;
   uint64_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_uint64_t_uint8_t {
   uint8_t t1;
   uint64_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_uint64_t_int8_t {
   int8_t t1;
   uint64_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_uint64_t_uint16_t {
   uint16_t t1;
   uint64_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_uint64_t_int16_t {
   int16_t t1;
   uint64_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_uint64_t_uint32_t {
   uint32_t t1;
   uint64_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_uint64_t_int32_t {
   int32_t t1;
   uint64_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_uint64_t_uint64_t {
   uint64_t t1;
   uint64_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_uint64_t_int64_t {
   int64_t t1;
   uint64_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_uint64_t_float {
   float t1;
   uint64_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_uint64_t_double {
   double t1;
   uint64_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_int64_t_char {
   char t1;
   int64_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_int64_t_void_star {
   void* t1;
   int64_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_int64_t_uint8_t {
   uint8_t t1;
   int64_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_int64_t_int8_t {
   int8_t t1;
   int64_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_int64_t_uint16_t {
   uint16_t t1;
   int64_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_int64_t_int16_t {
   int16_t t1;
   int64_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_int64_t_uint32_t {
   uint32_t t1;
   int64_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_int64_t_int32_t {
   int32_t t1;
   int64_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_int64_t_uint64_t {
   uint64_t t1;
   int64_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_int64_t_int64_t {
   int64_t t1;
   int64_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_int64_t_float {
   float t1;
   int64_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_int64_t_double {
   double t1;
   int64_t t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_float_char {
   char t1;
   float t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_float_void_star {
   void* t1;
   float t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_float_uint8_t {
   uint8_t t1;
   float t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_float_int8_t {
   int8_t t1;
   float t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_float_uint16_t {
   uint16_t t1;
   float t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_float_int16_t {
   int16_t t1;
   float t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_float_uint32_t {
   uint32_t t1;
   float t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_float_int32_t {
   int32_t t1;
   float t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_float_uint64_t {
   uint64_t t1;
   float t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_float_int64_t {
   int64_t t1;
   float t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_float_float {
   float t1;
   float t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_float_double {
   double t1;
   float t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_double_char {
   char t1;
   double t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_double_void_star {
   void* t1;
   double t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_double_uint8_t {
   uint8_t t1;
   double t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_double_int8_t {
   int8_t t1;
   double t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_double_uint16_t {
   uint16_t t1;
   double t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_double_int16_t {
   int16_t t1;
   double t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_double_uint32_t {
   uint32_t t1;
   double t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_double_int32_t {
   int32_t t1;
   double t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_double_uint64_t {
   uint64_t t1;
   double t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_double_int64_t {
   int64_t t1;
   double t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_double_float {
   float t1;
   double t2;
   uint8_t t3;
};



struct mdc_tuple3_uint8_t_double_double {
   double t1;
   double t2;
   uint8_t t3;
};



struct mdc_tuple3_int8_t_char_char {
   char t1;
   char t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_char_void_star {
   void* t1;
   char t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_char_uint8_t {
   uint8_t t1;
   char t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_char_int8_t {
   int8_t t1;
   char t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_char_uint16_t {
   uint16_t t1;
   char t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_char_int16_t {
   int16_t t1;
   char t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_char_uint32_t {
   uint32_t t1;
   char t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_char_int32_t {
   int32_t t1;
   char t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_char_uint64_t {
   uint64_t t1;
   char t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_char_int64_t {
   int64_t t1;
   char t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_char_float {
   float t1;
   char t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_char_double {
   double t1;
   char t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_void_star_char {
   char t1;
   void* t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_void_star_void_star {
   void* t1;
   void* t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_void_star_uint8_t {
   uint8_t t1;
   void* t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_void_star_int8_t {
   int8_t t1;
   void* t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_void_star_uint16_t {
   uint16_t t1;
   void* t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_void_star_int16_t {
   int16_t t1;
   void* t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_void_star_uint32_t {
   uint32_t t1;
   void* t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_void_star_int32_t {
   int32_t t1;
   void* t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_void_star_uint64_t {
   uint64_t t1;
   void* t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_void_star_int64_t {
   int64_t t1;
   void* t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_void_star_float {
   float t1;
   void* t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_void_star_double {
   double t1;
   void* t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_uint8_t_char {
   char t1;
   uint8_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_uint8_t_void_star {
   void* t1;
   uint8_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_uint8_t_uint8_t {
   uint8_t t1;
   uint8_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_uint8_t_int8_t {
   int8_t t1;
   uint8_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_uint8_t_uint16_t {
   uint16_t t1;
   uint8_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_uint8_t_int16_t {
   int16_t t1;
   uint8_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_uint8_t_uint32_t {
   uint32_t t1;
   uint8_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_uint8_t_int32_t {
   int32_t t1;
   uint8_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_uint8_t_uint64_t {
   uint64_t t1;
   uint8_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_uint8_t_int64_t {
   int64_t t1;
   uint8_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_uint8_t_float {
   float t1;
   uint8_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_uint8_t_double {
   double t1;
   uint8_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_int8_t_char {
   char t1;
   int8_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_int8_t_void_star {
   void* t1;
   int8_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_int8_t_uint8_t {
   uint8_t t1;
   int8_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_int8_t_int8_t {
   int8_t t1;
   int8_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_int8_t_uint16_t {
   uint16_t t1;
   int8_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_int8_t_int16_t {
   int16_t t1;
   int8_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_int8_t_uint32_t {
   uint32_t t1;
   int8_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_int8_t_int32_t {
   int32_t t1;
   int8_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_int8_t_uint64_t {
   uint64_t t1;
   int8_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_int8_t_int64_t {
   int64_t t1;
   int8_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_int8_t_float {
   float t1;
   int8_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_int8_t_double {
   double t1;
   int8_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_uint16_t_char {
   char t1;
   uint16_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_uint16_t_void_star {
   void* t1;
   uint16_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_uint16_t_uint8_t {
   uint8_t t1;
   uint16_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_uint16_t_int8_t {
   int8_t t1;
   uint16_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_uint16_t_uint16_t {
   uint16_t t1;
   uint16_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_uint16_t_int16_t {
   int16_t t1;
   uint16_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_uint16_t_uint32_t {
   uint32_t t1;
   uint16_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_uint16_t_int32_t {
   int32_t t1;
   uint16_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_uint16_t_uint64_t {
   uint64_t t1;
   uint16_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_uint16_t_int64_t {
   int64_t t1;
   uint16_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_uint16_t_float {
   float t1;
   uint16_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_uint16_t_double {
   double t1;
   uint16_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_int16_t_char {
   char t1;
   int16_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_int16_t_void_star {
   void* t1;
   int16_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_int16_t_uint8_t {
   uint8_t t1;
   int16_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_int16_t_int8_t {
   int8_t t1;
   int16_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_int16_t_uint16_t {
   uint16_t t1;
   int16_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_int16_t_int16_t {
   int16_t t1;
   int16_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_int16_t_uint32_t {
   uint32_t t1;
   int16_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_int16_t_int32_t {
   int32_t t1;
   int16_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_int16_t_uint64_t {
   uint64_t t1;
   int16_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_int16_t_int64_t {
   int64_t t1;
   int16_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_int16_t_float {
   float t1;
   int16_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_int16_t_double {
   double t1;
   int16_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_uint32_t_char {
   char t1;
   uint32_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_uint32_t_void_star {
   void* t1;
   uint32_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_uint32_t_uint8_t {
   uint8_t t1;
   uint32_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_uint32_t_int8_t {
   int8_t t1;
   uint32_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_uint32_t_uint16_t {
   uint16_t t1;
   uint32_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_uint32_t_int16_t {
   int16_t t1;
   uint32_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_uint32_t_uint32_t {
   uint32_t t1;
   uint32_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_uint32_t_int32_t {
   int32_t t1;
   uint32_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_uint32_t_uint64_t {
   uint64_t t1;
   uint32_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_uint32_t_int64_t {
   int64_t t1;
   uint32_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_uint32_t_float {
   float t1;
   uint32_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_uint32_t_double {
   double t1;
   uint32_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_int32_t_char {
   char t1;
   int32_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_int32_t_void_star {
   void* t1;
   int32_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_int32_t_uint8_t {
   uint8_t t1;
   int32_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_int32_t_int8_t {
   int8_t t1;
   int32_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_int32_t_uint16_t {
   uint16_t t1;
   int32_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_int32_t_int16_t {
   int16_t t1;
   int32_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_int32_t_uint32_t {
   uint32_t t1;
   int32_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_int32_t_int32_t {
   int32_t t1;
   int32_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_int32_t_uint64_t {
   uint64_t t1;
   int32_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_int32_t_int64_t {
   int64_t t1;
   int32_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_int32_t_float {
   float t1;
   int32_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_int32_t_double {
   double t1;
   int32_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_uint64_t_char {
   char t1;
   uint64_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_uint64_t_void_star {
   void* t1;
   uint64_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_uint64_t_uint8_t {
   uint8_t t1;
   uint64_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_uint64_t_int8_t {
   int8_t t1;
   uint64_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_uint64_t_uint16_t {
   uint16_t t1;
   uint64_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_uint64_t_int16_t {
   int16_t t1;
   uint64_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_uint64_t_uint32_t {
   uint32_t t1;
   uint64_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_uint64_t_int32_t {
   int32_t t1;
   uint64_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_uint64_t_uint64_t {
   uint64_t t1;
   uint64_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_uint64_t_int64_t {
   int64_t t1;
   uint64_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_uint64_t_float {
   float t1;
   uint64_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_uint64_t_double {
   double t1;
   uint64_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_int64_t_char {
   char t1;
   int64_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_int64_t_void_star {
   void* t1;
   int64_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_int64_t_uint8_t {
   uint8_t t1;
   int64_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_int64_t_int8_t {
   int8_t t1;
   int64_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_int64_t_uint16_t {
   uint16_t t1;
   int64_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_int64_t_int16_t {
   int16_t t1;
   int64_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_int64_t_uint32_t {
   uint32_t t1;
   int64_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_int64_t_int32_t {
   int32_t t1;
   int64_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_int64_t_uint64_t {
   uint64_t t1;
   int64_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_int64_t_int64_t {
   int64_t t1;
   int64_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_int64_t_float {
   float t1;
   int64_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_int64_t_double {
   double t1;
   int64_t t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_float_char {
   char t1;
   float t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_float_void_star {
   void* t1;
   float t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_float_uint8_t {
   uint8_t t1;
   float t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_float_int8_t {
   int8_t t1;
   float t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_float_uint16_t {
   uint16_t t1;
   float t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_float_int16_t {
   int16_t t1;
   float t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_float_uint32_t {
   uint32_t t1;
   float t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_float_int32_t {
   int32_t t1;
   float t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_float_uint64_t {
   uint64_t t1;
   float t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_float_int64_t {
   int64_t t1;
   float t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_float_float {
   float t1;
   float t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_float_double {
   double t1;
   float t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_double_char {
   char t1;
   double t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_double_void_star {
   void* t1;
   double t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_double_uint8_t {
   uint8_t t1;
   double t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_double_int8_t {
   int8_t t1;
   double t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_double_uint16_t {
   uint16_t t1;
   double t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_double_int16_t {
   int16_t t1;
   double t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_double_uint32_t {
   uint32_t t1;
   double t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_double_int32_t {
   int32_t t1;
   double t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_double_uint64_t {
   uint64_t t1;
   double t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_double_int64_t {
   int64_t t1;
   double t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_double_float {
   float t1;
   double t2;
   int8_t t3;
};



struct mdc_tuple3_int8_t_double_double {
   double t1;
   double t2;
   int8_t t3;
};



struct mdc_tuple3_uint16_t_char_char {
   char t1;
   char t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_char_void_star {
   void* t1;
   char t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_char_uint8_t {
   uint8_t t1;
   char t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_char_int8_t {
   int8_t t1;
   char t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_char_uint16_t {
   uint16_t t1;
   char t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_char_int16_t {
   int16_t t1;
   char t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_char_uint32_t {
   uint32_t t1;
   char t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_char_int32_t {
   int32_t t1;
   char t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_char_uint64_t {
   uint64_t t1;
   char t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_char_int64_t {
   int64_t t1;
   char t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_char_float {
   float t1;
   char t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_char_double {
   double t1;
   char t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_void_star_char {
   char t1;
   void* t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_void_star_void_star {
   void* t1;
   void* t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_void_star_uint8_t {
   uint8_t t1;
   void* t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_void_star_int8_t {
   int8_t t1;
   void* t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_void_star_uint16_t {
   uint16_t t1;
   void* t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_void_star_int16_t {
   int16_t t1;
   void* t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_void_star_uint32_t {
   uint32_t t1;
   void* t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_void_star_int32_t {
   int32_t t1;
   void* t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_void_star_uint64_t {
   uint64_t t1;
   void* t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_void_star_int64_t {
   int64_t t1;
   void* t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_void_star_float {
   float t1;
   void* t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_void_star_double {
   double t1;
   void* t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_uint8_t_char {
   char t1;
   uint8_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_uint8_t_void_star {
   void* t1;
   uint8_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_uint8_t_uint8_t {
   uint8_t t1;
   uint8_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_uint8_t_int8_t {
   int8_t t1;
   uint8_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_uint8_t_uint16_t {
   uint16_t t1;
   uint8_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_uint8_t_int16_t {
   int16_t t1;
   uint8_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_uint8_t_uint32_t {
   uint32_t t1;
   uint8_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_uint8_t_int32_t {
   int32_t t1;
   uint8_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_uint8_t_uint64_t {
   uint64_t t1;
   uint8_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_uint8_t_int64_t {
   int64_t t1;
   uint8_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_uint8_t_float {
   float t1;
   uint8_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_uint8_t_double {
   double t1;
   uint8_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_int8_t_char {
   char t1;
   int8_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_int8_t_void_star {
   void* t1;
   int8_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_int8_t_uint8_t {
   uint8_t t1;
   int8_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_int8_t_int8_t {
   int8_t t1;
   int8_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_int8_t_uint16_t {
   uint16_t t1;
   int8_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_int8_t_int16_t {
   int16_t t1;
   int8_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_int8_t_uint32_t {
   uint32_t t1;
   int8_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_int8_t_int32_t {
   int32_t t1;
   int8_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_int8_t_uint64_t {
   uint64_t t1;
   int8_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_int8_t_int64_t {
   int64_t t1;
   int8_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_int8_t_float {
   float t1;
   int8_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_int8_t_double {
   double t1;
   int8_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_uint16_t_char {
   char t1;
   uint16_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_uint16_t_void_star {
   void* t1;
   uint16_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_uint16_t_uint8_t {
   uint8_t t1;
   uint16_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_uint16_t_int8_t {
   int8_t t1;
   uint16_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_uint16_t_uint16_t {
   uint16_t t1;
   uint16_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_uint16_t_int16_t {
   int16_t t1;
   uint16_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_uint16_t_uint32_t {
   uint32_t t1;
   uint16_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_uint16_t_int32_t {
   int32_t t1;
   uint16_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_uint16_t_uint64_t {
   uint64_t t1;
   uint16_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_uint16_t_int64_t {
   int64_t t1;
   uint16_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_uint16_t_float {
   float t1;
   uint16_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_uint16_t_double {
   double t1;
   uint16_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_int16_t_char {
   char t1;
   int16_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_int16_t_void_star {
   void* t1;
   int16_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_int16_t_uint8_t {
   uint8_t t1;
   int16_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_int16_t_int8_t {
   int8_t t1;
   int16_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_int16_t_uint16_t {
   uint16_t t1;
   int16_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_int16_t_int16_t {
   int16_t t1;
   int16_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_int16_t_uint32_t {
   uint32_t t1;
   int16_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_int16_t_int32_t {
   int32_t t1;
   int16_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_int16_t_uint64_t {
   uint64_t t1;
   int16_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_int16_t_int64_t {
   int64_t t1;
   int16_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_int16_t_float {
   float t1;
   int16_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_int16_t_double {
   double t1;
   int16_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_uint32_t_char {
   char t1;
   uint32_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_uint32_t_void_star {
   void* t1;
   uint32_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_uint32_t_uint8_t {
   uint8_t t1;
   uint32_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_uint32_t_int8_t {
   int8_t t1;
   uint32_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_uint32_t_uint16_t {
   uint16_t t1;
   uint32_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_uint32_t_int16_t {
   int16_t t1;
   uint32_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_uint32_t_uint32_t {
   uint32_t t1;
   uint32_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_uint32_t_int32_t {
   int32_t t1;
   uint32_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_uint32_t_uint64_t {
   uint64_t t1;
   uint32_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_uint32_t_int64_t {
   int64_t t1;
   uint32_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_uint32_t_float {
   float t1;
   uint32_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_uint32_t_double {
   double t1;
   uint32_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_int32_t_char {
   char t1;
   int32_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_int32_t_void_star {
   void* t1;
   int32_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_int32_t_uint8_t {
   uint8_t t1;
   int32_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_int32_t_int8_t {
   int8_t t1;
   int32_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_int32_t_uint16_t {
   uint16_t t1;
   int32_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_int32_t_int16_t {
   int16_t t1;
   int32_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_int32_t_uint32_t {
   uint32_t t1;
   int32_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_int32_t_int32_t {
   int32_t t1;
   int32_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_int32_t_uint64_t {
   uint64_t t1;
   int32_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_int32_t_int64_t {
   int64_t t1;
   int32_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_int32_t_float {
   float t1;
   int32_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_int32_t_double {
   double t1;
   int32_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_uint64_t_char {
   char t1;
   uint64_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_uint64_t_void_star {
   void* t1;
   uint64_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_uint64_t_uint8_t {
   uint8_t t1;
   uint64_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_uint64_t_int8_t {
   int8_t t1;
   uint64_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_uint64_t_uint16_t {
   uint16_t t1;
   uint64_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_uint64_t_int16_t {
   int16_t t1;
   uint64_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_uint64_t_uint32_t {
   uint32_t t1;
   uint64_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_uint64_t_int32_t {
   int32_t t1;
   uint64_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_uint64_t_uint64_t {
   uint64_t t1;
   uint64_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_uint64_t_int64_t {
   int64_t t1;
   uint64_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_uint64_t_float {
   float t1;
   uint64_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_uint64_t_double {
   double t1;
   uint64_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_int64_t_char {
   char t1;
   int64_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_int64_t_void_star {
   void* t1;
   int64_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_int64_t_uint8_t {
   uint8_t t1;
   int64_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_int64_t_int8_t {
   int8_t t1;
   int64_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_int64_t_uint16_t {
   uint16_t t1;
   int64_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_int64_t_int16_t {
   int16_t t1;
   int64_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_int64_t_uint32_t {
   uint32_t t1;
   int64_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_int64_t_int32_t {
   int32_t t1;
   int64_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_int64_t_uint64_t {
   uint64_t t1;
   int64_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_int64_t_int64_t {
   int64_t t1;
   int64_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_int64_t_float {
   float t1;
   int64_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_int64_t_double {
   double t1;
   int64_t t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_float_char {
   char t1;
   float t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_float_void_star {
   void* t1;
   float t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_float_uint8_t {
   uint8_t t1;
   float t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_float_int8_t {
   int8_t t1;
   float t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_float_uint16_t {
   uint16_t t1;
   float t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_float_int16_t {
   int16_t t1;
   float t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_float_uint32_t {
   uint32_t t1;
   float t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_float_int32_t {
   int32_t t1;
   float t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_float_uint64_t {
   uint64_t t1;
   float t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_float_int64_t {
   int64_t t1;
   float t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_float_float {
   float t1;
   float t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_float_double {
   double t1;
   float t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_double_char {
   char t1;
   double t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_double_void_star {
   void* t1;
   double t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_double_uint8_t {
   uint8_t t1;
   double t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_double_int8_t {
   int8_t t1;
   double t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_double_uint16_t {
   uint16_t t1;
   double t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_double_int16_t {
   int16_t t1;
   double t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_double_uint32_t {
   uint32_t t1;
   double t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_double_int32_t {
   int32_t t1;
   double t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_double_uint64_t {
   uint64_t t1;
   double t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_double_int64_t {
   int64_t t1;
   double t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_double_float {
   float t1;
   double t2;
   uint16_t t3;
};



struct mdc_tuple3_uint16_t_double_double {
   double t1;
   double t2;
   uint16_t t3;
};



struct mdc_tuple3_int16_t_char_char {
   char t1;
   char t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_char_void_star {
   void* t1;
   char t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_char_uint8_t {
   uint8_t t1;
   char t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_char_int8_t {
   int8_t t1;
   char t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_char_uint16_t {
   uint16_t t1;
   char t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_char_int16_t {
   int16_t t1;
   char t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_char_uint32_t {
   uint32_t t1;
   char t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_char_int32_t {
   int32_t t1;
   char t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_char_uint64_t {
   uint64_t t1;
   char t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_char_int64_t {
   int64_t t1;
   char t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_char_float {
   float t1;
   char t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_char_double {
   double t1;
   char t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_void_star_char {
   char t1;
   void* t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_void_star_void_star {
   void* t1;
   void* t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_void_star_uint8_t {
   uint8_t t1;
   void* t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_void_star_int8_t {
   int8_t t1;
   void* t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_void_star_uint16_t {
   uint16_t t1;
   void* t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_void_star_int16_t {
   int16_t t1;
   void* t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_void_star_uint32_t {
   uint32_t t1;
   void* t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_void_star_int32_t {
   int32_t t1;
   void* t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_void_star_uint64_t {
   uint64_t t1;
   void* t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_void_star_int64_t {
   int64_t t1;
   void* t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_void_star_float {
   float t1;
   void* t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_void_star_double {
   double t1;
   void* t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_uint8_t_char {
   char t1;
   uint8_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_uint8_t_void_star {
   void* t1;
   uint8_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_uint8_t_uint8_t {
   uint8_t t1;
   uint8_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_uint8_t_int8_t {
   int8_t t1;
   uint8_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_uint8_t_uint16_t {
   uint16_t t1;
   uint8_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_uint8_t_int16_t {
   int16_t t1;
   uint8_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_uint8_t_uint32_t {
   uint32_t t1;
   uint8_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_uint8_t_int32_t {
   int32_t t1;
   uint8_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_uint8_t_uint64_t {
   uint64_t t1;
   uint8_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_uint8_t_int64_t {
   int64_t t1;
   uint8_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_uint8_t_float {
   float t1;
   uint8_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_uint8_t_double {
   double t1;
   uint8_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_int8_t_char {
   char t1;
   int8_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_int8_t_void_star {
   void* t1;
   int8_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_int8_t_uint8_t {
   uint8_t t1;
   int8_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_int8_t_int8_t {
   int8_t t1;
   int8_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_int8_t_uint16_t {
   uint16_t t1;
   int8_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_int8_t_int16_t {
   int16_t t1;
   int8_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_int8_t_uint32_t {
   uint32_t t1;
   int8_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_int8_t_int32_t {
   int32_t t1;
   int8_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_int8_t_uint64_t {
   uint64_t t1;
   int8_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_int8_t_int64_t {
   int64_t t1;
   int8_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_int8_t_float {
   float t1;
   int8_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_int8_t_double {
   double t1;
   int8_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_uint16_t_char {
   char t1;
   uint16_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_uint16_t_void_star {
   void* t1;
   uint16_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_uint16_t_uint8_t {
   uint8_t t1;
   uint16_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_uint16_t_int8_t {
   int8_t t1;
   uint16_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_uint16_t_uint16_t {
   uint16_t t1;
   uint16_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_uint16_t_int16_t {
   int16_t t1;
   uint16_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_uint16_t_uint32_t {
   uint32_t t1;
   uint16_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_uint16_t_int32_t {
   int32_t t1;
   uint16_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_uint16_t_uint64_t {
   uint64_t t1;
   uint16_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_uint16_t_int64_t {
   int64_t t1;
   uint16_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_uint16_t_float {
   float t1;
   uint16_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_uint16_t_double {
   double t1;
   uint16_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_int16_t_char {
   char t1;
   int16_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_int16_t_void_star {
   void* t1;
   int16_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_int16_t_uint8_t {
   uint8_t t1;
   int16_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_int16_t_int8_t {
   int8_t t1;
   int16_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_int16_t_uint16_t {
   uint16_t t1;
   int16_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_int16_t_int16_t {
   int16_t t1;
   int16_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_int16_t_uint32_t {
   uint32_t t1;
   int16_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_int16_t_int32_t {
   int32_t t1;
   int16_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_int16_t_uint64_t {
   uint64_t t1;
   int16_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_int16_t_int64_t {
   int64_t t1;
   int16_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_int16_t_float {
   float t1;
   int16_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_int16_t_double {
   double t1;
   int16_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_uint32_t_char {
   char t1;
   uint32_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_uint32_t_void_star {
   void* t1;
   uint32_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_uint32_t_uint8_t {
   uint8_t t1;
   uint32_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_uint32_t_int8_t {
   int8_t t1;
   uint32_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_uint32_t_uint16_t {
   uint16_t t1;
   uint32_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_uint32_t_int16_t {
   int16_t t1;
   uint32_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_uint32_t_uint32_t {
   uint32_t t1;
   uint32_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_uint32_t_int32_t {
   int32_t t1;
   uint32_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_uint32_t_uint64_t {
   uint64_t t1;
   uint32_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_uint32_t_int64_t {
   int64_t t1;
   uint32_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_uint32_t_float {
   float t1;
   uint32_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_uint32_t_double {
   double t1;
   uint32_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_int32_t_char {
   char t1;
   int32_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_int32_t_void_star {
   void* t1;
   int32_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_int32_t_uint8_t {
   uint8_t t1;
   int32_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_int32_t_int8_t {
   int8_t t1;
   int32_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_int32_t_uint16_t {
   uint16_t t1;
   int32_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_int32_t_int16_t {
   int16_t t1;
   int32_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_int32_t_uint32_t {
   uint32_t t1;
   int32_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_int32_t_int32_t {
   int32_t t1;
   int32_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_int32_t_uint64_t {
   uint64_t t1;
   int32_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_int32_t_int64_t {
   int64_t t1;
   int32_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_int32_t_float {
   float t1;
   int32_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_int32_t_double {
   double t1;
   int32_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_uint64_t_char {
   char t1;
   uint64_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_uint64_t_void_star {
   void* t1;
   uint64_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_uint64_t_uint8_t {
   uint8_t t1;
   uint64_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_uint64_t_int8_t {
   int8_t t1;
   uint64_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_uint64_t_uint16_t {
   uint16_t t1;
   uint64_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_uint64_t_int16_t {
   int16_t t1;
   uint64_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_uint64_t_uint32_t {
   uint32_t t1;
   uint64_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_uint64_t_int32_t {
   int32_t t1;
   uint64_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_uint64_t_uint64_t {
   uint64_t t1;
   uint64_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_uint64_t_int64_t {
   int64_t t1;
   uint64_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_uint64_t_float {
   float t1;
   uint64_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_uint64_t_double {
   double t1;
   uint64_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_int64_t_char {
   char t1;
   int64_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_int64_t_void_star {
   void* t1;
   int64_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_int64_t_uint8_t {
   uint8_t t1;
   int64_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_int64_t_int8_t {
   int8_t t1;
   int64_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_int64_t_uint16_t {
   uint16_t t1;
   int64_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_int64_t_int16_t {
   int16_t t1;
   int64_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_int64_t_uint32_t {
   uint32_t t1;
   int64_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_int64_t_int32_t {
   int32_t t1;
   int64_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_int64_t_uint64_t {
   uint64_t t1;
   int64_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_int64_t_int64_t {
   int64_t t1;
   int64_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_int64_t_float {
   float t1;
   int64_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_int64_t_double {
   double t1;
   int64_t t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_float_char {
   char t1;
   float t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_float_void_star {
   void* t1;
   float t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_float_uint8_t {
   uint8_t t1;
   float t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_float_int8_t {
   int8_t t1;
   float t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_float_uint16_t {
   uint16_t t1;
   float t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_float_int16_t {
   int16_t t1;
   float t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_float_uint32_t {
   uint32_t t1;
   float t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_float_int32_t {
   int32_t t1;
   float t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_float_uint64_t {
   uint64_t t1;
   float t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_float_int64_t {
   int64_t t1;
   float t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_float_float {
   float t1;
   float t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_float_double {
   double t1;
   float t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_double_char {
   char t1;
   double t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_double_void_star {
   void* t1;
   double t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_double_uint8_t {
   uint8_t t1;
   double t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_double_int8_t {
   int8_t t1;
   double t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_double_uint16_t {
   uint16_t t1;
   double t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_double_int16_t {
   int16_t t1;
   double t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_double_uint32_t {
   uint32_t t1;
   double t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_double_int32_t {
   int32_t t1;
   double t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_double_uint64_t {
   uint64_t t1;
   double t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_double_int64_t {
   int64_t t1;
   double t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_double_float {
   float t1;
   double t2;
   int16_t t3;
};



struct mdc_tuple3_int16_t_double_double {
   double t1;
   double t2;
   int16_t t3;
};



struct mdc_tuple3_uint32_t_char_char {
   char t1;
   char t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_char_void_star {
   void* t1;
   char t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_char_uint8_t {
   uint8_t t1;
   char t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_char_int8_t {
   int8_t t1;
   char t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_char_uint16_t {
   uint16_t t1;
   char t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_char_int16_t {
   int16_t t1;
   char t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_char_uint32_t {
   uint32_t t1;
   char t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_char_int32_t {
   int32_t t1;
   char t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_char_uint64_t {
   uint64_t t1;
   char t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_char_int64_t {
   int64_t t1;
   char t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_char_float {
   float t1;
   char t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_char_double {
   double t1;
   char t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_void_star_char {
   char t1;
   void* t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_void_star_void_star {
   void* t1;
   void* t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_void_star_uint8_t {
   uint8_t t1;
   void* t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_void_star_int8_t {
   int8_t t1;
   void* t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_void_star_uint16_t {
   uint16_t t1;
   void* t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_void_star_int16_t {
   int16_t t1;
   void* t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_void_star_uint32_t {
   uint32_t t1;
   void* t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_void_star_int32_t {
   int32_t t1;
   void* t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_void_star_uint64_t {
   uint64_t t1;
   void* t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_void_star_int64_t {
   int64_t t1;
   void* t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_void_star_float {
   float t1;
   void* t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_void_star_double {
   double t1;
   void* t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_uint8_t_char {
   char t1;
   uint8_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_uint8_t_void_star {
   void* t1;
   uint8_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_uint8_t_uint8_t {
   uint8_t t1;
   uint8_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_uint8_t_int8_t {
   int8_t t1;
   uint8_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_uint8_t_uint16_t {
   uint16_t t1;
   uint8_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_uint8_t_int16_t {
   int16_t t1;
   uint8_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_uint8_t_uint32_t {
   uint32_t t1;
   uint8_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_uint8_t_int32_t {
   int32_t t1;
   uint8_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_uint8_t_uint64_t {
   uint64_t t1;
   uint8_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_uint8_t_int64_t {
   int64_t t1;
   uint8_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_uint8_t_float {
   float t1;
   uint8_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_uint8_t_double {
   double t1;
   uint8_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_int8_t_char {
   char t1;
   int8_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_int8_t_void_star {
   void* t1;
   int8_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_int8_t_uint8_t {
   uint8_t t1;
   int8_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_int8_t_int8_t {
   int8_t t1;
   int8_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_int8_t_uint16_t {
   uint16_t t1;
   int8_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_int8_t_int16_t {
   int16_t t1;
   int8_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_int8_t_uint32_t {
   uint32_t t1;
   int8_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_int8_t_int32_t {
   int32_t t1;
   int8_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_int8_t_uint64_t {
   uint64_t t1;
   int8_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_int8_t_int64_t {
   int64_t t1;
   int8_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_int8_t_float {
   float t1;
   int8_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_int8_t_double {
   double t1;
   int8_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_uint16_t_char {
   char t1;
   uint16_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_uint16_t_void_star {
   void* t1;
   uint16_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_uint16_t_uint8_t {
   uint8_t t1;
   uint16_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_uint16_t_int8_t {
   int8_t t1;
   uint16_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_uint16_t_uint16_t {
   uint16_t t1;
   uint16_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_uint16_t_int16_t {
   int16_t t1;
   uint16_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_uint16_t_uint32_t {
   uint32_t t1;
   uint16_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_uint16_t_int32_t {
   int32_t t1;
   uint16_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_uint16_t_uint64_t {
   uint64_t t1;
   uint16_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_uint16_t_int64_t {
   int64_t t1;
   uint16_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_uint16_t_float {
   float t1;
   uint16_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_uint16_t_double {
   double t1;
   uint16_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_int16_t_char {
   char t1;
   int16_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_int16_t_void_star {
   void* t1;
   int16_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_int16_t_uint8_t {
   uint8_t t1;
   int16_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_int16_t_int8_t {
   int8_t t1;
   int16_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_int16_t_uint16_t {
   uint16_t t1;
   int16_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_int16_t_int16_t {
   int16_t t1;
   int16_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_int16_t_uint32_t {
   uint32_t t1;
   int16_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_int16_t_int32_t {
   int32_t t1;
   int16_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_int16_t_uint64_t {
   uint64_t t1;
   int16_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_int16_t_int64_t {
   int64_t t1;
   int16_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_int16_t_float {
   float t1;
   int16_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_int16_t_double {
   double t1;
   int16_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_uint32_t_char {
   char t1;
   uint32_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_uint32_t_void_star {
   void* t1;
   uint32_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_uint32_t_uint8_t {
   uint8_t t1;
   uint32_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_uint32_t_int8_t {
   int8_t t1;
   uint32_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_uint32_t_uint16_t {
   uint16_t t1;
   uint32_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_uint32_t_int16_t {
   int16_t t1;
   uint32_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_uint32_t_uint32_t {
   uint32_t t1;
   uint32_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_uint32_t_int32_t {
   int32_t t1;
   uint32_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_uint32_t_uint64_t {
   uint64_t t1;
   uint32_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_uint32_t_int64_t {
   int64_t t1;
   uint32_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_uint32_t_float {
   float t1;
   uint32_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_uint32_t_double {
   double t1;
   uint32_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_int32_t_char {
   char t1;
   int32_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_int32_t_void_star {
   void* t1;
   int32_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_int32_t_uint8_t {
   uint8_t t1;
   int32_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_int32_t_int8_t {
   int8_t t1;
   int32_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_int32_t_uint16_t {
   uint16_t t1;
   int32_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_int32_t_int16_t {
   int16_t t1;
   int32_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_int32_t_uint32_t {
   uint32_t t1;
   int32_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_int32_t_int32_t {
   int32_t t1;
   int32_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_int32_t_uint64_t {
   uint64_t t1;
   int32_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_int32_t_int64_t {
   int64_t t1;
   int32_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_int32_t_float {
   float t1;
   int32_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_int32_t_double {
   double t1;
   int32_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_uint64_t_char {
   char t1;
   uint64_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_uint64_t_void_star {
   void* t1;
   uint64_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_uint64_t_uint8_t {
   uint8_t t1;
   uint64_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_uint64_t_int8_t {
   int8_t t1;
   uint64_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_uint64_t_uint16_t {
   uint16_t t1;
   uint64_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_uint64_t_int16_t {
   int16_t t1;
   uint64_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_uint64_t_uint32_t {
   uint32_t t1;
   uint64_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_uint64_t_int32_t {
   int32_t t1;
   uint64_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_uint64_t_uint64_t {
   uint64_t t1;
   uint64_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_uint64_t_int64_t {
   int64_t t1;
   uint64_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_uint64_t_float {
   float t1;
   uint64_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_uint64_t_double {
   double t1;
   uint64_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_int64_t_char {
   char t1;
   int64_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_int64_t_void_star {
   void* t1;
   int64_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_int64_t_uint8_t {
   uint8_t t1;
   int64_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_int64_t_int8_t {
   int8_t t1;
   int64_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_int64_t_uint16_t {
   uint16_t t1;
   int64_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_int64_t_int16_t {
   int16_t t1;
   int64_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_int64_t_uint32_t {
   uint32_t t1;
   int64_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_int64_t_int32_t {
   int32_t t1;
   int64_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_int64_t_uint64_t {
   uint64_t t1;
   int64_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_int64_t_int64_t {
   int64_t t1;
   int64_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_int64_t_float {
   float t1;
   int64_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_int64_t_double {
   double t1;
   int64_t t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_float_char {
   char t1;
   float t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_float_void_star {
   void* t1;
   float t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_float_uint8_t {
   uint8_t t1;
   float t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_float_int8_t {
   int8_t t1;
   float t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_float_uint16_t {
   uint16_t t1;
   float t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_float_int16_t {
   int16_t t1;
   float t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_float_uint32_t {
   uint32_t t1;
   float t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_float_int32_t {
   int32_t t1;
   float t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_float_uint64_t {
   uint64_t t1;
   float t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_float_int64_t {
   int64_t t1;
   float t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_float_float {
   float t1;
   float t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_float_double {
   double t1;
   float t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_double_char {
   char t1;
   double t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_double_void_star {
   void* t1;
   double t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_double_uint8_t {
   uint8_t t1;
   double t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_double_int8_t {
   int8_t t1;
   double t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_double_uint16_t {
   uint16_t t1;
   double t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_double_int16_t {
   int16_t t1;
   double t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_double_uint32_t {
   uint32_t t1;
   double t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_double_int32_t {
   int32_t t1;
   double t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_double_uint64_t {
   uint64_t t1;
   double t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_double_int64_t {
   int64_t t1;
   double t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_double_float {
   float t1;
   double t2;
   uint32_t t3;
};



struct mdc_tuple3_uint32_t_double_double {
   double t1;
   double t2;
   uint32_t t3;
};



struct mdc_tuple3_int32_t_char_char {
   char t1;
   char t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_char_void_star {
   void* t1;
   char t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_char_uint8_t {
   uint8_t t1;
   char t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_char_int8_t {
   int8_t t1;
   char t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_char_uint16_t {
   uint16_t t1;
   char t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_char_int16_t {
   int16_t t1;
   char t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_char_uint32_t {
   uint32_t t1;
   char t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_char_int32_t {
   int32_t t1;
   char t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_char_uint64_t {
   uint64_t t1;
   char t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_char_int64_t {
   int64_t t1;
   char t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_char_float {
   float t1;
   char t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_char_double {
   double t1;
   char t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_void_star_char {
   char t1;
   void* t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_void_star_void_star {
   void* t1;
   void* t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_void_star_uint8_t {
   uint8_t t1;
   void* t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_void_star_int8_t {
   int8_t t1;
   void* t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_void_star_uint16_t {
   uint16_t t1;
   void* t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_void_star_int16_t {
   int16_t t1;
   void* t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_void_star_uint32_t {
   uint32_t t1;
   void* t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_void_star_int32_t {
   int32_t t1;
   void* t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_void_star_uint64_t {
   uint64_t t1;
   void* t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_void_star_int64_t {
   int64_t t1;
   void* t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_void_star_float {
   float t1;
   void* t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_void_star_double {
   double t1;
   void* t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_uint8_t_char {
   char t1;
   uint8_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_uint8_t_void_star {
   void* t1;
   uint8_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_uint8_t_uint8_t {
   uint8_t t1;
   uint8_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_uint8_t_int8_t {
   int8_t t1;
   uint8_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_uint8_t_uint16_t {
   uint16_t t1;
   uint8_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_uint8_t_int16_t {
   int16_t t1;
   uint8_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_uint8_t_uint32_t {
   uint32_t t1;
   uint8_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_uint8_t_int32_t {
   int32_t t1;
   uint8_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_uint8_t_uint64_t {
   uint64_t t1;
   uint8_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_uint8_t_int64_t {
   int64_t t1;
   uint8_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_uint8_t_float {
   float t1;
   uint8_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_uint8_t_double {
   double t1;
   uint8_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_int8_t_char {
   char t1;
   int8_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_int8_t_void_star {
   void* t1;
   int8_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_int8_t_uint8_t {
   uint8_t t1;
   int8_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_int8_t_int8_t {
   int8_t t1;
   int8_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_int8_t_uint16_t {
   uint16_t t1;
   int8_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_int8_t_int16_t {
   int16_t t1;
   int8_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_int8_t_uint32_t {
   uint32_t t1;
   int8_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_int8_t_int32_t {
   int32_t t1;
   int8_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_int8_t_uint64_t {
   uint64_t t1;
   int8_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_int8_t_int64_t {
   int64_t t1;
   int8_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_int8_t_float {
   float t1;
   int8_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_int8_t_double {
   double t1;
   int8_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_uint16_t_char {
   char t1;
   uint16_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_uint16_t_void_star {
   void* t1;
   uint16_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_uint16_t_uint8_t {
   uint8_t t1;
   uint16_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_uint16_t_int8_t {
   int8_t t1;
   uint16_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_uint16_t_uint16_t {
   uint16_t t1;
   uint16_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_uint16_t_int16_t {
   int16_t t1;
   uint16_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_uint16_t_uint32_t {
   uint32_t t1;
   uint16_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_uint16_t_int32_t {
   int32_t t1;
   uint16_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_uint16_t_uint64_t {
   uint64_t t1;
   uint16_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_uint16_t_int64_t {
   int64_t t1;
   uint16_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_uint16_t_float {
   float t1;
   uint16_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_uint16_t_double {
   double t1;
   uint16_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_int16_t_char {
   char t1;
   int16_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_int16_t_void_star {
   void* t1;
   int16_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_int16_t_uint8_t {
   uint8_t t1;
   int16_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_int16_t_int8_t {
   int8_t t1;
   int16_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_int16_t_uint16_t {
   uint16_t t1;
   int16_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_int16_t_int16_t {
   int16_t t1;
   int16_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_int16_t_uint32_t {
   uint32_t t1;
   int16_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_int16_t_int32_t {
   int32_t t1;
   int16_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_int16_t_uint64_t {
   uint64_t t1;
   int16_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_int16_t_int64_t {
   int64_t t1;
   int16_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_int16_t_float {
   float t1;
   int16_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_int16_t_double {
   double t1;
   int16_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_uint32_t_char {
   char t1;
   uint32_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_uint32_t_void_star {
   void* t1;
   uint32_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_uint32_t_uint8_t {
   uint8_t t1;
   uint32_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_uint32_t_int8_t {
   int8_t t1;
   uint32_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_uint32_t_uint16_t {
   uint16_t t1;
   uint32_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_uint32_t_int16_t {
   int16_t t1;
   uint32_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_uint32_t_uint32_t {
   uint32_t t1;
   uint32_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_uint32_t_int32_t {
   int32_t t1;
   uint32_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_uint32_t_uint64_t {
   uint64_t t1;
   uint32_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_uint32_t_int64_t {
   int64_t t1;
   uint32_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_uint32_t_float {
   float t1;
   uint32_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_uint32_t_double {
   double t1;
   uint32_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_int32_t_char {
   char t1;
   int32_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_int32_t_void_star {
   void* t1;
   int32_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_int32_t_uint8_t {
   uint8_t t1;
   int32_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_int32_t_int8_t {
   int8_t t1;
   int32_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_int32_t_uint16_t {
   uint16_t t1;
   int32_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_int32_t_int16_t {
   int16_t t1;
   int32_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_int32_t_uint32_t {
   uint32_t t1;
   int32_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_int32_t_int32_t {
   int32_t t1;
   int32_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_int32_t_uint64_t {
   uint64_t t1;
   int32_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_int32_t_int64_t {
   int64_t t1;
   int32_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_int32_t_float {
   float t1;
   int32_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_int32_t_double {
   double t1;
   int32_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_uint64_t_char {
   char t1;
   uint64_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_uint64_t_void_star {
   void* t1;
   uint64_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_uint64_t_uint8_t {
   uint8_t t1;
   uint64_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_uint64_t_int8_t {
   int8_t t1;
   uint64_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_uint64_t_uint16_t {
   uint16_t t1;
   uint64_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_uint64_t_int16_t {
   int16_t t1;
   uint64_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_uint64_t_uint32_t {
   uint32_t t1;
   uint64_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_uint64_t_int32_t {
   int32_t t1;
   uint64_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_uint64_t_uint64_t {
   uint64_t t1;
   uint64_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_uint64_t_int64_t {
   int64_t t1;
   uint64_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_uint64_t_float {
   float t1;
   uint64_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_uint64_t_double {
   double t1;
   uint64_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_int64_t_char {
   char t1;
   int64_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_int64_t_void_star {
   void* t1;
   int64_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_int64_t_uint8_t {
   uint8_t t1;
   int64_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_int64_t_int8_t {
   int8_t t1;
   int64_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_int64_t_uint16_t {
   uint16_t t1;
   int64_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_int64_t_int16_t {
   int16_t t1;
   int64_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_int64_t_uint32_t {
   uint32_t t1;
   int64_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_int64_t_int32_t {
   int32_t t1;
   int64_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_int64_t_uint64_t {
   uint64_t t1;
   int64_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_int64_t_int64_t {
   int64_t t1;
   int64_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_int64_t_float {
   float t1;
   int64_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_int64_t_double {
   double t1;
   int64_t t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_float_char {
   char t1;
   float t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_float_void_star {
   void* t1;
   float t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_float_uint8_t {
   uint8_t t1;
   float t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_float_int8_t {
   int8_t t1;
   float t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_float_uint16_t {
   uint16_t t1;
   float t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_float_int16_t {
   int16_t t1;
   float t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_float_uint32_t {
   uint32_t t1;
   float t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_float_int32_t {
   int32_t t1;
   float t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_float_uint64_t {
   uint64_t t1;
   float t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_float_int64_t {
   int64_t t1;
   float t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_float_float {
   float t1;
   float t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_float_double {
   double t1;
   float t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_double_char {
   char t1;
   double t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_double_void_star {
   void* t1;
   double t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_double_uint8_t {
   uint8_t t1;
   double t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_double_int8_t {
   int8_t t1;
   double t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_double_uint16_t {
   uint16_t t1;
   double t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_double_int16_t {
   int16_t t1;
   double t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_double_uint32_t {
   uint32_t t1;
   double t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_double_int32_t {
   int32_t t1;
   double t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_double_uint64_t {
   uint64_t t1;
   double t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_double_int64_t {
   int64_t t1;
   double t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_double_float {
   float t1;
   double t2;
   int32_t t3;
};



struct mdc_tuple3_int32_t_double_double {
   double t1;
   double t2;
   int32_t t3;
};



struct mdc_tuple3_uint64_t_char_char {
   char t1;
   char t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_char_void_star {
   void* t1;
   char t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_char_uint8_t {
   uint8_t t1;
   char t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_char_int8_t {
   int8_t t1;
   char t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_char_uint16_t {
   uint16_t t1;
   char t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_char_int16_t {
   int16_t t1;
   char t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_char_uint32_t {
   uint32_t t1;
   char t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_char_int32_t {
   int32_t t1;
   char t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_char_uint64_t {
   uint64_t t1;
   char t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_char_int64_t {
   int64_t t1;
   char t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_char_float {
   float t1;
   char t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_char_double {
   double t1;
   char t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_void_star_char {
   char t1;
   void* t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_void_star_void_star {
   void* t1;
   void* t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_void_star_uint8_t {
   uint8_t t1;
   void* t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_void_star_int8_t {
   int8_t t1;
   void* t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_void_star_uint16_t {
   uint16_t t1;
   void* t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_void_star_int16_t {
   int16_t t1;
   void* t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_void_star_uint32_t {
   uint32_t t1;
   void* t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_void_star_int32_t {
   int32_t t1;
   void* t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_void_star_uint64_t {
   uint64_t t1;
   void* t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_void_star_int64_t {
   int64_t t1;
   void* t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_void_star_float {
   float t1;
   void* t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_void_star_double {
   double t1;
   void* t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_uint8_t_char {
   char t1;
   uint8_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_uint8_t_void_star {
   void* t1;
   uint8_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_uint8_t_uint8_t {
   uint8_t t1;
   uint8_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_uint8_t_int8_t {
   int8_t t1;
   uint8_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_uint8_t_uint16_t {
   uint16_t t1;
   uint8_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_uint8_t_int16_t {
   int16_t t1;
   uint8_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_uint8_t_uint32_t {
   uint32_t t1;
   uint8_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_uint8_t_int32_t {
   int32_t t1;
   uint8_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_uint8_t_uint64_t {
   uint64_t t1;
   uint8_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_uint8_t_int64_t {
   int64_t t1;
   uint8_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_uint8_t_float {
   float t1;
   uint8_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_uint8_t_double {
   double t1;
   uint8_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_int8_t_char {
   char t1;
   int8_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_int8_t_void_star {
   void* t1;
   int8_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_int8_t_uint8_t {
   uint8_t t1;
   int8_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_int8_t_int8_t {
   int8_t t1;
   int8_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_int8_t_uint16_t {
   uint16_t t1;
   int8_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_int8_t_int16_t {
   int16_t t1;
   int8_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_int8_t_uint32_t {
   uint32_t t1;
   int8_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_int8_t_int32_t {
   int32_t t1;
   int8_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_int8_t_uint64_t {
   uint64_t t1;
   int8_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_int8_t_int64_t {
   int64_t t1;
   int8_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_int8_t_float {
   float t1;
   int8_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_int8_t_double {
   double t1;
   int8_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_uint16_t_char {
   char t1;
   uint16_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_uint16_t_void_star {
   void* t1;
   uint16_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_uint16_t_uint8_t {
   uint8_t t1;
   uint16_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_uint16_t_int8_t {
   int8_t t1;
   uint16_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_uint16_t_uint16_t {
   uint16_t t1;
   uint16_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_uint16_t_int16_t {
   int16_t t1;
   uint16_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_uint16_t_uint32_t {
   uint32_t t1;
   uint16_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_uint16_t_int32_t {
   int32_t t1;
   uint16_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_uint16_t_uint64_t {
   uint64_t t1;
   uint16_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_uint16_t_int64_t {
   int64_t t1;
   uint16_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_uint16_t_float {
   float t1;
   uint16_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_uint16_t_double {
   double t1;
   uint16_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_int16_t_char {
   char t1;
   int16_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_int16_t_void_star {
   void* t1;
   int16_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_int16_t_uint8_t {
   uint8_t t1;
   int16_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_int16_t_int8_t {
   int8_t t1;
   int16_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_int16_t_uint16_t {
   uint16_t t1;
   int16_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_int16_t_int16_t {
   int16_t t1;
   int16_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_int16_t_uint32_t {
   uint32_t t1;
   int16_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_int16_t_int32_t {
   int32_t t1;
   int16_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_int16_t_uint64_t {
   uint64_t t1;
   int16_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_int16_t_int64_t {
   int64_t t1;
   int16_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_int16_t_float {
   float t1;
   int16_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_int16_t_double {
   double t1;
   int16_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_uint32_t_char {
   char t1;
   uint32_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_uint32_t_void_star {
   void* t1;
   uint32_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_uint32_t_uint8_t {
   uint8_t t1;
   uint32_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_uint32_t_int8_t {
   int8_t t1;
   uint32_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_uint32_t_uint16_t {
   uint16_t t1;
   uint32_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_uint32_t_int16_t {
   int16_t t1;
   uint32_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_uint32_t_uint32_t {
   uint32_t t1;
   uint32_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_uint32_t_int32_t {
   int32_t t1;
   uint32_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_uint32_t_uint64_t {
   uint64_t t1;
   uint32_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_uint32_t_int64_t {
   int64_t t1;
   uint32_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_uint32_t_float {
   float t1;
   uint32_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_uint32_t_double {
   double t1;
   uint32_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_int32_t_char {
   char t1;
   int32_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_int32_t_void_star {
   void* t1;
   int32_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_int32_t_uint8_t {
   uint8_t t1;
   int32_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_int32_t_int8_t {
   int8_t t1;
   int32_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_int32_t_uint16_t {
   uint16_t t1;
   int32_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_int32_t_int16_t {
   int16_t t1;
   int32_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_int32_t_uint32_t {
   uint32_t t1;
   int32_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_int32_t_int32_t {
   int32_t t1;
   int32_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_int32_t_uint64_t {
   uint64_t t1;
   int32_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_int32_t_int64_t {
   int64_t t1;
   int32_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_int32_t_float {
   float t1;
   int32_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_int32_t_double {
   double t1;
   int32_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_uint64_t_char {
   char t1;
   uint64_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_uint64_t_void_star {
   void* t1;
   uint64_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_uint64_t_uint8_t {
   uint8_t t1;
   uint64_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_uint64_t_int8_t {
   int8_t t1;
   uint64_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_uint64_t_uint16_t {
   uint16_t t1;
   uint64_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_uint64_t_int16_t {
   int16_t t1;
   uint64_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_uint64_t_uint32_t {
   uint32_t t1;
   uint64_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_uint64_t_int32_t {
   int32_t t1;
   uint64_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_uint64_t_uint64_t {
   uint64_t t1;
   uint64_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_uint64_t_int64_t {
   int64_t t1;
   uint64_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_uint64_t_float {
   float t1;
   uint64_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_uint64_t_double {
   double t1;
   uint64_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_int64_t_char {
   char t1;
   int64_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_int64_t_void_star {
   void* t1;
   int64_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_int64_t_uint8_t {
   uint8_t t1;
   int64_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_int64_t_int8_t {
   int8_t t1;
   int64_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_int64_t_uint16_t {
   uint16_t t1;
   int64_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_int64_t_int16_t {
   int16_t t1;
   int64_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_int64_t_uint32_t {
   uint32_t t1;
   int64_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_int64_t_int32_t {
   int32_t t1;
   int64_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_int64_t_uint64_t {
   uint64_t t1;
   int64_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_int64_t_int64_t {
   int64_t t1;
   int64_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_int64_t_float {
   float t1;
   int64_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_int64_t_double {
   double t1;
   int64_t t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_float_char {
   char t1;
   float t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_float_void_star {
   void* t1;
   float t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_float_uint8_t {
   uint8_t t1;
   float t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_float_int8_t {
   int8_t t1;
   float t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_float_uint16_t {
   uint16_t t1;
   float t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_float_int16_t {
   int16_t t1;
   float t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_float_uint32_t {
   uint32_t t1;
   float t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_float_int32_t {
   int32_t t1;
   float t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_float_uint64_t {
   uint64_t t1;
   float t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_float_int64_t {
   int64_t t1;
   float t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_float_float {
   float t1;
   float t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_float_double {
   double t1;
   float t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_double_char {
   char t1;
   double t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_double_void_star {
   void* t1;
   double t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_double_uint8_t {
   uint8_t t1;
   double t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_double_int8_t {
   int8_t t1;
   double t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_double_uint16_t {
   uint16_t t1;
   double t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_double_int16_t {
   int16_t t1;
   double t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_double_uint32_t {
   uint32_t t1;
   double t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_double_int32_t {
   int32_t t1;
   double t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_double_uint64_t {
   uint64_t t1;
   double t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_double_int64_t {
   int64_t t1;
   double t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_double_float {
   float t1;
   double t2;
   uint64_t t3;
};



struct mdc_tuple3_uint64_t_double_double {
   double t1;
   double t2;
   uint64_t t3;
};



struct mdc_tuple3_int64_t_char_char {
   char t1;
   char t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_char_void_star {
   void* t1;
   char t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_char_uint8_t {
   uint8_t t1;
   char t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_char_int8_t {
   int8_t t1;
   char t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_char_uint16_t {
   uint16_t t1;
   char t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_char_int16_t {
   int16_t t1;
   char t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_char_uint32_t {
   uint32_t t1;
   char t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_char_int32_t {
   int32_t t1;
   char t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_char_uint64_t {
   uint64_t t1;
   char t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_char_int64_t {
   int64_t t1;
   char t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_char_float {
   float t1;
   char t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_char_double {
   double t1;
   char t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_void_star_char {
   char t1;
   void* t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_void_star_void_star {
   void* t1;
   void* t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_void_star_uint8_t {
   uint8_t t1;
   void* t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_void_star_int8_t {
   int8_t t1;
   void* t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_void_star_uint16_t {
   uint16_t t1;
   void* t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_void_star_int16_t {
   int16_t t1;
   void* t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_void_star_uint32_t {
   uint32_t t1;
   void* t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_void_star_int32_t {
   int32_t t1;
   void* t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_void_star_uint64_t {
   uint64_t t1;
   void* t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_void_star_int64_t {
   int64_t t1;
   void* t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_void_star_float {
   float t1;
   void* t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_void_star_double {
   double t1;
   void* t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_uint8_t_char {
   char t1;
   uint8_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_uint8_t_void_star {
   void* t1;
   uint8_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_uint8_t_uint8_t {
   uint8_t t1;
   uint8_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_uint8_t_int8_t {
   int8_t t1;
   uint8_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_uint8_t_uint16_t {
   uint16_t t1;
   uint8_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_uint8_t_int16_t {
   int16_t t1;
   uint8_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_uint8_t_uint32_t {
   uint32_t t1;
   uint8_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_uint8_t_int32_t {
   int32_t t1;
   uint8_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_uint8_t_uint64_t {
   uint64_t t1;
   uint8_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_uint8_t_int64_t {
   int64_t t1;
   uint8_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_uint8_t_float {
   float t1;
   uint8_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_uint8_t_double {
   double t1;
   uint8_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_int8_t_char {
   char t1;
   int8_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_int8_t_void_star {
   void* t1;
   int8_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_int8_t_uint8_t {
   uint8_t t1;
   int8_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_int8_t_int8_t {
   int8_t t1;
   int8_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_int8_t_uint16_t {
   uint16_t t1;
   int8_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_int8_t_int16_t {
   int16_t t1;
   int8_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_int8_t_uint32_t {
   uint32_t t1;
   int8_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_int8_t_int32_t {
   int32_t t1;
   int8_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_int8_t_uint64_t {
   uint64_t t1;
   int8_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_int8_t_int64_t {
   int64_t t1;
   int8_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_int8_t_float {
   float t1;
   int8_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_int8_t_double {
   double t1;
   int8_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_uint16_t_char {
   char t1;
   uint16_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_uint16_t_void_star {
   void* t1;
   uint16_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_uint16_t_uint8_t {
   uint8_t t1;
   uint16_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_uint16_t_int8_t {
   int8_t t1;
   uint16_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_uint16_t_uint16_t {
   uint16_t t1;
   uint16_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_uint16_t_int16_t {
   int16_t t1;
   uint16_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_uint16_t_uint32_t {
   uint32_t t1;
   uint16_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_uint16_t_int32_t {
   int32_t t1;
   uint16_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_uint16_t_uint64_t {
   uint64_t t1;
   uint16_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_uint16_t_int64_t {
   int64_t t1;
   uint16_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_uint16_t_float {
   float t1;
   uint16_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_uint16_t_double {
   double t1;
   uint16_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_int16_t_char {
   char t1;
   int16_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_int16_t_void_star {
   void* t1;
   int16_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_int16_t_uint8_t {
   uint8_t t1;
   int16_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_int16_t_int8_t {
   int8_t t1;
   int16_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_int16_t_uint16_t {
   uint16_t t1;
   int16_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_int16_t_int16_t {
   int16_t t1;
   int16_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_int16_t_uint32_t {
   uint32_t t1;
   int16_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_int16_t_int32_t {
   int32_t t1;
   int16_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_int16_t_uint64_t {
   uint64_t t1;
   int16_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_int16_t_int64_t {
   int64_t t1;
   int16_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_int16_t_float {
   float t1;
   int16_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_int16_t_double {
   double t1;
   int16_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_uint32_t_char {
   char t1;
   uint32_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_uint32_t_void_star {
   void* t1;
   uint32_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_uint32_t_uint8_t {
   uint8_t t1;
   uint32_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_uint32_t_int8_t {
   int8_t t1;
   uint32_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_uint32_t_uint16_t {
   uint16_t t1;
   uint32_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_uint32_t_int16_t {
   int16_t t1;
   uint32_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_uint32_t_uint32_t {
   uint32_t t1;
   uint32_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_uint32_t_int32_t {
   int32_t t1;
   uint32_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_uint32_t_uint64_t {
   uint64_t t1;
   uint32_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_uint32_t_int64_t {
   int64_t t1;
   uint32_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_uint32_t_float {
   float t1;
   uint32_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_uint32_t_double {
   double t1;
   uint32_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_int32_t_char {
   char t1;
   int32_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_int32_t_void_star {
   void* t1;
   int32_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_int32_t_uint8_t {
   uint8_t t1;
   int32_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_int32_t_int8_t {
   int8_t t1;
   int32_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_int32_t_uint16_t {
   uint16_t t1;
   int32_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_int32_t_int16_t {
   int16_t t1;
   int32_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_int32_t_uint32_t {
   uint32_t t1;
   int32_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_int32_t_int32_t {
   int32_t t1;
   int32_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_int32_t_uint64_t {
   uint64_t t1;
   int32_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_int32_t_int64_t {
   int64_t t1;
   int32_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_int32_t_float {
   float t1;
   int32_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_int32_t_double {
   double t1;
   int32_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_uint64_t_char {
   char t1;
   uint64_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_uint64_t_void_star {
   void* t1;
   uint64_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_uint64_t_uint8_t {
   uint8_t t1;
   uint64_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_uint64_t_int8_t {
   int8_t t1;
   uint64_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_uint64_t_uint16_t {
   uint16_t t1;
   uint64_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_uint64_t_int16_t {
   int16_t t1;
   uint64_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_uint64_t_uint32_t {
   uint32_t t1;
   uint64_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_uint64_t_int32_t {
   int32_t t1;
   uint64_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_uint64_t_uint64_t {
   uint64_t t1;
   uint64_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_uint64_t_int64_t {
   int64_t t1;
   uint64_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_uint64_t_float {
   float t1;
   uint64_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_uint64_t_double {
   double t1;
   uint64_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_int64_t_char {
   char t1;
   int64_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_int64_t_void_star {
   void* t1;
   int64_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_int64_t_uint8_t {
   uint8_t t1;
   int64_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_int64_t_int8_t {
   int8_t t1;
   int64_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_int64_t_uint16_t {
   uint16_t t1;
   int64_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_int64_t_int16_t {
   int16_t t1;
   int64_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_int64_t_uint32_t {
   uint32_t t1;
   int64_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_int64_t_int32_t {
   int32_t t1;
   int64_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_int64_t_uint64_t {
   uint64_t t1;
   int64_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_int64_t_int64_t {
   int64_t t1;
   int64_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_int64_t_float {
   float t1;
   int64_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_int64_t_double {
   double t1;
   int64_t t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_float_char {
   char t1;
   float t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_float_void_star {
   void* t1;
   float t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_float_uint8_t {
   uint8_t t1;
   float t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_float_int8_t {
   int8_t t1;
   float t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_float_uint16_t {
   uint16_t t1;
   float t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_float_int16_t {
   int16_t t1;
   float t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_float_uint32_t {
   uint32_t t1;
   float t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_float_int32_t {
   int32_t t1;
   float t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_float_uint64_t {
   uint64_t t1;
   float t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_float_int64_t {
   int64_t t1;
   float t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_float_float {
   float t1;
   float t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_float_double {
   double t1;
   float t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_double_char {
   char t1;
   double t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_double_void_star {
   void* t1;
   double t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_double_uint8_t {
   uint8_t t1;
   double t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_double_int8_t {
   int8_t t1;
   double t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_double_uint16_t {
   uint16_t t1;
   double t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_double_int16_t {
   int16_t t1;
   double t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_double_uint32_t {
   uint32_t t1;
   double t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_double_int32_t {
   int32_t t1;
   double t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_double_uint64_t {
   uint64_t t1;
   double t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_double_int64_t {
   int64_t t1;
   double t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_double_float {
   float t1;
   double t2;
   int64_t t3;
};



struct mdc_tuple3_int64_t_double_double {
   double t1;
   double t2;
   int64_t t3;
};



struct mdc_tuple3_float_char_char {
   char t1;
   char t2;
   float t3;
};



struct mdc_tuple3_float_char_void_star {
   void* t1;
   char t2;
   float t3;
};



struct mdc_tuple3_float_char_uint8_t {
   uint8_t t1;
   char t2;
   float t3;
};



struct mdc_tuple3_float_char_int8_t {
   int8_t t1;
   char t2;
   float t3;
};



struct mdc_tuple3_float_char_uint16_t {
   uint16_t t1;
   char t2;
   float t3;
};



struct mdc_tuple3_float_char_int16_t {
   int16_t t1;
   char t2;
   float t3;
};



struct mdc_tuple3_float_char_uint32_t {
   uint32_t t1;
   char t2;
   float t3;
};



struct mdc_tuple3_float_char_int32_t {
   int32_t t1;
   char t2;
   float t3;
};



struct mdc_tuple3_float_char_uint64_t {
   uint64_t t1;
   char t2;
   float t3;
};



struct mdc_tuple3_float_char_int64_t {
   int64_t t1;
   char t2;
   float t3;
};



struct mdc_tuple3_float_char_float {
   float t1;
   char t2;
   float t3;
};



struct mdc_tuple3_float_char_double {
   double t1;
   char t2;
   float t3;
};



struct mdc_tuple3_float_void_star_char {
   char t1;
   void* t2;
   float t3;
};



struct mdc_tuple3_float_void_star_void_star {
   void* t1;
   void* t2;
   float t3;
};



struct mdc_tuple3_float_void_star_uint8_t {
   uint8_t t1;
   void* t2;
   float t3;
};



struct mdc_tuple3_float_void_star_int8_t {
   int8_t t1;
   void* t2;
   float t3;
};



struct mdc_tuple3_float_void_star_uint16_t {
   uint16_t t1;
   void* t2;
   float t3;
};



struct mdc_tuple3_float_void_star_int16_t {
   int16_t t1;
   void* t2;
   float t3;
};



struct mdc_tuple3_float_void_star_uint32_t {
   uint32_t t1;
   void* t2;
   float t3;
};



struct mdc_tuple3_float_void_star_int32_t {
   int32_t t1;
   void* t2;
   float t3;
};



struct mdc_tuple3_float_void_star_uint64_t {
   uint64_t t1;
   void* t2;
   float t3;
};



struct mdc_tuple3_float_void_star_int64_t {
   int64_t t1;
   void* t2;
   float t3;
};



struct mdc_tuple3_float_void_star_float {
   float t1;
   void* t2;
   float t3;
};



struct mdc_tuple3_float_void_star_double {
   double t1;
   void* t2;
   float t3;
};



struct mdc_tuple3_float_uint8_t_char {
   char t1;
   uint8_t t2;
   float t3;
};



struct mdc_tuple3_float_uint8_t_void_star {
   void* t1;
   uint8_t t2;
   float t3;
};



struct mdc_tuple3_float_uint8_t_uint8_t {
   uint8_t t1;
   uint8_t t2;
   float t3;
};



struct mdc_tuple3_float_uint8_t_int8_t {
   int8_t t1;
   uint8_t t2;
   float t3;
};



struct mdc_tuple3_float_uint8_t_uint16_t {
   uint16_t t1;
   uint8_t t2;
   float t3;
};



struct mdc_tuple3_float_uint8_t_int16_t {
   int16_t t1;
   uint8_t t2;
   float t3;
};



struct mdc_tuple3_float_uint8_t_uint32_t {
   uint32_t t1;
   uint8_t t2;
   float t3;
};



struct mdc_tuple3_float_uint8_t_int32_t {
   int32_t t1;
   uint8_t t2;
   float t3;
};



struct mdc_tuple3_float_uint8_t_uint64_t {
   uint64_t t1;
   uint8_t t2;
   float t3;
};



struct mdc_tuple3_float_uint8_t_int64_t {
   int64_t t1;
   uint8_t t2;
   float t3;
};



struct mdc_tuple3_float_uint8_t_float {
   float t1;
   uint8_t t2;
   float t3;
};



struct mdc_tuple3_float_uint8_t_double {
   double t1;
   uint8_t t2;
   float t3;
};



struct mdc_tuple3_float_int8_t_char {
   char t1;
   int8_t t2;
   float t3;
};



struct mdc_tuple3_float_int8_t_void_star {
   void* t1;
   int8_t t2;
   float t3;
};



struct mdc_tuple3_float_int8_t_uint8_t {
   uint8_t t1;
   int8_t t2;
   float t3;
};



struct mdc_tuple3_float_int8_t_int8_t {
   int8_t t1;
   int8_t t2;
   float t3;
};



struct mdc_tuple3_float_int8_t_uint16_t {
   uint16_t t1;
   int8_t t2;
   float t3;
};



struct mdc_tuple3_float_int8_t_int16_t {
   int16_t t1;
   int8_t t2;
   float t3;
};



struct mdc_tuple3_float_int8_t_uint32_t {
   uint32_t t1;
   int8_t t2;
   float t3;
};



struct mdc_tuple3_float_int8_t_int32_t {
   int32_t t1;
   int8_t t2;
   float t3;
};



struct mdc_tuple3_float_int8_t_uint64_t {
   uint64_t t1;
   int8_t t2;
   float t3;
};



struct mdc_tuple3_float_int8_t_int64_t {
   int64_t t1;
   int8_t t2;
   float t3;
};



struct mdc_tuple3_float_int8_t_float {
   float t1;
   int8_t t2;
   float t3;
};



struct mdc_tuple3_float_int8_t_double {
   double t1;
   int8_t t2;
   float t3;
};



struct mdc_tuple3_float_uint16_t_char {
   char t1;
   uint16_t t2;
   float t3;
};



struct mdc_tuple3_float_uint16_t_void_star {
   void* t1;
   uint16_t t2;
   float t3;
};



struct mdc_tuple3_float_uint16_t_uint8_t {
   uint8_t t1;
   uint16_t t2;
   float t3;
};



struct mdc_tuple3_float_uint16_t_int8_t {
   int8_t t1;
   uint16_t t2;
   float t3;
};



struct mdc_tuple3_float_uint16_t_uint16_t {
   uint16_t t1;
   uint16_t t2;
   float t3;
};



struct mdc_tuple3_float_uint16_t_int16_t {
   int16_t t1;
   uint16_t t2;
   float t3;
};



struct mdc_tuple3_float_uint16_t_uint32_t {
   uint32_t t1;
   uint16_t t2;
   float t3;
};



struct mdc_tuple3_float_uint16_t_int32_t {
   int32_t t1;
   uint16_t t2;
   float t3;
};



struct mdc_tuple3_float_uint16_t_uint64_t {
   uint64_t t1;
   uint16_t t2;
   float t3;
};



struct mdc_tuple3_float_uint16_t_int64_t {
   int64_t t1;
   uint16_t t2;
   float t3;
};



struct mdc_tuple3_float_uint16_t_float {
   float t1;
   uint16_t t2;
   float t3;
};



struct mdc_tuple3_float_uint16_t_double {
   double t1;
   uint16_t t2;
   float t3;
};



struct mdc_tuple3_float_int16_t_char {
   char t1;
   int16_t t2;
   float t3;
};



struct mdc_tuple3_float_int16_t_void_star {
   void* t1;
   int16_t t2;
   float t3;
};



struct mdc_tuple3_float_int16_t_uint8_t {
   uint8_t t1;
   int16_t t2;
   float t3;
};



struct mdc_tuple3_float_int16_t_int8_t {
   int8_t t1;
   int16_t t2;
   float t3;
};



struct mdc_tuple3_float_int16_t_uint16_t {
   uint16_t t1;
   int16_t t2;
   float t3;
};



struct mdc_tuple3_float_int16_t_int16_t {
   int16_t t1;
   int16_t t2;
   float t3;
};



struct mdc_tuple3_float_int16_t_uint32_t {
   uint32_t t1;
   int16_t t2;
   float t3;
};



struct mdc_tuple3_float_int16_t_int32_t {
   int32_t t1;
   int16_t t2;
   float t3;
};



struct mdc_tuple3_float_int16_t_uint64_t {
   uint64_t t1;
   int16_t t2;
   float t3;
};



struct mdc_tuple3_float_int16_t_int64_t {
   int64_t t1;
   int16_t t2;
   float t3;
};



struct mdc_tuple3_float_int16_t_float {
   float t1;
   int16_t t2;
   float t3;
};



struct mdc_tuple3_float_int16_t_double {
   double t1;
   int16_t t2;
   float t3;
};



struct mdc_tuple3_float_uint32_t_char {
   char t1;
   uint32_t t2;
   float t3;
};



struct mdc_tuple3_float_uint32_t_void_star {
   void* t1;
   uint32_t t2;
   float t3;
};



struct mdc_tuple3_float_uint32_t_uint8_t {
   uint8_t t1;
   uint32_t t2;
   float t3;
};



struct mdc_tuple3_float_uint32_t_int8_t {
   int8_t t1;
   uint32_t t2;
   float t3;
};



struct mdc_tuple3_float_uint32_t_uint16_t {
   uint16_t t1;
   uint32_t t2;
   float t3;
};



struct mdc_tuple3_float_uint32_t_int16_t {
   int16_t t1;
   uint32_t t2;
   float t3;
};



struct mdc_tuple3_float_uint32_t_uint32_t {
   uint32_t t1;
   uint32_t t2;
   float t3;
};



struct mdc_tuple3_float_uint32_t_int32_t {
   int32_t t1;
   uint32_t t2;
   float t3;
};



struct mdc_tuple3_float_uint32_t_uint64_t {
   uint64_t t1;
   uint32_t t2;
   float t3;
};



struct mdc_tuple3_float_uint32_t_int64_t {
   int64_t t1;
   uint32_t t2;
   float t3;
};



struct mdc_tuple3_float_uint32_t_float {
   float t1;
   uint32_t t2;
   float t3;
};



struct mdc_tuple3_float_uint32_t_double {
   double t1;
   uint32_t t2;
   float t3;
};



struct mdc_tuple3_float_int32_t_char {
   char t1;
   int32_t t2;
   float t3;
};



struct mdc_tuple3_float_int32_t_void_star {
   void* t1;
   int32_t t2;
   float t3;
};



struct mdc_tuple3_float_int32_t_uint8_t {
   uint8_t t1;
   int32_t t2;
   float t3;
};



struct mdc_tuple3_float_int32_t_int8_t {
   int8_t t1;
   int32_t t2;
   float t3;
};



struct mdc_tuple3_float_int32_t_uint16_t {
   uint16_t t1;
   int32_t t2;
   float t3;
};



struct mdc_tuple3_float_int32_t_int16_t {
   int16_t t1;
   int32_t t2;
   float t3;
};



struct mdc_tuple3_float_int32_t_uint32_t {
   uint32_t t1;
   int32_t t2;
   float t3;
};



struct mdc_tuple3_float_int32_t_int32_t {
   int32_t t1;
   int32_t t2;
   float t3;
};



struct mdc_tuple3_float_int32_t_uint64_t {
   uint64_t t1;
   int32_t t2;
   float t3;
};



struct mdc_tuple3_float_int32_t_int64_t {
   int64_t t1;
   int32_t t2;
   float t3;
};



struct mdc_tuple3_float_int32_t_float {
   float t1;
   int32_t t2;
   float t3;
};



struct mdc_tuple3_float_int32_t_double {
   double t1;
   int32_t t2;
   float t3;
};



struct mdc_tuple3_float_uint64_t_char {
   char t1;
   uint64_t t2;
   float t3;
};



struct mdc_tuple3_float_uint64_t_void_star {
   void* t1;
   uint64_t t2;
   float t3;
};



struct mdc_tuple3_float_uint64_t_uint8_t {
   uint8_t t1;
   uint64_t t2;
   float t3;
};



struct mdc_tuple3_float_uint64_t_int8_t {
   int8_t t1;
   uint64_t t2;
   float t3;
};



struct mdc_tuple3_float_uint64_t_uint16_t {
   uint16_t t1;
   uint64_t t2;
   float t3;
};



struct mdc_tuple3_float_uint64_t_int16_t {
   int16_t t1;
   uint64_t t2;
   float t3;
};



struct mdc_tuple3_float_uint64_t_uint32_t {
   uint32_t t1;
   uint64_t t2;
   float t3;
};



struct mdc_tuple3_float_uint64_t_int32_t {
   int32_t t1;
   uint64_t t2;
   float t3;
};



struct mdc_tuple3_float_uint64_t_uint64_t {
   uint64_t t1;
   uint64_t t2;
   float t3;
};



struct mdc_tuple3_float_uint64_t_int64_t {
   int64_t t1;
   uint64_t t2;
   float t3;
};



struct mdc_tuple3_float_uint64_t_float {
   float t1;
   uint64_t t2;
   float t3;
};



struct mdc_tuple3_float_uint64_t_double {
   double t1;
   uint64_t t2;
   float t3;
};



struct mdc_tuple3_float_int64_t_char {
   char t1;
   int64_t t2;
   float t3;
};



struct mdc_tuple3_float_int64_t_void_star {
   void* t1;
   int64_t t2;
   float t3;
};



struct mdc_tuple3_float_int64_t_uint8_t {
   uint8_t t1;
   int64_t t2;
   float t3;
};



struct mdc_tuple3_float_int64_t_int8_t {
   int8_t t1;
   int64_t t2;
   float t3;
};



struct mdc_tuple3_float_int64_t_uint16_t {
   uint16_t t1;
   int64_t t2;
   float t3;
};



struct mdc_tuple3_float_int64_t_int16_t {
   int16_t t1;
   int64_t t2;
   float t3;
};



struct mdc_tuple3_float_int64_t_uint32_t {
   uint32_t t1;
   int64_t t2;
   float t3;
};



struct mdc_tuple3_float_int64_t_int32_t {
   int32_t t1;
   int64_t t2;
   float t3;
};



struct mdc_tuple3_float_int64_t_uint64_t {
   uint64_t t1;
   int64_t t2;
   float t3;
};



struct mdc_tuple3_float_int64_t_int64_t {
   int64_t t1;
   int64_t t2;
   float t3;
};



struct mdc_tuple3_float_int64_t_float {
   float t1;
   int64_t t2;
   float t3;
};



struct mdc_tuple3_float_int64_t_double {
   double t1;
   int64_t t2;
   float t3;
};



struct mdc_tuple3_float_float_char {
   char t1;
   float t2;
   float t3;
};



struct mdc_tuple3_float_float_void_star {
   void* t1;
   float t2;
   float t3;
};



struct mdc_tuple3_float_float_uint8_t {
   uint8_t t1;
   float t2;
   float t3;
};



struct mdc_tuple3_float_float_int8_t {
   int8_t t1;
   float t2;
   float t3;
};



struct mdc_tuple3_float_float_uint16_t {
   uint16_t t1;
   float t2;
   float t3;
};



struct mdc_tuple3_float_float_int16_t {
   int16_t t1;
   float t2;
   float t3;
};



struct mdc_tuple3_float_float_uint32_t {
   uint32_t t1;
   float t2;
   float t3;
};



struct mdc_tuple3_float_float_int32_t {
   int32_t t1;
   float t2;
   float t3;
};



struct mdc_tuple3_float_float_uint64_t {
   uint64_t t1;
   float t2;
   float t3;
};



struct mdc_tuple3_float_float_int64_t {
   int64_t t1;
   float t2;
   float t3;
};



struct mdc_tuple3_float_float_float {
   float t1;
   float t2;
   float t3;
};



struct mdc_tuple3_float_float_double {
   double t1;
   float t2;
   float t3;
};



struct mdc_tuple3_float_double_char {
   char t1;
   double t2;
   float t3;
};



struct mdc_tuple3_float_double_void_star {
   void* t1;
   double t2;
   float t3;
};



struct mdc_tuple3_float_double_uint8_t {
   uint8_t t1;
   double t2;
   float t3;
};



struct mdc_tuple3_float_double_int8_t {
   int8_t t1;
   double t2;
   float t3;
};



struct mdc_tuple3_float_double_uint16_t {
   uint16_t t1;
   double t2;
   float t3;
};



struct mdc_tuple3_float_double_int16_t {
   int16_t t1;
   double t2;
   float t3;
};



struct mdc_tuple3_float_double_uint32_t {
   uint32_t t1;
   double t2;
   float t3;
};



struct mdc_tuple3_float_double_int32_t {
   int32_t t1;
   double t2;
   float t3;
};



struct mdc_tuple3_float_double_uint64_t {
   uint64_t t1;
   double t2;
   float t3;
};



struct mdc_tuple3_float_double_int64_t {
   int64_t t1;
   double t2;
   float t3;
};



struct mdc_tuple3_float_double_float {
   float t1;
   double t2;
   float t3;
};



struct mdc_tuple3_float_double_double {
   double t1;
   double t2;
   float t3;
};



struct mdc_tuple3_double_char_char {
   char t1;
   char t2;
   double t3;
};



struct mdc_tuple3_double_char_void_star {
   void* t1;
   char t2;
   double t3;
};



struct mdc_tuple3_double_char_uint8_t {
   uint8_t t1;
   char t2;
   double t3;
};



struct mdc_tuple3_double_char_int8_t {
   int8_t t1;
   char t2;
   double t3;
};



struct mdc_tuple3_double_char_uint16_t {
   uint16_t t1;
   char t2;
   double t3;
};



struct mdc_tuple3_double_char_int16_t {
   int16_t t1;
   char t2;
   double t3;
};



struct mdc_tuple3_double_char_uint32_t {
   uint32_t t1;
   char t2;
   double t3;
};



struct mdc_tuple3_double_char_int32_t {
   int32_t t1;
   char t2;
   double t3;
};



struct mdc_tuple3_double_char_uint64_t {
   uint64_t t1;
   char t2;
   double t3;
};



struct mdc_tuple3_double_char_int64_t {
   int64_t t1;
   char t2;
   double t3;
};



struct mdc_tuple3_double_char_float {
   float t1;
   char t2;
   double t3;
};



struct mdc_tuple3_double_char_double {
   double t1;
   char t2;
   double t3;
};



struct mdc_tuple3_double_void_star_char {
   char t1;
   void* t2;
   double t3;
};



struct mdc_tuple3_double_void_star_void_star {
   void* t1;
   void* t2;
   double t3;
};



struct mdc_tuple3_double_void_star_uint8_t {
   uint8_t t1;
   void* t2;
   double t3;
};



struct mdc_tuple3_double_void_star_int8_t {
   int8_t t1;
   void* t2;
   double t3;
};



struct mdc_tuple3_double_void_star_uint16_t {
   uint16_t t1;
   void* t2;
   double t3;
};



struct mdc_tuple3_double_void_star_int16_t {
   int16_t t1;
   void* t2;
   double t3;
};



struct mdc_tuple3_double_void_star_uint32_t {
   uint32_t t1;
   void* t2;
   double t3;
};



struct mdc_tuple3_double_void_star_int32_t {
   int32_t t1;
   void* t2;
   double t3;
};



struct mdc_tuple3_double_void_star_uint64_t {
   uint64_t t1;
   void* t2;
   double t3;
};



struct mdc_tuple3_double_void_star_int64_t {
   int64_t t1;
   void* t2;
   double t3;
};



struct mdc_tuple3_double_void_star_float {
   float t1;
   void* t2;
   double t3;
};



struct mdc_tuple3_double_void_star_double {
   double t1;
   void* t2;
   double t3;
};



struct mdc_tuple3_double_uint8_t_char {
   char t1;
   uint8_t t2;
   double t3;
};



struct mdc_tuple3_double_uint8_t_void_star {
   void* t1;
   uint8_t t2;
   double t3;
};



struct mdc_tuple3_double_uint8_t_uint8_t {
   uint8_t t1;
   uint8_t t2;
   double t3;
};



struct mdc_tuple3_double_uint8_t_int8_t {
   int8_t t1;
   uint8_t t2;
   double t3;
};



struct mdc_tuple3_double_uint8_t_uint16_t {
   uint16_t t1;
   uint8_t t2;
   double t3;
};



struct mdc_tuple3_double_uint8_t_int16_t {
   int16_t t1;
   uint8_t t2;
   double t3;
};



struct mdc_tuple3_double_uint8_t_uint32_t {
   uint32_t t1;
   uint8_t t2;
   double t3;
};



struct mdc_tuple3_double_uint8_t_int32_t {
   int32_t t1;
   uint8_t t2;
   double t3;
};



struct mdc_tuple3_double_uint8_t_uint64_t {
   uint64_t t1;
   uint8_t t2;
   double t3;
};



struct mdc_tuple3_double_uint8_t_int64_t {
   int64_t t1;
   uint8_t t2;
   double t3;
};



struct mdc_tuple3_double_uint8_t_float {
   float t1;
   uint8_t t2;
   double t3;
};



struct mdc_tuple3_double_uint8_t_double {
   double t1;
   uint8_t t2;
   double t3;
};



struct mdc_tuple3_double_int8_t_char {
   char t1;
   int8_t t2;
   double t3;
};



struct mdc_tuple3_double_int8_t_void_star {
   void* t1;
   int8_t t2;
   double t3;
};



struct mdc_tuple3_double_int8_t_uint8_t {
   uint8_t t1;
   int8_t t2;
   double t3;
};



struct mdc_tuple3_double_int8_t_int8_t {
   int8_t t1;
   int8_t t2;
   double t3;
};



struct mdc_tuple3_double_int8_t_uint16_t {
   uint16_t t1;
   int8_t t2;
   double t3;
};



struct mdc_tuple3_double_int8_t_int16_t {
   int16_t t1;
   int8_t t2;
   double t3;
};



struct mdc_tuple3_double_int8_t_uint32_t {
   uint32_t t1;
   int8_t t2;
   double t3;
};



struct mdc_tuple3_double_int8_t_int32_t {
   int32_t t1;
   int8_t t2;
   double t3;
};



struct mdc_tuple3_double_int8_t_uint64_t {
   uint64_t t1;
   int8_t t2;
   double t3;
};



struct mdc_tuple3_double_int8_t_int64_t {
   int64_t t1;
   int8_t t2;
   double t3;
};



struct mdc_tuple3_double_int8_t_float {
   float t1;
   int8_t t2;
   double t3;
};



struct mdc_tuple3_double_int8_t_double {
   double t1;
   int8_t t2;
   double t3;
};



struct mdc_tuple3_double_uint16_t_char {
   char t1;
   uint16_t t2;
   double t3;
};



struct mdc_tuple3_double_uint16_t_void_star {
   void* t1;
   uint16_t t2;
   double t3;
};



struct mdc_tuple3_double_uint16_t_uint8_t {
   uint8_t t1;
   uint16_t t2;
   double t3;
};



struct mdc_tuple3_double_uint16_t_int8_t {
   int8_t t1;
   uint16_t t2;
   double t3;
};



struct mdc_tuple3_double_uint16_t_uint16_t {
   uint16_t t1;
   uint16_t t2;
   double t3;
};



struct mdc_tuple3_double_uint16_t_int16_t {
   int16_t t1;
   uint16_t t2;
   double t3;
};



struct mdc_tuple3_double_uint16_t_uint32_t {
   uint32_t t1;
   uint16_t t2;
   double t3;
};



struct mdc_tuple3_double_uint16_t_int32_t {
   int32_t t1;
   uint16_t t2;
   double t3;
};



struct mdc_tuple3_double_uint16_t_uint64_t {
   uint64_t t1;
   uint16_t t2;
   double t3;
};



struct mdc_tuple3_double_uint16_t_int64_t {
   int64_t t1;
   uint16_t t2;
   double t3;
};



struct mdc_tuple3_double_uint16_t_float {
   float t1;
   uint16_t t2;
   double t3;
};



struct mdc_tuple3_double_uint16_t_double {
   double t1;
   uint16_t t2;
   double t3;
};



struct mdc_tuple3_double_int16_t_char {
   char t1;
   int16_t t2;
   double t3;
};



struct mdc_tuple3_double_int16_t_void_star {
   void* t1;
   int16_t t2;
   double t3;
};



struct mdc_tuple3_double_int16_t_uint8_t {
   uint8_t t1;
   int16_t t2;
   double t3;
};



struct mdc_tuple3_double_int16_t_int8_t {
   int8_t t1;
   int16_t t2;
   double t3;
};



struct mdc_tuple3_double_int16_t_uint16_t {
   uint16_t t1;
   int16_t t2;
   double t3;
};



struct mdc_tuple3_double_int16_t_int16_t {
   int16_t t1;
   int16_t t2;
   double t3;
};



struct mdc_tuple3_double_int16_t_uint32_t {
   uint32_t t1;
   int16_t t2;
   double t3;
};



struct mdc_tuple3_double_int16_t_int32_t {
   int32_t t1;
   int16_t t2;
   double t3;
};



struct mdc_tuple3_double_int16_t_uint64_t {
   uint64_t t1;
   int16_t t2;
   double t3;
};



struct mdc_tuple3_double_int16_t_int64_t {
   int64_t t1;
   int16_t t2;
   double t3;
};



struct mdc_tuple3_double_int16_t_float {
   float t1;
   int16_t t2;
   double t3;
};



struct mdc_tuple3_double_int16_t_double {
   double t1;
   int16_t t2;
   double t3;
};



struct mdc_tuple3_double_uint32_t_char {
   char t1;
   uint32_t t2;
   double t3;
};



struct mdc_tuple3_double_uint32_t_void_star {
   void* t1;
   uint32_t t2;
   double t3;
};



struct mdc_tuple3_double_uint32_t_uint8_t {
   uint8_t t1;
   uint32_t t2;
   double t3;
};



struct mdc_tuple3_double_uint32_t_int8_t {
   int8_t t1;
   uint32_t t2;
   double t3;
};



struct mdc_tuple3_double_uint32_t_uint16_t {
   uint16_t t1;
   uint32_t t2;
   double t3;
};



struct mdc_tuple3_double_uint32_t_int16_t {
   int16_t t1;
   uint32_t t2;
   double t3;
};



struct mdc_tuple3_double_uint32_t_uint32_t {
   uint32_t t1;
   uint32_t t2;
   double t3;
};



struct mdc_tuple3_double_uint32_t_int32_t {
   int32_t t1;
   uint32_t t2;
   double t3;
};



struct mdc_tuple3_double_uint32_t_uint64_t {
   uint64_t t1;
   uint32_t t2;
   double t3;
};



struct mdc_tuple3_double_uint32_t_int64_t {
   int64_t t1;
   uint32_t t2;
   double t3;
};



struct mdc_tuple3_double_uint32_t_float {
   float t1;
   uint32_t t2;
   double t3;
};



struct mdc_tuple3_double_uint32_t_double {
   double t1;
   uint32_t t2;
   double t3;
};



struct mdc_tuple3_double_int32_t_char {
   char t1;
   int32_t t2;
   double t3;
};



struct mdc_tuple3_double_int32_t_void_star {
   void* t1;
   int32_t t2;
   double t3;
};



struct mdc_tuple3_double_int32_t_uint8_t {
   uint8_t t1;
   int32_t t2;
   double t3;
};



struct mdc_tuple3_double_int32_t_int8_t {
   int8_t t1;
   int32_t t2;
   double t3;
};



struct mdc_tuple3_double_int32_t_uint16_t {
   uint16_t t1;
   int32_t t2;
   double t3;
};



struct mdc_tuple3_double_int32_t_int16_t {
   int16_t t1;
   int32_t t2;
   double t3;
};



struct mdc_tuple3_double_int32_t_uint32_t {
   uint32_t t1;
   int32_t t2;
   double t3;
};



struct mdc_tuple3_double_int32_t_int32_t {
   int32_t t1;
   int32_t t2;
   double t3;
};



struct mdc_tuple3_double_int32_t_uint64_t {
   uint64_t t1;
   int32_t t2;
   double t3;
};



struct mdc_tuple3_double_int32_t_int64_t {
   int64_t t1;
   int32_t t2;
   double t3;
};



struct mdc_tuple3_double_int32_t_float {
   float t1;
   int32_t t2;
   double t3;
};



struct mdc_tuple3_double_int32_t_double {
   double t1;
   int32_t t2;
   double t3;
};



struct mdc_tuple3_double_uint64_t_char {
   char t1;
   uint64_t t2;
   double t3;
};



struct mdc_tuple3_double_uint64_t_void_star {
   void* t1;
   uint64_t t2;
   double t3;
};



struct mdc_tuple3_double_uint64_t_uint8_t {
   uint8_t t1;
   uint64_t t2;
   double t3;
};



struct mdc_tuple3_double_uint64_t_int8_t {
   int8_t t1;
   uint64_t t2;
   double t3;
};



struct mdc_tuple3_double_uint64_t_uint16_t {
   uint16_t t1;
   uint64_t t2;
   double t3;
};



struct mdc_tuple3_double_uint64_t_int16_t {
   int16_t t1;
   uint64_t t2;
   double t3;
};



struct mdc_tuple3_double_uint64_t_uint32_t {
   uint32_t t1;
   uint64_t t2;
   double t3;
};



struct mdc_tuple3_double_uint64_t_int32_t {
   int32_t t1;
   uint64_t t2;
   double t3;
};



struct mdc_tuple3_double_uint64_t_uint64_t {
   uint64_t t1;
   uint64_t t2;
   double t3;
};



struct mdc_tuple3_double_uint64_t_int64_t {
   int64_t t1;
   uint64_t t2;
   double t3;
};



struct mdc_tuple3_double_uint64_t_float {
   float t1;
   uint64_t t2;
   double t3;
};



struct mdc_tuple3_double_uint64_t_double {
   double t1;
   uint64_t t2;
   double t3;
};



struct mdc_tuple3_double_int64_t_char {
   char t1;
   int64_t t2;
   double t3;
};



struct mdc_tuple3_double_int64_t_void_star {
   void* t1;
   int64_t t2;
   double t3;
};



struct mdc_tuple3_double_int64_t_uint8_t {
   uint8_t t1;
   int64_t t2;
   double t3;
};



struct mdc_tuple3_double_int64_t_int8_t {
   int8_t t1;
   int64_t t2;
   double t3;
};



struct mdc_tuple3_double_int64_t_uint16_t {
   uint16_t t1;
   int64_t t2;
   double t3;
};



struct mdc_tuple3_double_int64_t_int16_t {
   int16_t t1;
   int64_t t2;
   double t3;
};



struct mdc_tuple3_double_int64_t_uint32_t {
   uint32_t t1;
   int64_t t2;
   double t3;
};



struct mdc_tuple3_double_int64_t_int32_t {
   int32_t t1;
   int64_t t2;
   double t3;
};



struct mdc_tuple3_double_int64_t_uint64_t {
   uint64_t t1;
   int64_t t2;
   double t3;
};



struct mdc_tuple3_double_int64_t_int64_t {
   int64_t t1;
   int64_t t2;
   double t3;
};



struct mdc_tuple3_double_int64_t_float {
   float t1;
   int64_t t2;
   double t3;
};



struct mdc_tuple3_double_int64_t_double {
   double t1;
   int64_t t2;
   double t3;
};



struct mdc_tuple3_double_float_char {
   char t1;
   float t2;
   double t3;
};



struct mdc_tuple3_double_float_void_star {
   void* t1;
   float t2;
   double t3;
};



struct mdc_tuple3_double_float_uint8_t {
   uint8_t t1;
   float t2;
   double t3;
};



struct mdc_tuple3_double_float_int8_t {
   int8_t t1;
   float t2;
   double t3;
};



struct mdc_tuple3_double_float_uint16_t {
   uint16_t t1;
   float t2;
   double t3;
};



struct mdc_tuple3_double_float_int16_t {
   int16_t t1;
   float t2;
   double t3;
};



struct mdc_tuple3_double_float_uint32_t {
   uint32_t t1;
   float t2;
   double t3;
};



struct mdc_tuple3_double_float_int32_t {
   int32_t t1;
   float t2;
   double t3;
};



struct mdc_tuple3_double_float_uint64_t {
   uint64_t t1;
   float t2;
   double t3;
};



struct mdc_tuple3_double_float_int64_t {
   int64_t t1;
   float t2;
   double t3;
};



struct mdc_tuple3_double_float_float {
   float t1;
   float t2;
   double t3;
};



struct mdc_tuple3_double_float_double {
   double t1;
   float t2;
   double t3;
};



struct mdc_tuple3_double_double_char {
   char t1;
   double t2;
   double t3;
};



struct mdc_tuple3_double_double_void_star {
   void* t1;
   double t2;
   double t3;
};



struct mdc_tuple3_double_double_uint8_t {
   uint8_t t1;
   double t2;
   double t3;
};



struct mdc_tuple3_double_double_int8_t {
   int8_t t1;
   double t2;
   double t3;
};



struct mdc_tuple3_double_double_uint16_t {
   uint16_t t1;
   double t2;
   double t3;
};



struct mdc_tuple3_double_double_int16_t {
   int16_t t1;
   double t2;
   double t3;
};



struct mdc_tuple3_double_double_uint32_t {
   uint32_t t1;
   double t2;
   double t3;
};



struct mdc_tuple3_double_double_int32_t {
   int32_t t1;
   double t2;
   double t3;
};



struct mdc_tuple3_double_double_uint64_t {
   uint64_t t1;
   double t2;
   double t3;
};



struct mdc_tuple3_double_double_int64_t {
   int64_t t1;
   double t2;
   double t3;
};



struct mdc_tuple3_double_double_float {
   float t1;
   double t2;
   double t3;
};



struct mdc_tuple3_double_double_double {
   double t1;
   double t2;
   double t3;
};



#endif //MDC_SPAN_G

