#include <stdio.h>
#include <stdlib.h>

int global_var = 10; // 存放在全局/静态区

void test_memory_layout(void) {
    int stack_var = 20; // 存放在栈区
    int *heap_var = (int *)malloc(sizeof(int)); // 存放在堆区
    *heap_var = 30;

    printf("Stack variable address: %p\n", (void *)&stack_var);
    printf("Heap variable address:  %p\n", (void *)heap_var);
    printf("Global variable address:%p\n", (void *)&global_var);

    // 释放堆内存并置空，防止变成悬空指针
    free(heap_var);
    heap_var = NULL; 
}

int main(void) {
    test_memory_layout();
    return 0;
}