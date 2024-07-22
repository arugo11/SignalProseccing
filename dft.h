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

    /**
     * @brief dftの２次元変換
     * @param input 入力信号
     * @param n 行数
     * @param m 列数
     * @param output 出力信号
     */
    void dft2d(const double** input, int n, int m, Complex** output);

    /**
     * @brief idftの２次元変換
     * @param input 入力信号
     * @param n 行数
     * @param m 列数
     * @param output 出力信号
     */
    void idft2d(const Complex** input, int n, int m, double** output);

#endif // DFT_H