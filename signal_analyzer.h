#ifndef SIGNAL_ANALYZER_H_
#define SIGNAL_ANALYZER_H_

/**
 * @brief 信号の主要周波数を計算する
 * @param input 入力信号
 * @param sample_count サンプル数
 * @param sampling_freq サンプリング周波数
 * @return 主要周波数
 */
double calculate_main_frequency(double* input, int sample_count, double sampling_freq);


/** @fn 
 * @brief 信号のパワーを計算する
 * @param input 入力信号
 * @param input_size 入力信号のサイズ
 * @param sampling_freq サンプリング周波数
 * @param start_freq 範囲の開始地点
 * @param end_freq 範囲の終了地点
 * @return 信号のパワー
 */
double calculate_signal_power(double* input, int input_size, double sampling_freq, double start_freq, double end_freq);
    



#endif // SIGNAL_ANALYSIS_H