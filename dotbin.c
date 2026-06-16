//
// Created by MeowWow520 on 2026/6/14.
//

// dotbin.c shell commands
// -o "output.bin": output .bin file



#include <stdio.h>
#include <stdint.h>
#include <string.h>



#define DEFAULT_OUTPUT_FILE_NAME "output.bin"

int output_file_index = 0;
char* output_file_name = DEFAULT_OUTPUT_FILE_NAME;


uint8_t buffer_uint8[80] = {
    0x00, 0x18, 0x18, 0x1c, 0x18, 0x18, 0x18, 0x7e, 0x00, 0x3c, 0x66, 0x60, 0x30, 0x0c, 0x06, 0x7e, 0x00, 0x3c, 0x66, 0x60,
    0x38, 0x60, 0x66, 0x3c, 0x00, 0x30, 0x38, 0x34, 0x32, 0x7e, 0x30, 0x30, 0x00, 0x7e, 0x06, 0x3e, 0x60, 0x60, 0x66, 0x3c,
    0x00, 0x3c, 0x66, 0x06, 0x3e, 0x66, 0x66, 0x3c, 0x00, 0x7e, 0x66, 0x30, 0x30, 0x18, 0x18, 0x18, 0x00, 0x3c, 0x66, 0x66,
    0x3c, 0x66, 0x66, 0x3c, 0x00, 0x3c, 0x66, 0x66, 0x7c, 0x60, 0x66, 0x3c, 0x00, 0x3c, 0x66, 0x76, 0x6e, 0x66, 0x66, 0x3c
};

void read_argv(const int a, char **b) {
    for (int i = 0; i < a; i++) {
        if (strcmp(b[i], "-o") == 0) output_file_index = i;
    }
};

int main(const int argc, char **argv) {
    printf("Hello Dotbin.c\n");

    if (argc != 1) {
        read_argv(argc, argv);
    }
    if (output_file_index != 0 && argv[output_file_index + 1] != NULL) {
        output_file_name = argv[output_file_index + 1];
        printf("Output file name: %s\n", output_file_name);
    } else {
        printf("Output file name is not provided, using default file name: %s\n", DEFAULT_OUTPUT_FILE_NAME);
    }


    FILE *fp;
    fopen_s(&fp, output_file_name, "wb");
    if (fp == NULL) return 1;
    fwrite(buffer_uint8, sizeof(uint8_t), sizeof(buffer_uint8) / sizeof(buffer_uint8[0]), fp);
    fclose(fp);
    return 0;
}
