#include <stdio.h>
#include <stdint.h>

static const char hex_table[16] = {
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'
};

inline static char hex(uint8_t value) { return hex_table[value]; }


void
hexdump(char *restrict out, unsigned char *restrict in, size_t n) {
    size_t j = 0;
    for (size_t i = 0; i < n; i++) {
        uint8_t a = in[i];
        out[j++] = '\\';
        out[j++] = 'x';
        out[j++] = hex(a >> 4);
        out[j++] = hex(a & 0b1111);
    }
}