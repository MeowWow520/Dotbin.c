//
// Created by MeowWow520 on 2026/6/14.
//
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    uint8_t *item;
    size_t size;
    size_t capacity;
} uint8_t_array;


#define arr_push(array, i)                                   \
        do {                                                 \
            if (array.size >= array.capacity) {              \
                if (array.capacity == 0) array.capacity = 8; \
                    array.capacity *= 2;                     \
                    array.item = realloc(array.item,         \
                        array.capacity*sizeof(uint8_t));     \
                        assert(array.item != NULL);          \
            }                                                \
            array.item[array.size++] = i;                    \
        } while (0);




void insert_uint8_t_to_array(
    uint8_t_array *array, size_t index, uint8_t value) {
    array->item[index] = value;
}

void insert_uint16_t_to_array(
    uint8_t_array *array, size_t index, uint16_t value) {
    array->item[index] = value;
}

void save_dash_index(
    char **src_argv, int src_argc, uint8_t_array *target) {
    for (int i = 0; i < src_argc; i++) {
        if (src_argv[i][0] == '-')
            arr_push((*target), i)
    }
}

int main(const int argc, char **argv) {
    printf("Hello Dotbin.c\n");
    printf("-------------------------\n");
    uint8_t_array argc_dash_array = { 0 };
    save_dash_index(argv, argc, &argc_dash_array);

    free(argc_dash_array.item);
    return 0;
}
