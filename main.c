#include <stdio.h>
#include <stdint.h>
#include <memory.h>

void
hexdump(char *restrict out, unsigned char *restrict in, size_t n) {
    int i;
    for (i = 0; i < n; i += 2) {
        sprintf(&out[4 * i], "\\x%02X", in[i]);
    }
}

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

int main() {
    unsigned char my_str[] = "CYYeI520vDUs5JkwSYL3iLriNVtxrYEuWDqYZzmMTOnOdswHC6llFoDonYLEkDB6NqrI8KIND3Cre5k4nz9jiPzbn8a8g33ecFLUahF757ffci2mWM0ULLaZRDcb0fcVT9AdDRssC97jnkmBU0EvIygExS3J1b2xwatr7Jgyz06mZKeRWPyYUVZIaqNyqEtPdDg88pE9p18mcQfMJwNGHHQz98DuY8jOAM6UhCOw35NFRUHPIwmGZnT2DzLZoiKEnWTXOeMQM9U6NoTcI13pQFfSMgUtY1IoEzsohed58a1BFa2JhyJKN2M9T78Uqt080vbjzelglavAoogWta3PojcDvj4wt8dNXa5703OUNmljuXEXSGKGoGfxCh810VfYxakXXYLwxPYCIYWxdkb5KMOGvY1JDBEikUT2za6SWwofN7lpfy5UGSRBCHJPULvU1RJrYyPCzEExbrpXBy7za08FF2dCZzJsjGHaOY9uedvdWosK0Owpu9S6ncMIxIaVBOc4fc9pZsA7rcVXB1Pu9Kn5ab0XxOfEtVMbtfn2v73Yxko53YYf0RvMgOJVL8zKwcAFoGmtRm0IAmM1kGfjnv9Kgp9aoIs9g7ldedXnv20txMDl2zcBigp98HKd8fnygF3rjeB6dK6Es9reoZytNi1UASZtJwzsuNtsmokL0o8OiBqJO48J6BxDorg5fsfFrlYNdeAnc5oKX6p0Er4kZngypzdUXKOh8gIiR6EMFVIMKL8mi20mjhZAkYsdlzfwJr0Sa4Cl9QtJDth2t1EtEzav612auwkcNYOqgnIvbGLfUhwtzA1V6s6WdlW4PbDNB0JDJSQRQUvN0sI8h83sXjgM78m8O3MF9wbjo01vJawqlRxwivD1RTvQhGv1XvZkIeY4LsZ0LjJsfIrQHRVYkQwBhgas5m535TxXMxMQUNOYA3RxQF99fqBDe2OGgImTJrbZUZNISRcX713AV1tvEZmWtsu4SUsTwpNS2NmYyg0h0gT53SgAZWqIhtEaDV02";
//    unsigned char my_str[]="Hello World";
    size_t n = 1024;
    char out[4 * n + 1];
    encodeHex(out, my_str, n);
    printf("%s\n", out);
//    printf("%d\n", time(out, my_str, n));
    return 0;
}
