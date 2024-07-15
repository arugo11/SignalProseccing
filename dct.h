#ifndef DCT_H_
#define DCT_H_

/**
 * @brief 離散コサイン変換（DCT）を実行
 * @param input 入力信号
 * @param input_size 入力信号のサイズ
 * @param output DCT係数の出力先
 */
void dct(const double* input, int input_size, double* output);

/**
 * @brief 逆離散コサイン変換（IDCT）を実行
 * @param coeffs DCT係数
 * @param coeffs_size DCT係数のサイズ
 * @param output 復元された信号の出力先
 */
void idct(const double* coeffs, int coeffs_size, double* output);

#endif /*DCT_H_*/
