#ifndef IO_HANDLER_H
#define IO_HANDLER_H

#include "complex.h"

/**
 * @brief 1次元の実数データをファイルから読み込む
 * @param filename 入力ファイル名
 * @param output 読み込んだデータを格納する配列
 * @param max_size 読み込む最大要素数
 * @return 実際に読み込んだ要素数、エラーの場合は負の値
 */
int read_real_1d(const char* filename, double* output, int max_size);

/**
 * @brief 1次元の実数データをファイルに書き込む
 * @param filename 出力ファイル名
 * @param data 書き込むデータの配列
 * @param size データの要素数
 * @return 成功した場合は0、失敗した場合は負の値
 */
int write_real_1d(const char* filename, const double* data, int size);

/**
 * @brief 1次元の複素数データをファイルから読み込む
 * @param filename 入力ファイル名
 * @param output 読み込んだデータを格納する配列
 * @param max_size 読み込む最大要素数
 * @return 実際に読み込んだ要素数、エラーの場合は負の値
 */
int read_complex_1d(const char* filename, Complex* output, int max_size);

/**
 * @brief 1次元の複素数データをファイルに書き込む
 * @param filename 出力ファイル名
 * @param data 書き込むデータの配列
 * @param size データの要素数
 * @return 成功した場合は0、失敗した場合は負の値
 */
int write_complex_1d(const char* filename, const Complex* data, int size);

/**
 * @brief 2次元の実数データをファイルに書き込む
 * @param filename 出力ファイル名
 * @param data 書き込むデータの2次元配列
 * @param rows データの行数
 * @param cols データの列数
 * @return 成功した場合は0、失敗した場合は負の値
 */
int write_real_2d(const char* filename, const double** data, int rows, int cols);

/**
 * @brief 2次元の複素数データをファイルから書き込む
 * @param filename 入力ファイル名
 * @param output 読み込んだデータを格納する2次元配列
 * @param max_rows 読み込む最大行数
 * @param max_cols 読み込む最大列数
 */
int write_complex_2d(const char* filename, const Complex** data, int max_rows, int max_cols);

/**
 * @brief ファイルの行数を取得
 * @param filename ファイル名
 * @return ファイルの行数
 */
int cnt_size(const char* filename);

char** get_file_names(const char* dir_path, int* num_files);



#endif // IO_HANDLER_H
