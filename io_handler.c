/** 
 * @fn io_handler.c
 * @brief ファイルの入出力
 * @author Argo
 * @date 2024/07/18
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "complex.h"
#include "io_handler.h"

#define MAX_FILENAME_LENGTH 256

int read_real_1d(const char* filename, double* output, int max_size)
{
    char filepath[MAX_FILENAME_LENGTH];
    snprintf(filepath, sizeof(filepath), "input/%s", filename); // ファイルパスの設定

    FILE* fp = fopen(filepath, "r");
    if (fp == NULL)
    {
        return -1; // ファイルオープンに失敗
    }

    int cnt = 0;
    while (cnt < max_size && fscanf(fp, "%lf", &output[cnt]) == 1)
    {
        cnt++; // 成功した読み込みの数をカウント
    }

    fclose(fp);
    return cnt; // 読み込んだ要素の数を返す
}

int write_real_1d(const char* filename, const double* data, int size)
{
    char filepath[MAX_FILENAME_LENGTH];
    snprintf(filepath, sizeof(filepath), "output/%s.csv", filename);

    FILE* fp = fopen(filepath, "w");
    if (fp == NULL)
    {
        return -1; // ファイルオープンに失敗
    }

    for (int i = 0; i < size; i++)
    {
        fprintf(fp, "%f\n", data[i]); // 配列の各要素をファイルに書き込む
    }

    fclose(fp); // ファイルを閉じる
    return 0; // 成功
}

int read_complex_1d(const char* filename, Complex* output, int max_size)
{
    char filepath[MAX_FILENAME_LENGTH];
    snprintf(filepath, sizeof(filepath), "input/%s", filename); // ファイルパスの設定

    FILE* fp = fopen(filepath, "r");
    if (fp == NULL)
    {
        return -1; // ファイルオープンに失敗
    }

    int cnt = 0;
    double real, imag;
    while (cnt < max_size && fscanf(fp, "%lf %lf", &real, &imag) == 2)
    {
        output[cnt].re = real;
        output[cnt].im = imag;
        cnt++; // 成功した読み込みの数をカウント
    }

    fclose(fp);
    return cnt; // 読み込んだ要素の数を返す
}

int write_complex_1d(const char* filename, const Complex* data, int size)
{
    char filepath[MAX_FILENAME_LENGTH];
    snprintf(filepath, sizeof(filepath), "output/%s.csv", filename);

    FILE* fp = fopen(filepath, "w");
    if (fp == NULL)
    {
        return -1;
    }

    for (int i = 0; i < size; i++)
    {
        fprintf(fp, "%f + %fi\n", data[i].re, data[i].im); // 複素数の実部と虚部を書き込む
    }

    fclose(fp);
    return 0;
}


int write_real_2d(const char* filename, const double** data, int rows, int cols) {
    if (filename == NULL || data == NULL || rows <= 0 || cols <= 0) {
        return -1; // 引数の検証
    }

    char filepath[MAX_FILENAME_LENGTH];
    snprintf(filepath, sizeof(filepath), "output/%s.csv", filename);

    FILE* fp = fopen(filepath, "w");
    if (fp == NULL) {
        return -1;
    }

    for (int i = 0; i < rows; i++) {
        if (data[i] == NULL) { // data[i]がNULLでないことを確認
            fclose(fp);
            return -1;
        }
        for (int j = 0; j < cols; j++) {
            fprintf(fp, "%f", data[i][j]);
            if (j < cols - 1) {
                fprintf(fp, ",");
            }
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
    return 0;
}

int write_complex_2d(const char* filename, const Complex** data, int max_rows, int max_cols) {
    if (filename == NULL || data == NULL || max_rows <= 0 || max_cols <= 0) {
        return -1; // 引数の検証
    }

    char filepath[MAX_FILENAME_LENGTH];
    snprintf(filepath, sizeof(filepath), "output/%s.csv", filename);

    FILE* fp = fopen(filepath, "w");
    if (fp == NULL) {
        return -1;
    }

    for (int i = 0; i < max_rows; i++) {
        if (data[i] == NULL) { // data[i]がNULLでないことを確認
            fclose(fp);
            return -1;
        }
        for (int j = 0; j < max_cols; j++) {
            fprintf(fp, "%f + %fi", data[i][j].re, data[i][j].im);
            if (j < max_cols - 1) {
                fprintf(fp, ",");
            }
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
    return 0;
}

int cnt_size(const char* filename)
{
    char filepath[MAX_FILENAME_LENGTH];
    snprintf(filepath, sizeof(filepath), "input/%s", filename); // ファイルパスの設定

    FILE* fp = fopen(filepath, "r");
    if (fp == NULL)
    {
        return -1; // ファイルオープンに失敗した場合
    }

    int cnt = 0;
    char buffer[1024]; // 1行を読み込むためのバッファ
    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        cnt++; // ファイルの行数をカウント
    }

    fclose(fp);
    return cnt; // ファイルの行数を返す
}

#include <dirent.h>
#include <stdlib.h>
#include <string.h>

char** get_file_names(const char* dir_path, int* num_files) {
    DIR* dir;
    struct dirent* entry;
    char** file_names = NULL;
    int count = 0;

    dir = opendir(dir_path);
    if (dir == NULL) {
        perror("opendir");
        return NULL;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {
            file_names = realloc(file_names, (count + 1) * sizeof(char*));
            if (file_names == NULL) {
                perror("realloc");
                closedir(dir);
                return NULL;
            }
            file_names[count] = strdup(entry->d_name);
            if (file_names[count] == NULL) {
                perror("strdup");
                closedir(dir);
                return NULL;
            }
            count++;
        }
    }

    closedir(dir);
    *num_files = count;
    return file_names;
}