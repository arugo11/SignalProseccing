#ifndef DCT_H
#define DCT_H

/**
 * @brief 離散コサイン変換（DCT）を実行
 * @param input 入力信号
 * @param input_size 入力信号のサイズ
 * @param output DCT係数の出力先
 * @return なし
 */
void dct(const double* input, int input_size, double* output);





/**
 * @brief 逆離散コサイン変換（IDCT）を実行
 * @param coeffs DCT係数
 * @param coeffs_size DCT係数のサイズ
 * @param output 復元された信号の出力先
 * @return なし
 */
void idct(const double* coeffs, int coeffs_size, double* output);

/**
 * @brief dctの２次元変換
 * @param input 入力信号
 * @param n 行数
 * @param m 列数
 * @param output 出力信号
 */ 
void dct2d(const double** input, int rows, int cols, double** output);

/**
 * @brief idctの２次元変換
 * @param input 入力信号
 * @param n 行数
 * @param m 列数
 * @param output 出力信号
 */
void idct2d(const double** coeffs, int rows, int cols, double** output);
#endif // DCT_H