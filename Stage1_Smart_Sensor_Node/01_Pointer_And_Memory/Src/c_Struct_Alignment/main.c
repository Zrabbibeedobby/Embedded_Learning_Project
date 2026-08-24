#include <stdio.h>
#include <stdint.h>

// Default alignment struct (contains padding bytes)
typedef struct {
    uint8_t a;   // 1 byte
    uint32_t b;  // 4 bytes (preceded by 3 padding bytes on 32-bit systems)
    uint16_t c;  // 2 bytes
} Normal_Struct_t;

// Strict 1-byte alignment struct (no padding)
#pragma pack(1)
typedef struct {
    uint8_t a;   // 1 byte
    uint32_t b;  // 4 bytes
    uint16_t c;  // 2 bytes
} Packed_Struct_t;
#pragma pack()

int main(void) {
    printf("Size of Normal_Struct_t: %zu bytes\n", sizeof(Normal_Struct_t)); // Usually 12 bytes
    printf("Size of Packed_Struct_t: %zu bytes\n", sizeof(Packed_Struct_t)); // Exactly 7 bytes
    return 0;
}