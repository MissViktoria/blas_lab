#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define CBLAS_INDEX size_t
#include <stddef.h>

// ========== ПРАВИЛЬНЫЕ РЕАЛИЗАЦИИ ВСЕХ ФУНКЦИЙ ==========

// 1. SAXPY - y = alpha * x + y
void cblas_saxpy(const int n, const float alpha, const float *x, const int incx, float *y, const int incy) {
    for (int i = 0; i < n; i++) {
        y[i * incy] += alpha * x[i * incx];
    }
}

// 2. SCOPY - копирование вектора
void cblas_scopy(const int n, const float *x, const int incx, float *y, const int incy) {
    for (int i = 0; i < n; i++) {
        y[i * incy] = x[i * incx];
    }
}

// 3. SDOT - скалярное произведение
float cblas_sdot(const int n, const float *x, const int incx, const float *y, const int incy) {
    float sum = 0.0f;
    for (int i = 0; i < n; i++) {
        sum += x[i * incx] * y[i * incy];
    }
    return sum;
}

// 4. SNRM2 - евклидова норма
float cblas_snrm2(const int n, const float *x, const int incx) {
    float sum = 0.0f;
    for (int i = 0; i < n; i++) {
        float val = x[i * incx];
        sum += val * val;
    }
    return sqrtf(sum);
}

// 5. ISAMAX - индекс максимального по модулю элемента
CBLAS_INDEX cblas_isamax(const int n, const float *x, const int incx) {
    if (n <= 0) return 0;
    CBLAS_INDEX max_idx = 0;
    float max_val = fabsf(x[0]);
    for (int i = 1; i < n; i++) {
        float val = fabsf(x[i * incx]);
        if (val > max_val) {
            max_val = val;
            max_idx = i;
        }
    }
    return max_idx;
}

// 6. SSWAP - обмен векторов
void cblas_sswap(const int n, float *x, const int incx, float *y, const int incy) {
    for (int i = 0; i < n; i++) {
        float temp = x[i * incx];
        x[i * incx] = y[i * incy];
        y[i * incy] = temp;
    }
}

// 7. DAXPY - y = alpha * x + y (double)
void cblas_daxpy(const int n, const double alpha, const double *x, const int incx, double *y, const int incy) {
    for (int i = 0; i < n; i++) {
        y[i * incy] += alpha * x[i * incx];
    }
}

// 8. DCOPY - копирование вектора (double)
void cblas_dcopy(const int n, const double *x, const int incx, double *y, const int incy) {
    for (int i = 0; i < n; i++) {
        y[i * incy] = x[i * incx];
    }
}

// 9. DDOT - скалярное произведение (double)
double cblas_ddot(const int n, const double *x, const int incx, const double *y, const int incy) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += x[i * incx] * y[i * incy];
    }
    return sum;
}

// 10. DNRM2 - евклидова норма (double)
double cblas_dnrm2(const int n, const double *x, const int incx) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        double val = x[i * incx];
        sum += val * val;
    }
    return sqrt(sum);
}

// 11. IDAMAX - индекс максимального по модулю элемента (double)
CBLAS_INDEX cblas_idamax(const int n, const double *x, const int incx) {
    if (n <= 0) return 0;
    CBLAS_INDEX max_idx = 0;
    double max_val = fabs(x[0]);
    for (int i = 1; i < n; i++) {
        double val = fabs(x[i * incx]);
        if (val > max_val) {
            max_val = val;
            max_idx = i;
        }
    }
    return max_idx;
}

// 12. DSWAP - обмен векторов (double)
void cblas_dswap(const int n, double *x, const int incx, double *y, const int incy) {
    for (int i = 0; i < n; i++) {
        double temp = x[i * incx];
        x[i * incx] = y[i * incy];
        y[i * incy] = temp;
    }
}