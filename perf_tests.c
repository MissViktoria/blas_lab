#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bad_cblas.h"

#define N 100000
#define ITERATIONS 10

int main() {
    clock_t start, end;
    double cpu_time_used;
    
    printf("\n=== Performance Tests ===\n");
    
    // Выделяем память
    float *x = (float*)malloc(N * sizeof(float));
    float *y = (float*)malloc(N * sizeof(float));
    
    if (x == NULL || y == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    // Инициализируем
    for (int i = 0; i < N; i++) {
        x[i] = (float)i / N;
        y[i] = 1.0f;
    }
    
    // Тест производительности SAXPY
    start = clock();
    for (int i = 0; i < ITERATIONS; i++) {
        cblas_saxpy(N, 2.5f, x, 1, y, 1);
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("SAXPY (%d итераций, размер %d): %.4f секунд\n", ITERATIONS, N, cpu_time_used);
    
    free(x);
    free(y);
    
    printf("=== Performance Tests Complete ===\n");
    return 0;
}