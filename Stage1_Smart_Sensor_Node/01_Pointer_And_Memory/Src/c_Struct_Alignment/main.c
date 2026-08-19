#include <stdio.h>
#include <stdint.h>

// 默认对齐结构体（包含编译器自动填充的字节）
typedef struct {
    uint8_t a;   // 1 字节
    uint32_t b;  // 4 字节（在 32 位系统上，前面会被填充 3 个字节）
    uint16_t c;  // 2 字节
} Normal_Struct_t;

// 严格按 1 字节对齐的结构体（无填充）
#pragma pack(1)
typedef struct {
    uint8_t a;   // 1 字节
    uint32_t b;  // 4 字节
    uint16_t c;  // 2 字节
} Packed_Struct_t;
#pragma pack()

int main(void) {
    printf("Size of Normal_Struct_t: %zu bytes\n", sizeof(Normal_Struct_t)); // 通常为 12 字节
    printf("Size of Packed_Struct_t: %zu bytes\n", sizeof(Packed_Struct_t)); // 精确为 7 字节
    return 0;
}