//
// Created by MeowWow520 on 2026/6/14.
//
#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    uint8_t *item;
    size_t size;
    size_t capacity;
} uint8_t_array;

typedef struct {
    uint16_t *item;
    size_t size;
    size_t capacity;
} uint16_t_array;

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

uint8_t switch_str_to_uint8_t(char *str) {
    char *endptr;
    uint8_t value = (uint8_t)strtoul(str, &endptr, 0);
    return value;
}


void save_dash_index(
    char **src_argv, int src_argc, uint8_t_array *target) {
    for (int i = 0; i < src_argc; i++) {
        if (src_argv[i][0] == '-')
            arr_push((*target), i)
    }
}

char* read_file_to_string(const char* filename) {
    // open a file witn read mode
    FILE* file = fopen(filename, "r");
    if (!file) return NULL;
    // get file size
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);
    // save file content to buffer
    char* buffer = malloc(file_size + 1);
    if (!buffer) return NULL;
    size_t bytes_read = fread(buffer, 1, file_size, file);
    buffer[bytes_read] = '\0';
    fclose(file);
    return buffer;
}

int main(int argc, char **argv) {
    for (int i = 0; i < 30; i++) {
        if (!i) printf("Hello Dotbin.c\n");
        printf("-");
        if (i == 29) printf("\n");
    }
    // create dach index array: waiting to decete config
    uint8_t_array argv_dash_array = { 0 };
    save_dash_index(argv, argc, &argv_dash_array);
    // source array: read from input file
    uint8_t_array src_array = { 0 };
    // target array: convert from src_array, waiting for write to output file
    uint8_t_array target_array = { 0 };
    // read input file
    char *file_path = "input.txt";
    char *output_file = "output.bin";
    char *file_content = read_file_to_string(file_path);

    // read file content, and add it to src_array
    do {
        size_t file_size = strlen(file_content);
        if (file_size < 4) break;
        char string4_buf[5];
        memcpy(string4_buf, file_content, 4);
        string4_buf[4] = '\0';
        uint8_t uint8_buf = switch_str_to_uint8_t(string4_buf);
        arr_push(src_array, uint8_buf);
        if (file_size <= 6) break;
        file_content += 6;
    } while (1);


    for (int i = 0; i < src_array.size; i++) {
        printf("%d ", src_array.item[i]);
    }



    free(argv_dash_array.item);
    free(src_array.item);
    free(target_array.item);
    return 0;
}



/*
int arr[] = {1, 2, 3, 100, 200};
size_t count = sizeof(arr) / sizeof(arr[0]);
FILE *fp = fopen("numbers.bin", "wb");
if (fp == NULL) return 1;

// 写入整个数组
fwrite(arr, sizeof(int), count, fp);

fclose(fp);
*/
