#include <stdio.h>
#include <stdint.h>

int main(void) {
    // Define an 8-byte buffer
    uint8_t buffer[8] = {0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88};
    
    // Pitfall demonstration: type-casting buffer to uint32_t pointer
    uint32_t *p32 = (uint32_t *)buffer;
    printf("p32[0] = 0x%X\n", p32[0]); // Outputs 0x44332211 on little-endian machines
    
    p32++; // Shifts forward by 4 bytes (sizeof(uint32_t))
    printf("After p32++, value = 0x%X\n", *p32); // Points to and outputs 0x88776655
    
    return 0;
}