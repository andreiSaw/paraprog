#include <string.h>
#include <stdio.h>
#include <immintrin.h>


static const unsigned int hex_table[256] = {
        0x3030785c, 0x3130785c, 0x3230785c, 0x3330785c, 0x3430785c, 0x3530785c, 0x3630785c, 0x3730785c, 0x3830785c,
        0x3930785c, 0x6130785c, 0x6230785c, 0x6330785c, 0x6430785c, 0x6530785c, 0x6630785c, 0x3031785c,
        0x3131785c, 0x3231785c, 0x3331785c, 0x3431785c, 0x3531785c, 0x3631785c, 0x3731785c, 0x3831785c, 0x3931785c,
        0x6131785c, 0x6231785c, 0x6331785c, 0x6431785c, 0x6531785c, 0x6631785c, 0x3032785c, 0x3132785c, 0x3232785c,
        0x3332785c, 0x3432785c, 0x3532785c, 0x3632785c, 0x3732785c, 0x3832785c, 0x3932785c, 0x6132785c, 0x6232785c,
        0x6332785c, 0x6432785c, 0x6532785c, 0x6632785c, 0x3033785c, 0x3133785c, 0x3233785c, 0x3333785c,
        0x3433785c, 0x3533785c, 0x3633785c, 0x3733785c, 0x3833785c, 0x3933785c, 0x6133785c, 0x6233785c, 0x6333785c,
        0x6433785c, 0x6533785c, 0x6633785c, 0x3034785c, 0x3134785c, 0x3234785c, 0x3334785c, 0x3434785c,
        0x3534785c, 0x3634785c, 0x3734785c, 0x3834785c, 0x3934785c, 0x6134785c, 0x6234785c, 0x6334785c, 0x6434785c,
        0x6534785c, 0x6634785c, 0x3035785c, 0x3135785c, 0x3235785c, 0x3335785c, 0x3435785c, 0x3535785c,
        0x3635785c, 0x3735785c, 0x3835785c, 0x3935785c, 0x6135785c, 0x6235785c, 0x6335785c, 0x6435785c, 0x6535785c,
        0x6635785c, 0x3036785c, 0x3136785c, 0x3236785c, 0x3336785c, 0x3436785c, 0x3536785c, 0x3636785c,
        0x3736785c, 0x3836785c, 0x3936785c, 0x6136785c, 0x6236785c, 0x6336785c, 0x6436785c, 0x6536785c, 0x6636785c,
        0x3037785c, 0x3137785c, 0x3237785c, 0x3337785c, 0x3437785c, 0x3537785c, 0x3637785c, 0x3737785c,
        0x3837785c, 0x3937785c, 0x6137785c, 0x6237785c, 0x6337785c, 0x6437785c, 0x6537785c, 0x6637785c, 0x3038785c,
        0x3138785c, 0x3238785c, 0x3338785c, 0x3438785c, 0x3538785c, 0x3638785c, 0x3738785c, 0x3838785c,
        0x3938785c, 0x6138785c, 0x6238785c, 0x6338785c, 0x6438785c, 0x6538785c, 0x6638785c, 0x3039785c, 0x3139785c,
        0x3239785c, 0x3339785c, 0x3439785c, 0x3539785c, 0x3639785c, 0x3739785c, 0x3839785c, 0x3939785c,
        0x6139785c, 0x6239785c, 0x6339785c, 0x6439785c, 0x6539785c, 0x6639785c, 0x3061785c, 0x3161785c, 0x3261785c,
        0x3361785c, 0x3461785c, 0x3561785c, 0x3661785c, 0x3761785c, 0x3861785c, 0x3961785c, 0x6161785c,
        0x6261785c, 0x6361785c, 0x6461785c, 0x6561785c, 0x6661785c, 0x3062785c, 0x3162785c, 0x3262785c, 0x3362785c,
        0x3462785c, 0x3562785c, 0x3662785c, 0x3762785c, 0x3862785c, 0x3962785c, 0x6162785c, 0x6262785c,
        0x6362785c, 0x6462785c, 0x6562785c, 0x6662785c, 0x3063785c, 0x3163785c, 0x3263785c, 0x3363785c, 0x3463785c,
        0x3563785c, 0x3663785c, 0x3763785c, 0x3863785c, 0x3963785c, 0x6163785c, 0x6263785c, 0x6363785c,
        0x6463785c, 0x6563785c, 0x6663785c, 0x3064785c, 0x3164785c, 0x3264785c, 0x3364785c, 0x3464785c, 0x3564785c,
        0x3664785c, 0x3764785c, 0x3864785c, 0x3964785c, 0x6164785c, 0x6264785c, 0x6364785c, 0x6464785c,
        0x6564785c, 0x6664785c, 0x3065785c, 0x3165785c, 0x3265785c, 0x3365785c, 0x3465785c, 0x3565785c, 0x3665785c,
        0x3765785c, 0x3865785c, 0x3965785c, 0x6165785c, 0x6265785c, 0x6365785c, 0x6465785c, 0x6565785c,
        0x6665785c, 0x3066785c, 0x3166785c, 0x3266785c, 0x3366785c, 0x3466785c, 0x3566785c, 0x3666785c, 0x3766785c,
        0x3866785c, 0x3966785c, 0x6166785c, 0x6266785c, 0x6366785c, 0x6466785c, 0x6566785c, 0x6666785c
};

