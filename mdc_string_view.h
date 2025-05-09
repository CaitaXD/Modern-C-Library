#ifndef MDC_STRING_VIEW_H
#define MDC_STRING_VIEW_H

#define MDC_SV_API static inline
#include <assert.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>

typedef struct mdc_const_string_view {
    size_t length;
    const char *data;
} mdc_const_string_view_t, MdcConstStringView;

typedef struct mdc_string_view {
    union {
        struct {
            size_t length;
            char *data;
        };
        struct mdc_const_string_view as_const;
    };
} mdc_string_view_t, MdcStringView;

#define MDC_SV(X) ((struct mdc_const_string_view){.data = X, .length = sizeof(X) - 1})
#define MDC_SV_BUFFER(SIZE) ((struct mdc_string_view){.data = (char[SIZE]){}, .length = SIZE})

#if !defined(MDC_STRING_VIEW_NO_SHORT_NAMES)
    typedef mdc_string_view_t string_view_t;
    typedef MdcStringView StringView;
    typedef mdc_const_string_view_t const_string_view_t;
    typedef MdcConstStringView ConstStringView;
    #define SV_BUFFER MDC_SV_BUFFER
    #define SV MDC_SV
    #define sv_slice mdc_sv_slice
    #define sv_slice_const mdc_sv_slice_const
    #define sv_not_found mdc_sv_not_found
#endif

#if !defined(mdc_sv_not_found)
#   if defined(__STDC_VERSION__ ) && (__STDC_VERSION__ >= 202000L)
    constexpr size_t mdc_sv_not_found = SIZE_MAX;
#   else
#   define mdc_sv_not_found SIZE_MAX
#   endif
#endif

MDC_SV_API size_t mdc_sv_index_of(const_string_view_t string, const_string_view_t needle);
MDC_SV_API string_view_t mdc_sv_slice(string_view_t string, size_t offset, size_t count);
MDC_SV_API string_view_t mdc_sv_from_cstr(char *cstr);
MDC_SV_API string_view_t mdc_sv_replace(const_string_view_t str, const_string_view_t find, const_string_view_t replace, string_view_t memory);
MDC_SV_API string_view_t mdc_sv_clone(const_string_view_t string, string_view_t memory);
MDC_SV_API string_view_t mdc_sv_format(char const *format, string_view_t memory, ...);
MDC_SV_API string_view_t mdc_sv_trim_left(string_view_t string);
MDC_SV_API string_view_t mdc_sv_trim_right(string_view_t string);
MDC_SV_API string_view_t mdc_sv_trim(string_view_t string);

MDC_SV_API const_string_view_t mdc_sv_slice_const(const_string_view_t string, size_t offset, size_t count);
MDC_SV_API const_string_view_t mdc_sv_trim_left_const(const_string_view_t string);
MDC_SV_API const_string_view_t mdc_sv_trim_right_const(const_string_view_t string);
MDC_SV_API const_string_view_t mdc_sv_trim_const(const_string_view_t string);

#if defined(MDC_STRING_VIEW_IMPLEMENTATION)

size_t mdc_sv_index_of(const const_string_view_t string, const const_string_view_t needle) {
    extern char *strstr(const char *_haystack, const char *_needle);

    if (string.length < needle.length) {
        return mdc_sv_not_found;
    }
    const char *p = strstr(string.data, needle.data);
    if (p == NULL) {
        return mdc_sv_not_found;
    }
    const size_t index = p - string.data;
    if (index > string.length) {
        return mdc_sv_not_found;
    }
    return index;
}

struct mdc_string_view mdc_sv_slice(const struct mdc_string_view string, const size_t offset, const size_t count) {
    return (mdc_string_view_t) {
        .data = string.data + offset,
        .length = count
    };
}

struct mdc_const_string_view mdc_sv_slice_const(const struct mdc_const_string_view string, const size_t offset, const size_t count) {
    return (mdc_const_string_view_t) {
        .data = string.data + offset,
        .length = count
    };
}

struct mdc_string_view mdc_sv_from_cstr(char *cstr) {
    extern size_t strlen(const char *s);
    return (mdc_string_view_t) {
        .data = cstr,
        .length = strlen(cstr)
    };
}

struct mdc_string_view mdc_sv_clone(const const_string_view_t string, const struct mdc_string_view memory) {
    const struct mdc_string_view result = {
        .data = memory.data,
        .length = string.length
    };
    strncpy(result.data, string.data, string.length);
    return result;
}

struct mdc_string_view mdc_sv_replace(struct mdc_const_string_view str, const struct mdc_const_string_view find, const struct mdc_const_string_view replace, const struct mdc_string_view memory) {
    ssize_t result_length = 0;
    while (true) {
        const ssize_t index = mdc_sv_index_of(str, find);
        if (index == mdc_sv_not_found) {
            strncpy(memory.data + result_length, str.data, str.length);
            result_length += str.length;
            break;
        }

        strncpy(memory.data + result_length, str.data, index);
        result_length += index;

        strncpy(memory.data + result_length, replace.data, replace.length);
        result_length += replace.length;

        str.data += index + find.length;
        str.length -= index + find.length;
    }
    return mdc_sv_slice(memory, 0, result_length);
}

#include <stdarg.h>

struct mdc_string_view mdc_sv_format(char const *format, const struct mdc_string_view memory, ...) {
    extern int snprintf(char *str, size_t size, const char *_format, ...);
    va_list args;
    va_start(args, memory);
    const int result = vsnprintf(memory.data, memory.length, format, args);
    va_end(args);
    if (result < 0) return (mdc_string_view_t){};
    return mdc_sv_slice(memory, 0, result);
}

const_string_view_t mdc_sv_trim_left_const(const const_string_view_t string) {
    ssize_t index = 0;
    while (index < string.length) {
        if (string.data[index] == ' ' || string.data[index] == '\t' || string.data[index] == '\n') {
            index++;
        } else {
            break;
        }
    }
    return mdc_sv_slice_const(string, index, string.length - index);
}

const_string_view_t mdc_sv_trim_right_const(const const_string_view_t string) {
    ssize_t index = string.length - 1;
    while (index >= 0) {
        if (string.data[index] == ' ' || string.data[index] == '\t' || string.data[index] == '\n') {
            index--;
        } else {
            break;
        }
    }
    if (index < 0) return (const_string_view_t){};
    return mdc_sv_slice_const(string, 0, index + 1);
}

const_string_view_t mdc_sv_trim_const(const const_string_view_t string) {
    return mdc_sv_trim_left_const(mdc_sv_trim_right_const(string));
}

string_view_t mdc_sv_trim_left(const string_view_t string) {
    const const_string_view_t result = mdc_sv_trim_const(string.as_const);
    return (string_view_t){
        .data = (void*)result.data,
        .length = result.length
    };
}

string_view_t mdc_sv_trim_right(const string_view_t string) {
    const const_string_view_t result = mdc_sv_trim_right_const(string.as_const);
    return (string_view_t){
        .data = (void*)result.data,
        .length = result.length
    };
}

string_view_t mdc_sv_trim(const string_view_t string) {
    return mdc_sv_trim_left(mdc_sv_trim_right(string));
}

char *mdc_sv_to_cstr_malloc(const const_string_view_t string) {
    extern void *malloc(size_t size);
    char *result = malloc(string.length + 1);
    strncpy(result, string.data, string.length);
    result[string.length] = '\0';
    return result;
}

#endif //MDC_STRING_VIEW_IMPLEMENTATION

#endif //MDC_STRING_VIEW_H
