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



void HPF_complex(Complex* input, int input_size, int cutoff, Complex* output) {
    int N = input_size;

    for (int k = 0; k < N; k++) {
        if (k < cutoff || k > N - cutoff) 
        { 
            output[k].re = 0.0;
            output[k].im = 0.0;
        }
        else
        {
            output[k].re = input[k].re;
            output[k].im = input[k].im;
        }
    }
}

void LPF_complex(Complex* input, int input_size, int cutoff, Complex* output) {
    int N = input_size;

    for (int k = 0; k < N; k++) {
        if (k > cutoff && k < N - cutoff) 
        { 
            output[k].re = 0.0;
            output[k].im = 0.0;
        }
        else
        {
            output[k].re = input[k].re;
            output[k].im = input[k].im;
        }
    }
}

void HPF_real(double* input, int input_size, int cutoff, double* output)
{
    for(int i = 0; i < input_size; i++)
    {
        if(i < cutoff)
        {
            output[i] = 0.0;
        }
        else output[i] = input[i];
    }
}

void LPF_real(double* input, int input_size, int cutoff, double* output)
{
    for(int i = 0; i < input_size; i++)
    {
        if(i > cutoff)
        {
            output[i] = 0.0;
        }
        else output[i] = input[i];
    }
}


// void HPF_A(double* input, int input_size, int cutoff, double amplitude, double* output) {
//     int N = input_size;
//     Complex* spectrum = (Complex*)malloc(N * sizeof(Complex));

//     fft(input, N, spectrum);
    
//     for (int k = 0; k < N; k++) {
//         if (k < cutoff || k > N - cutoff) { 
//             spectrum[k].re *= amplitude;
//             spectrum[k].im *= amplitude;
//         }
//     }

//     ifft(spectrum, N, output);
//     free(spectrum);
// }

// void LPF_A(double* input, int input_size, int cutoff, double amplitude, double* output) {
//     int N = input_size;
//     Complex* spectrum = (Complex*)malloc(N * sizeof(Complex));

//     fft(input, N, spectrum);

//     for (int k = 0; k < N; k++) {
//         if (k > cutoff && k < N - cutoff) { 
//             spectrum[k].re *= amplitude;
//             spectrum[k].im *= amplitude;
//         }
//     }

//     ifft(spectrum, N, output);
//     free(spectrum);
// }