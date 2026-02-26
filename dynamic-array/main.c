#include <stdio.h>

#include "stb_dynarray.h"

int main()
{
    int* arr = NULL;
    push_back(arr, 13);
    push_back(arr, 565);
    push_back(arr, 69);
    push_back(arr, 145);
    push_back(arr, 464);
    push_back(arr, 675);
    push_back(arr, -455);
    printf("Length of integer array: %zu\n", len_array(arr));
    for (size_t i = 0; i < len_array(arr); i++)
    {
        printf("[%zu]: %d\n", i, arr[i]);
    }
    free_array(arr);

    float* arr2 = NULL;
    push_back(arr2, 13.5f);
    push_back(arr2, 565.0f);
    push_back(arr2, 69.0f);
    push_back(arr2, 145.0f);
    push_back(arr2, 464.0f);
    push_back(arr2, 675.0f);
    push_back(arr2, -455.0f);
    printf("Length of float array: %zu\n", len_array(arr2));
    for (size_t i = 0; i < len_array(arr2); i++)
    {
        printf("[%zu]: %f\n", i, arr2[i]);
    }
    free_array(arr2);

    char** arr3 = NULL;
    push_back(arr3, "Hello");
    push_back(arr3, "World");
    printf("Length of string array: %zu\n", len_array(arr3));
    for (size_t i = 0; i < len_array(arr3); i++)
    {
        printf("[%zu]: %s\n", i, arr3[i]);
    }
    free_array(arr3);
    return 0;
}