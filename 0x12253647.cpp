#include <stdio.h>
#include <stdint.h>

static inline int is_little_endian(void)// 判断本机字节序：1 = 小端，0 = 大端 //
{
    union { uint32_t u; unsigned char c[4]; } v = { 0x01020304 };
    return v.c[0] == 0x04;
}

static inline uint32_t bswap32(uint32_t x)// 通用 32-bit 翻转函数 //
{
    return ((x >> 24) & 0xFFu) |
        ((x >> 8) & 0xFF00u) |
        ((x << 8) & 0xFF0000u) |
        ((x << 24) & 0xFF000000u);
}

static inline uint32_t to_big32(uint32_t v)// 本机 → 大端 //
{
    return is_little_endian() ? bswap32(v) : v;
}

static inline uint32_t to_little32(uint32_t v)// 本机 → 小端 //
{
    return is_little_endian() ? v : bswap32(v);
}

int main(void)
{
    uint32_t val = 0x12253647;

    printf("本机字节序: %s\n", is_little_endian() ? "Little-Endian" : "Big-Endian");
    printf("原始值 (本机): 0x%08X\n", val);
    printf("小端表示   : 0x%08X\n", to_little32(val));
    printf("大端表示   : 0x%08X\n", to_big32(val));

    return 0;
}
