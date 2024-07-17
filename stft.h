#ifndef STFT_H
#define STFT_H

#include "complex.h"

/**
 * @brief 短時間フーリエ変換（STFT）を実行
 * @param input 入力信号
 * @param input_size 入力信号のサイズ
 * @param window_size 窓サイズ
 * @param hop_size ホップサイズ
 * @param output STFT結果の出力先（2次元配列）
 * @param output_rows STFT結果の行数の出力先
 * @param output_cols STFT結果の列数の出力先
 * @return なし
 */
void stft(const double* input, int input_size, int window_size, int hop_size, 
          Complex** output, int* output_rows, int* output_cols);

#endif // STFT_H