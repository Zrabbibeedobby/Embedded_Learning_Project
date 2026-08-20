#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

// Buffer size can be customized freely, e.g., 5
#define RING_BUFFER_SIZE 5 

typedef struct {
    uint8_t buffer[RING_BUFFER_SIZE];
    uint16_t head;  // Write pointer
    uint16_t tail;  // Read pointer
    uint16_t count; // Current number of valid items (what you see is what you get)
} CustomRingBuffer_t;

// 1. Push data into the buffer
bool CustomRingBuffer_Push(CustomRingBuffer_t *rb, uint8_t data) {
    // Check counter: reject if full
    if (rb->count >= RING_BUFFER_SIZE) {
        return false; 
    }

    rb->buffer[rb->head] = data;
    rb->head = (rb->head + 1) % RING_BUFFER_SIZE; // Standard modulo wrap-around, safe and reliable
    rb->count++; // Increment count
    return true;
}

// 2. Pop data out of the buffer
bool CustomRingBuffer_Pop(CustomRingBuffer_t *rb, uint8_t *data) {
    // Check counter: nothing to read if empty
    if (rb->count == 0) {
        return false; 
    }

    *data = rb->buffer[rb->tail];
    rb->tail = (rb->tail + 1) % RING_BUFFER_SIZE;
    rb->count--; // Decrement count
    return true;
}

int main(void) {
    CustomRingBuffer_t my_rb = {0};
    uint8_t val = 0;

    printf("=== Custom Size (5) with Counter Test ===\n");
    
    // Fill up all 5 slots
    printf("Push A: %s\n", CustomRingBuffer_Push(&my_rb, 'A') ? "Success" : "Full");
    printf("Push B: %s\n", CustomRingBuffer_Push(&my_rb, 'B') ? "Success" : "Full");
    printf("Push C: %s\n", CustomRingBuffer_Push(&my_rb, 'C') ? "Success" : "Full");
    printf("Push D: %s\n", CustomRingBuffer_Push(&my_rb, 'D') ? "Success" : "Full");
    printf("Push E: %s\n", CustomRingBuffer_Push(&my_rb, 'E') ? "Success" : "Full");
    
    // The 6th push should report Full
    printf("Push F (Should be Full): %s\n", CustomRingBuffer_Push(&my_rb, 'F') ? "Success" : "Full");

    // Pop one item out
    if (CustomRingBuffer_Pop(&my_rb, &val)) {
        printf("\nPopped one: %c\n", val);
    }

    // After making space, pushing 'F' should succeed now!
    printf("Push F again (After Pop): %s\n", CustomRingBuffer_Push(&my_rb, 'F') ? "Success" : "Full");

    return 0;
}