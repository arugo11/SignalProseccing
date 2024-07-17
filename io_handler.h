#ifndef IO_HANDLER_H
#define IO_HANDLER_H

/**
 * @brief テキストファイルから信号を読み込む
 * @param filename ファイル名
 * @param output 読み込んだ信号データの出力先
 * @param max_size 読み込む最大サイズ
 * @return 実際に読み込んだデータの数
 */
int read_signal_from_file(const char* filename, double* output, int max_size);

/**
 * @brief 信号をテキストファイルに書き込む
 * @param filename ファイル名
 * @param signal 書き込む信号データ
 * @param size 信号データのサイズ
 * @return 成功時は0、失敗時は-1
 */
int write_signal_to_file(const char* filename, const double* signal, int size);

#endif // IO_HANDLER_H