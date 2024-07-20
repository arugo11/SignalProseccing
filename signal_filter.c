/**
 * @file signal_filter.c
 * @brief 信号フィルタライブラリ
 * @author Argo
 * @date 2024/07/20
 */


#include <stdio.h>
#include <math.h>
#include "signal_filter.h"
#include "dft.h"
#include "complex.h"
#include "math_utils.h"
#include "io_handler.h"


void HPF(double* input, int input_size, int cutoff, double* output) {
    int N = input_size;
    Complex spectrum[N];

    dft(input, N, spectrum);
    
    for (int k = 0; k < N; k++) {
        if (k < cutoff || k > N - cutoff) { 
            spectrum[k].re = 0.0;
            spectrum[k].im = 0.0;
        }
    }

    idft(spectrum, N, output);
}

void LPF(double* input, int input_size, int cutoff, double* output) {
    int N = input_size;
    Complex spectrum[N];

    dft(input, N, spectrum);

    // カットオフ周波数より高い周波数成分を0に設定
    for (int k = 0; k < N; k++) {
        if (k > cutoff && k < N - cutoff) { 
            spectrum[k].re = 0.0;
            spectrum[k].im = 0.0;
        }
    }

    idft(spectrum, N, output);
}