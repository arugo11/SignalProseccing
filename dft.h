#ifndef DFT_H
#define DFT_H

#include "complex.h"

/**
 * @brief 離散フーリエ変換（DFT）を実行
 * @param input 入力信号
 * @param input_size 入力信号のサイズ
 * @param output DFT係数の出力先
 * @return なし
 */
void dft(const double* input, int input_size, Complex* output);

/**
 * @brief 逆離散フーリエ変換（IDFT）を実行
 * @param coeffs DFT係数
 * @param coeffs_size DFT係数のサイズ
 * @param output 復元された信号の出力先
 * @return なし
 */
void idft(const Complex* coeffs, int coeffs_size, double* output);

#endif // DFT_H