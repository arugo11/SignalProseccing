#ifndef FFT_H
#define FFT_H

#include "complex.h"

/**
 * @brief 高速フーリエ変換（FFT）を実行
 * @param input 入力信号
 * @param input_size 入力信号のサイズ（2のべき乗である必要がある）
 * @param output FFT係数の出力先
 */
void fft(const double* input, int input_size, Complex* output);

/**
 * @brief 逆高速フーリエ変換（IFFT）を実行
 * @param coeffs FFT係数
 * @param coeffs_size FFT係数のサイズ（2のべき乗である必要がある）
 * @param output 復元された信号の出力先
 */
void ifft(const Complex* coeffs, int coeffs_size, Complex* output);

#endif // FFT_H