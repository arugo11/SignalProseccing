#ifndef SIGNAL_FILTER_H
#define SIGNAL_FILTER_H

#include "complex.h"
/*** 
 * @brief 複素数ハイパスフィルタ
 * @param input 入力信号(周波数領域)
 * @param input_size 入力信号のサイズ
 * @param cutoff カットする値
 * @param output 出力信号(周波数領域)
 * @note cutoff以上を通過させる
 */
void HPF_complex(Complex* input, int input_size,  int cutoff, Complex* output);

/*** 
 * @brief 複素数ローパスフィルタ
 * @param input 入力信号(周波数領域)
 * @param input_size 入力信号のサイズ
 * @param cutoff カットする値
 * @param output 出力信号(周波数領域)
 * @note cutoff以下を通過させる
 */
void LPF_complex(Complex* input, int input_size, int cutoff, Complex* output);

/***
 * @brief 実数ハイパスフィルタ
 * @param input 入力信号(周波数領域)
 * @param input_size 入力信号のサイズ
 * @param cutoff カットする値
 * @param output 出力信号(周波数領域)
 * @note cutoffより上を通過させる
 * 
*/
void HPF_real(double* input, int input_size, int cutoff, double* output);

/***
 * @brief 実数ローパスフィルタ
 * @param input 入力信号(周波数領域)
 * @param input_size 入力信号のサイズ
 * @param cutoff カットする値
 * @param output 出力信号(周波数領域)
 * @note cutoff未満を通過させる
 * 
*/
void LPF_real(double* input, int input_size, int cutoff, double* output);

#endif // SIGNAL_FILTER_H
