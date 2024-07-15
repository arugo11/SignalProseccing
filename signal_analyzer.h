/**
 * @brief 信号の統計情報を表す構造体
 */
typedef struct {
    double mean;    /**< 平均 */
    double variance; /**< 分散 */
    double max;      /**< 最大値 */
    double min;      /**< 最小値 */
} SignalStats;

/**
 * @brief 信号の統計情報を計算
 * @param signal 入力信号
 * @param size 信号のサイズ
 * @return 統計情報
 */
SignalStats calculate_signal_stats(const double* signal, int size);

/**
 * @brief 信号のSN比を計算
 * @param signal 入力信号
 * @param noise ノイズ信号
 * @param size 信号のサイズ
 * @return SN比（デシベル）
 */
double calculate_snr(const double* signal, const double* noise, int size);