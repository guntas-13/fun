#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    size_t size;
    size_t capacity;
} Meta;

/*
[Header][int][int][int]...[int]
    ^       ^
    |       |
    |       +---> array elements start here
    +---> header starts here
Pointer arithmetic: hdr + 1 -> hdr + sizeof(Meta) -> points to the first int element

[Header][int][int][int]...[int]
    ^       ^
    |       |
    |       +---> if we are here
    +---> and wish to go back by sizeof(Meta) then cast to Meta* and subtract 1
*/

void* init_array(size_t initial_capacity)
{
    Meta* hdr = malloc(sizeof(Meta) + initial_capacity * sizeof(int));
    hdr->size = 0;
    hdr->capacity = initial_capacity;
    return (void*)(hdr + 1); 
}

size_t len_array(int* arr)
{
    Meta* hdr = (Meta*)arr - 1;
    return hdr->size;
}

void push_back(int* arr, int x)
{
    Meta* hdr = (Meta*)arr - 1;
    // will need to check if capacity has exceeded or not
    arr[hdr->size++] = x;
}

void free_array(void* arr)
{
    Meta* hdr = (Meta*)arr - 1;
    free(hdr);
}

int main()
{
    int* arr = init_array(10);
    int init_capacity = 10;
    push_back(arr, 42);
    push_back(arr, 99);
    push_back(arr, 123);
    push_back(arr, 2434);
    push_back(arr, 244);
    push_back(arr, 344);
    push_back(arr, 34);
    for (size_t i = 0; i < len_array(arr); i++) {
        printf("[%zu]: %d\n", i, arr[i]);
    }
    free_array(arr);

    return 0;
}