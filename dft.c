/***
 * @file dft.c
 * @brief DFT(離散フーリエ変換),IDFT(逆離散フーリエ変換)の実装
 * @author Argo
 * @date 2024/07/20
 */

#include <stdio.h>
#include <math.h>
#include "math_utils.h"
#include "complex.h"

void dft(const double* input, int input_size, Complex* output)
{
    int N = input_size;
    double omega = -2 * Pi / N;
    double vector;

    for(int k = 0; k < N; k++)
    {
        output[k].re = 0;
        output[k].im = 0;
        for(int n = 0; n < N; n++)
        {
            vector = omega * (double)k * (double)n;
            output[k].re += input[n] * cos(vector);
            output[k].im += input[n] * sin(vector);
        }

    }
}

void idft(const Complex* coeffs, int coeffs_size, double* output) 
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