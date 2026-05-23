#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define CBLAS_INDEX size_t
#include <stddef.h>

// ========== НАМЕРЕННО НЕПРАВИЛЬНЫЕ РЕАЛИЗАЦИИ ==========

// 1. SAXPY - возвращает нули
void cblas_saxpy(const int n, const float alpha, const float *x, const int incx, float *y, const int incy) {
    for (int i = 0; i < n; i++) {
        y[i * incy] = 0.0f;  // ОШИБКА: должно быть y += alpha*x
    }
}

// 2. SCOPY - копирует только первый элемент
void cblas_scopy(const int n, const float *x, const int incx, float *y, const int incy) {
    if (n > 0) {
        y[0] = x[0];  // ОШИБКА: копирует только первый
    }
}

// 3. SDOT - всегда возвращает 0
float cblas_sdot(const int n, const float *x, const int incx, const float *y, const int incy) {
    return 0.0f;  // ОШИБКА: должно быть скалярное произведение
}

// 4. SNRM2 - всегда возвращает 1
float cblas_snrm2(const int n, const float *x, const int incx) {
    return 1.0f;  // ОШИБКА: должна быть норма
}

// 5. ISAMAX - всегда возвращает 0
CBLAS_INDEX cblas_isamax(const int n, const float *x, const int incx) {
    return 0;  // ОШИБКА: должен быть индекс максимума
}

// 6. SSWAP - ничего не делает
void cblas_sswap(const int n, float *x, const int incx, float *y, const int incy) {
    // ОШИБКА: ничего не меняет
}

// 7. DAXPY - возвращает только alpha
void cblas_daxpy(const int n, const double alpha, const double *x, const int incx, double *y, const int incy) {
    for (int i = 0; i < n; i++) {
        y[i * incy] = alpha;  // ОШИБКА: должно быть alpha*x + y
    }
}

// 8. DCOPY - копирует со сдвигом
void cblas_dcopy(const int n, const double *x, const int incx, double *y, const int incy) {
    for (int i = 0; i < n - 1; i++) {
        y[(i + 1) * incy] = x[i * incx];  // ОШИБКА: сдвиг на 1
    }
}

// 9. DDOT - всегда возвращает 42
double cblas_ddot(const int n, const double *x, const int incx, const double *y, const int incy) {
    return 42.0;  // ОШИБКА: всегда 42
}

// 10. DNRM2 - всегда возвращает 2
double cblas_dnrm2(const int n, const double *x, const int incx) {
    return 2.0;  // ОШИБКА: всегда 2
}

// 11. IDAMAX - возвращает последний индекс
CBLAS_INDEX cblas_idamax(const int n, const double *x, const int incx) {
    return n - 1;  // ОШИБКА: должен быть индекс максимума
}

// 12. DSWAP - меняет только первый элемент
void cblas_dswap(const int n, double *x, const int incx, double *y, const int incy) {
    if (n > 0) {
        double temp = x[0];
        x[0] = y[0];
        y[0] = temp;  // ОШИБКА: меняет только первый
    }
}