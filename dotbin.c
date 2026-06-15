//
// Created by MeowWow520 on 2026/6/14.
//

// dotbin.c shell commands
// -o "output.bin": output .bin file
// -i "input.bin" : change format


#include <stdio.h>
#include <stdint.h>
#include <limits.h>



uint8_t buffer_uint8[12] = {
    0xff, 0xfe, 0xfd, 0xfc, 0xfb, 0xfa,
    0xff, 0xef, 0xdf, 0xcf, 0xbf, 0xaf
};
int main(int argc, char **argv) {
    printf("Hello Dotbin.c\n");
    FILE *fp = fopen("numbers.bin", "wb");
    if (fp == NULL) return 1;
    fwrite(buffer_uint8, sizeof(uint8_t), 12, fp);
    fclose(fp);
    return 0;
}
