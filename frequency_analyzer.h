#ifndef FREQUENCY_ANALYZER_H
#define FREQUENCY_ANALYZER_H

#include "complex.h"

/**
 * @brief 信号の主要周波数を同定
 * @param signal 入力信号
 * @param size 信号のサイズ
 * @param sample_rate サンプリングレート
 * @return 主要周波数
 */
double identify_main_frequency(const double* signal, int size, double sample_rate);

/**
 * @brief 指定された周波数範囲のパワーを計算
 * @param dft_coeffs DFT係数
 * @param size DFT係数のサイズ
 * @param freq_min 最小周波数
 * @param freq_max 最大周波数
 * @param sample_rate サンプリングレート
 * @return 指定範囲のパワー
 */
double calculate_power_in_frequency_range(const Complex* dft_coeffs, int size, 
                                          double freq_min, double freq_max, double sample_rate);

#endif // FREQUENCY_ANALYZER_H