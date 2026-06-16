//
// Created by MeowWow520 on 2026/6/16.
//
#include <stdint.h>
#include <stdio.h>

#define SPLIT_U64_TO_BYTES_BE(val, out_arr) \
    do { \
        uint64_t _tmp = (val); \
        (out_arr)[0] = (uint8_t)(_tmp >> 56); \
        (out_arr)[1] = (uint8_t)(_tmp >> 48); \
        (out_arr)[2] = (uint8_t)(_tmp >> 40); \
        (out_arr)[3] = (uint8_t)(_tmp >> 32); \
        (out_arr)[4] = (uint8_t)(_tmp >> 24); \
        (out_arr)[5] = (uint8_t)(_tmp >> 16); \
        (out_arr)[6] = (uint8_t)(_tmp >> 8); \
        (out_arr)[7] = (uint8_t)(_tmp); \
    } while(0)

#define SPLIT_U64_TO_BYTES_LE(val, out_arr) \
    do { \
        uint64_t _tmp = (val); \
        (out_arr)[0] = (uint8_t)(_tmp); \
        (out_arr)[1] = (uint8_t)(_tmp >> 8); \
        (out_arr)[2] = (uint8_t)(_tmp >> 16); \
        (out_arr)[3] = (uint8_t)(_tmp >> 24); \
        (out_arr)[4] = (uint8_t)(_tmp >> 32); \
        (out_arr)[5] = (uint8_t)(_tmp >> 40); \
        (out_arr)[6] = (uint8_t)(_tmp >> 48); \
        (out_arr)[7] = (uint8_t)(_tmp >> 56); \
    } while(0)

const uint64_t IMAGES[] = {
    0x7e1818181c181800,
    0x7e060c3060663c00,
    0x3c66603860663c00,
    0x30307e3234383000,
    0x3c6660603e067e00,
    0x3c66663e06663c00,
    0x1818183030667e00,
    0x3c66663c66663c00,
    0x3c66607c66663c00,
    0x3c66666e76663c00
};

const int IMAGES_LEN = sizeof(IMAGES) / sizeof(IMAGES[0]);

int main() {
    uint8_t IMAGES_B[80] = {0};
    for (int i = 0; i < IMAGES_LEN; i++) {
        SPLIT_U64_TO_BYTES_LE(IMAGES[i], &IMAGES_B[i * 8]);
    }
    for (int i = 0; i < IMAGES_LEN * 8; i++) {
        printf("0x%02x, ", IMAGES_B[i]);
    }
    return 0;
}