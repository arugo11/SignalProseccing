#ifndef SIGNAL_PROCESSING_H
#define SIGNAL_PROCESSING_H

#include "complex.h"

/**
 * @brief 信号にフィルタを適用
 * @param input 入力信号
 * @param input_size 入力信号のサイズ
 * @param filter フィルタ関数ポインタ
 * @param output フィルタ適用後の信号の出力先
 * @return なし
 */
void apply_filter(const Complex* input, int input_size, 
                  Complex (*filter)(Complex), Complex* output);

/**
 * @brief ハイパスフィルタを作成
 * @param cutoff_freq カットオフ周波数
 * @param sample_rate サンプリングレート
 * @return フィルタ関数ポインタ
 */
Complex (*create_high_pass_filter(double cutoff_freq, double sample_rate))(Complex);

#endif // SIGNAL_PROCESSING_H