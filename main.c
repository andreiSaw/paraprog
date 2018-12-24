#include <printf.h>
#include "hex.c"

int main() {
//    unsigned char in[] = "CYYeI520vDUs5JkwSYL3iLriNVtxrYEuWDqYZzmMTOnOdswHC6llFoDonYLEkDB6NqrI8KIND3Cre5k4nz9jiPzbn8a8g33ecFLUahF757ffci2mWM0ULLaZRDcb0fcVT9AdDRssC97jnkmBU0EvIygExS3J1b2xwatr7Jgyz06mZKeRWPyYUVZIaqNyqEtPdDg88pE9p18mcQfMJwNGHHQz98DuY8jOAM6UhCOw35NFRUHPIwmGZnT2DzLZoiKEnWTXOeMQM9U6NoTcI13pQFfSMgUtY1IoEzsohed58a1BFa2JhyJKN2M9T78Uqt080vbjzelglavAoogWta3PojcDvj4wt8dNXa5703OUNmljuXEXSGKGoGfxCh810VfYxakXXYLwxPYCIYWxdkb5KMOGvY1JDBEikUT2za6SWwofN7lpfy5UGSRBCHJPULvU1RJrYyPCzEExbrpXBy7za08FF2dCZzJsjGHaOY9uedvdWosK0Owpu9S6ncMIxIaVBOc4fc9pZsA7rcVXB1Pu9Kn5ab0XxOfEtVMbtfn2v73Yxko53YYf0RvMgOJVL8zKwcAFoGmtRm0IAmM1kGfjnv9Kgp9aoIs9g7ldedXnv20txMDl2zcBigp98HKd8fnygF3rjeB6dK6Es9reoZytNi1UASZtJwzsuNtsmokL0o8OiBqJO48J6BxDorg5fsfFrlYNdeAnc5oKX6p0Er4kZngypzdUXKOh8gIiR6EMFVIMKL8mi20mjhZAkYsdlzfwJr0Sa4Cl9QtJDth2t1EtEzav612auwkcNYOqgnIvbGLfUhwtzA1V6s6WdlW4PbDNB0JDJSQRQUvN0sI8h83sXjgM78m8O3MF9wbjo01vJawqlRxwivD1RTvQhGv1XvZkIeY4LsZ0LjJsfIrQHRVYkQwBhgas5m535TxXMxMQUNOYA3RxQF99fqBDe2OGgImTJrbZUZNISRcX713AV1tvEZmWtsu4SUsTwpNS2NmYyg0h0gT53SgAZWqIhtEaDV02";
    unsigned char in[] = "Hello World";
    size_t n = 1024;
    char out[4 * n];
    unsigned t0, t1;
    asm volatile("lfence; rdtsc" : "=a"(t0) : : "edx");
    hexdump_vec(out, in, n);
    asm volatile("lfence; rdtsc" : "=a"(t1) : : "edx");
    printf("%d\n", t1 - t0);
    printf("%s\n", out);
    return 0;
}