#define HEXR _mm256_setr_epi8(\
            '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f',\
            '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f')

static inline __m256i a2hex(__m128i val) {
    __m256i enlarge = _mm256_cvtepu8_epi16(val);
    __m256i high = _mm256_srli_epi16(enlarge, 4);
    __m256i low = _mm256_slli_epi16(enlarge, 8);
    __m256i bytes = _mm256_or_si256(high, low);
    bytes = _mm256_and_si256(bytes, _mm256_set1_epi8(0x0f));
    bytes = _mm256_shuffle_epi8(HEXR, bytes);
    return bytes;
}

#define ADDX _mm256_set1_epi32(0x785c)

static inline void hex2out(__m256i val, __m256i *__restrict put) {
    __m128i *r = (__m128i *) (&val);
    __m256i bytes1 = _mm256_cvtepu16_epi32(r[0]);
    bytes1 = _mm256_slli_epi32(bytes1, 16);
    _mm256_storeu_si256(&put[0], _mm256_or_si256(ADDX, bytes1));
    __m256i bytes2 = _mm256_cvtepu16_epi32(r[1]);
    bytes2 = _mm256_slli_epi32(bytes2, 16);
    _mm256_storeu_si256(&put[1], _mm256_or_si256(ADDX, bytes2));
}

void hexdump(char *restrict out, unsigned char *restrict in, size_t n) {
    size_t b = n / 8, r = n % 8;
    for (size_t i = 0; i < b; i++) {
        memcpy(&out[(32 * i)], &hex_table[in[8 * i]], 4);
        memcpy(&out[(32 * i) + 4], &hex_table[in[8 * i + 1]], 4);
        memcpy(&out[(32 * i) + 8], &hex_table[in[8 * i + 2]], 4);
        memcpy(&out[(32 * i) + 12], &hex_table[in[8 * i + 3]], 4);
        memcpy(&out[(32 * i) + 16], &hex_table[in[8 * i + 4]], 4);
        memcpy(&out[(32 * i) + 20], &hex_table[in[8 * i + 5]], 4);
        memcpy(&out[(32 * i) + 24], &hex_table[in[8 * i + 6]], 4);
        memcpy(&out[(32 * i) + 28], &hex_table[in[8 * i + 7]], 4);
    }

    for (size_t i = n - r; i < n; i++) {
        memcpy(&out[4 * (i + 0)], &hex_table[in[i + 0]], 4);
    }

}

void hexdump_vec(char *restrict out, unsigned char *restrict in, size_t n) {
    const __m128i *input128 = (const __m128i *) (in);
    __m256i *output256 = (__m256i *) (out);

    unsigned rest = n % 16;
    unsigned n_vect = (n - rest) >> 4;
    for (unsigned int i = 0; i < n_vect; i++) {
        __m128i av = _mm_lddqu_si128(&input128[i]);
        __m256i hex = a2hex(av);
        hex2out(hex, &output256[2 * i]);
    }
    hexdump(out + (n_vect << 5), in + (n_vect << 4), rest);
}