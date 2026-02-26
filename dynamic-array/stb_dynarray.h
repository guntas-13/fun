/*
thanks to tsoding for introducing to the implementation of this dynamic array - also inspired by stb_ds.h (https://github.com/nothings/stb/blob/master/stb_ds.h)

To use do this before including the header:

#include ...
#include "stb_dynarray.h"
*/

#ifndef STB_DYNARRAY_H
#define STB_DYNARRAY_H

#include <stdlib.h>

typedef struct {
    size_t size;
    size_t capacity;
} Meta;

#define HEADER_SIZE sizeof(Meta)
#define INITIAL_CAPACITY 256

#define _get_header(arr) ((Meta*)(arr) - 1)
#define len_array(arr) (_get_header(arr)->size)

#define push_back(arr, x)                                                       \
    do{                                                                         \
        if (arr == NULL)                                                        \
        {                                                                       \
            Meta* hdr = malloc(HEADER_SIZE + INITIAL_CAPACITY * sizeof(*arr));  \
            hdr->size = 0;                                                      \
            hdr->capacity = INITIAL_CAPACITY;                                   \
            arr = (void*)(hdr + 1);                                             \
        }                                                                       \
        Meta* hdr = _get_header(arr);                                           \
        if (hdr->size >= hdr->capacity)                                         \
        {                                                                       \
            hdr->capacity *= 2;                                                 \
            hdr = realloc(hdr, HEADER_SIZE + hdr->capacity * sizeof(*arr));     \
            arr = (void*)(hdr + 1);                                             \
        }                                                                       \
        arr[hdr->size++] = x;                                                   \
    } while(0)

#define free_array(arr) free(_get_header(arr))


#endif // STB_DYNARRAY_H