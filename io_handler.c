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

    int count = 0;
    while (count < max_size && fscanf(fp, "%lf", &output[count]) == 1)
    {
        count++; // 成功した読み込みの数をカウント
    }

    fclose(fp);
    return count; // 読み込んだ要素の数を返す
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

    int count = 0;
    double real, imag;
    while (count < max_size && fscanf(fp, "%lf %lf", &real, &imag) == 2)
    {
        output[count].re = real;
        output[count].im = imag;
        count++; // 成功した読み込みの数をカウント
    }

    fclose(fp);
    return count; // 読み込んだ要素の数を返す
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

int read_real_2d(const char* filename, double** output, int max_rows, int max_cols)
{
    char filepath[MAX_FILENAME_LENGTH];
    snprintf(filepath, sizeof(filepath), "input/%s", filename); // ファイルパスの設定

    FILE* fp = fopen(filepath, "r");
    if (fp == NULL)
    {
        return -1; // ファイルオープンに失敗
    }

    for (int i = 0; i < max_rows; i++)
    {
        for (int j = 0; j < max_cols; j++)
        {
            if (fscanf(fp, "%lf", &output[i][j]) != 1)
            {
                fclose(fp);
                return i; // 読み込んだ行数を返す
            }
        }
    }

    fclose(fp);
    return max_rows; // 全ての行を読み込んだ
}

int write_real_2d(const char* filename, const double** data, int rows, int cols)
{
    char filepath[MAX_FILENAME_LENGTH];
    snprintf(filepath, sizeof(filepath), "output/%s.csv", filename);

    FILE* fp = fopen(filepath, "w");
    if (fp == NULL)
    {
        return -1;
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            fprintf(fp, "%f", data[i][j]);
            if (j < cols - 1)
            {
                fprintf(fp, ","); // カンマで列を区切る
            }
        }
        fprintf(fp, "\n"); // 各行の終わりに改行を挿入
    }

    fclose(fp);
    return 0;
}
