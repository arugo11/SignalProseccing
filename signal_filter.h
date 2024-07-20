#ifndef SIGNAL_FILTER_H
#define SIGNAL_FILTER_H

/*** 
 * @brief 実数ハイパスフィルタ
 * @param input 入力信号
 * @param input_size 入力信号のサイズ
 * @param cutoff カットする値
 * @param output 出力信号
 */
void HPF(double* input, int input_size,  int cutoff, double* output);

/*** 
 * @brief 実数ローパスフィルタ
 * @param input 入力信号
 * @param input_size 入力信号のサイズ
 * @param cutoff カットする値
 * @param output 出力信号
 */
void LPF(double* input, int input_size, int cutoff, double* output);

#endif // SIGNAL_FILTER_H
