#include <stdio.h>
#include <stdint.h>
#include <memory.h>

static const char hex_table[16] = {
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'
};

inline static char hex(uint8_t value) { return hex_table[value]; }


void
encodeHex(char *restrict dest, unsigned char *restrict src, size_t len /* number of src bytes */) {
    size_t j = 0;
    for (size_t i = 0; i < len; i++) {
        uint8_t a = src[i];
        dest[j++] = '\\';
        dest[j++] = 'x';
        dest[j++] = hex(a >> 4);
        dest[j++] = hex(a & 0b1111);
    }
}

unsigned time(char *out, unsigned char *in, size_t n) {
    unsigned t0, t1;
    asm volatile("lfence; rdtsc" : "=a"(t0) : : "edx");
    encodeHex(out, in, n);
    asm volatile("lfence; rdtsc" : "=a"(t1) : : "edx");
    return t1 - t0;
}