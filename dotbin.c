//
// Created by MeowWow520 on 2026/6/14.
//

// dotbin.c shell commands
// -o "output.bin": output .bin file



#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>



#define DEFAULT_OUTPUT_FILE_NAME "output.bin"

int output_file_index = 0;
char* output_file_name = DEFAULT_OUTPUT_FILE_NAME;



uint8_t buffer_uint8[12] = {
    0xff, 0xfe, 0xfd, 0xfc, 0xfb, 0xfa,
    0xff, 0xef, 0xdf, 0xcf, 0xbf, 0xaf
};

void read_argv(const int a, char **b) {
    for (int i = 0; i < a; i++) {
        if (strcmp(b[i], "-o") == 0) output_file_index = i;
    }
};

int main(const int argc, char **argv) {
    printf("Hello Dotbin.c\n");
    bool markers[argc];
    for (int i = 0; i < argc; i++) {
        markers[i] = false;
    }


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
    fwrite(buffer_uint8, sizeof(uint8_t), 12, fp);
    fclose(fp);
    return 0;
}
