/**
 * @file signal_filter.c
 * @brief 信号フィルタライブラリ
 * @author Argo
 * @date 2024/07/20
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "signal_filter.h"
#include "dft.h"
#include "fft.h"
#include "complex.h"
#include "math_utils.h"
#include "io_handler.h"


void HPF(double* input, int input_size, int cutoff, double* output) {
    int N = input_size;
    Complex* spectrum = (Complex*)malloc(N * sizeof(Complex));
    // spectrum配列をゼロで初期化
    for (int i = 0; i < N; i++) {
        spectrum[i].re = 0.0;
        spectrum[i].im = 0.0;
    }

    dft(input, N, spectrum);
    
    for (int k = 0; k < N; k++) {
        if (k < cutoff || k > N - cutoff) { 
            spectrum[k].re = 0.0;
            spectrum[k].im = 0.0;
        }
    }

    idft(spectrum, N, output);
    free(spectrum);
}

void LPF(double* input, int input_size, int cutoff, double* output) {
    int N = input_size;
    Complex* spectrum = (Complex*)malloc(N * sizeof(Complex));

    // spectrum配列をゼロで初期化
    for (int i = 0; i < N; i++) {
        spectrum[i].re = 0.0;
        spectrum[i].im = 0.0;
    }

    dft(input, N, spectrum);

    for (int k = 0; k < N; k++) {
        if (k > cutoff && k < N - cutoff) { 
            spectrum[k].re = 0.0;
            spectrum[k].im = 0.0;
        }
    }

    idft(spectrum, N, output);
    free(spectrum);
}

void HPF_A(double* input, int input_size, int cutoff, double amplitude, double* output) {
    int N = input_size;
    Complex* spectrum = (Complex*)malloc(N * sizeof(Complex));

    fft(input, N, spectrum);
    
    for (int k = 0; k < N; k++) {
        if (k < cutoff || k > N - cutoff) { 
            spectrum[k].re *= amplitude;
            spectrum[k].im *= amplitude;
        }
    }

    ifft(spectrum, N, output);
    free(spectrum);
}

void LPF_A(double* input, int input_size, int cutoff, double amplitude, double* output) {
    int N = input_size;
    Complex* spectrum = (Complex*)malloc(N * sizeof(Complex));

    fft(input, N, spectrum);

    for (int k = 0; k < N; k++) {
        if (k > cutoff && k < N - cutoff) { 
            spectrum[k].re *= amplitude;
            spectrum[k].im *= amplitude;
        }
    }

    ifft(spectrum, N, output);
    free(spectrum);
}