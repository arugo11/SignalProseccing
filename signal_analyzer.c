/**
 * @file signal_analysis.c
 * @brief 信号解析ライブラリの実装
 * @author Argo
 * @date 2024/07/20
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "complex.h"
#include "signal_analyzer.h"
#include "dft.h"


double calculate_main_frequency(double* input, int sample_count, double sampling_freq)
    {
    Complex* output = malloc(sample_count * sizeof(Complex));

    // DFTを適用
    dft(input, sample_count, output);

    // 最大振幅を持つ周波数成分を見つける
    int max_index = 0;
    double max_magnitude = 0;
    for (int i = 1; i < sample_count/2; i++) {  // ナイキスト周波数
        double magnitude = sqrt(output[i].re * output[i].re + output[i].im * output[i].im);
        if (magnitude > max_magnitude) {
            max_magnitude = magnitude;
            max_index = i;
        }
    }

    // 周波数を計算
    double frequency = (double)max_index * sampling_freq / sample_count;

    free(output);

    return frequency;
}

#include <stdlib.h>
#include <math.h>
#include "complex.h"
#include "dft.h"

double calculate_signal_power(double* input, int input_size, double sampling_freq, double start_freq, double end_freq)
{
    Complex* output = malloc(input_size * sizeof(Complex));

    dft(input, input_size, output);

    double power = 0.0;
    double freq_resolution = sampling_freq / input_size;

    for (int i = 0; i < input_size / 2; i++) {  // ナイキスト周波数まで
        double freq = i * freq_resolution;
        if (freq >= start_freq && freq <= end_freq) {
            power += output[i].re * output[i].re + output[i].im * output[i].im;
        }
    }

    free(output);

    power /= (input_size * input_size);

    return power;
}

