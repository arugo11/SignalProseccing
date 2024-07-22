/***
 * @file fft.c
 * @brief FFT(高速フーリエ変換),IFFT(逆高速フーリエ変換)の実装
 * @author argo
 * @date 2024/07/20
 */

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "complex.h"
#include "fft.h"
#include "math_utils.h"

// ビットリバースの関数
int reverse_bit(int num, int m) {
    int res = 0;
    for (int i = 0; i < m; i++) {
        res = (res << 1) | (num & 1);
        num >>= 1;
    }
    return res;
}

// FFTの実装
void fft(const double* input, int input_size, Complex* output) {
    int N = input_size;
    int m = (int)log2(N);

    // メモ化
    Complex* memo = (Complex*)malloc(sizeof(Complex) * (N / 2));
    for (int i = 0; i < N / 2; i++) {
        double vector = -2.0 * Pi * i / N;
        memo[i].re = cos(vector);
        memo[i].im = sin(vector);
    }

    // 実数を複素数に変換
    for (int i = 0; i < N; i++) {
        output[i].re = input[i];
        output[i].im = 0.0;
    }

    // ならびかえ
    for (int i = 0; i < N; i++) {
        int j = reverse_bit(i, m);
        if (i < j) {
            Complex temp = output[i];
            output[i] = output[j];
            output[j] = temp;
        }
    }

    // FFTのメインループ
    for (int s = 1; s <= m; ++s) {
        int m = 1 << s;
        int m2 = m >> 1;
        for (int j = 0; j < m2; ++j) {
            Complex w = memo[N / m * j];
            for (int k = j; k < N; k += m) {
                Complex t = complex_multiply(w, output[k + m2]);
                output[k + m2] = complex_subtract(output[k], t);
                output[k] = complex_add(output[k], t);
            }
        }
    }

    free(memo);
}
void ifft(const Complex* coeffs, int coeffs_size, double* output) 
{
    int N = coeffs_size;
    double omega_conj = 2 * Pi / N;
    double vector;

    for(int n = 0; n < N; n++) {
        output[n] = 0;
        for(int k = 0; k < N; k++) {
            vector = (double)n * (double)k * omega_conj;
            Complex multi;
            multi.re = cos(vector);
            multi.im = sin(vector);
            Complex term = complex_multiply(coeffs[k], multi);
            output[n] += term.re;
        }
        output[n] /= N;
    }
}