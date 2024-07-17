/***
 * @file io_handler.c
 * @brief ファイルの入出力関係の処理
 * @author argo
 * @date 2024/07/17
*/

#include <stdio.h>


#include "complex.h"
#include "io_handler.h"

int read_real_1d(const char* filename, double* output, int max_size)
{
    FILE* fp = fopen(filename, "r");
    if(fp == NULL)
    {
        return -1;
    }

    int i = 0;
    while(i < max_size && fscanf(fp, "%lf", &output[i]) != EOF)
    {
        i++;
    }

    fclose(fp);

    return i;
}

int write_real_1d(const char* filename, const double* data, int size)
{
    FILE* fp = fopen(filename, "w");
    if(fp == NULL)
    {
        return -1;
    }

    for(int i = 0; i < size; i++)
    {
        fprintf(fp, "%lf\n", data[i]);
    }

    fclose(fp);

    return 0;
}

int read_complex_1d(const char* filename, Complex* output, int max_size)
{
    FILE* fp = fopen(filename, "r");
    if(fp == NULL)
    {
        return -1;
    }

    for(int i = 0; i < max_size; i++)
    {
        if(fscanf(fp, "%lf %lf", &output[i].re, &output[i].im) == EOF)
        {
            fclose(fp);
            return i;
        }
    }
}

int write_complex_1d(const char* filename, const Complex* data, int size)
{
    FILE* fp = fopen(filename, "w");
    if(fp == NULL)
    {
        return -1;
    }

    for(int i = 0; i < size; i++)
    {
        fprintf(fp, "%lf %lf\n", data[i].re, data[i].im);
    }

    fclose(fp);

    return 0;

}

int read_real_2d(const char* filename, double** output, int max_rows, int max_cols)
{
    FILE* fp = fopen(filename, "r");
    if(fp == NULL)
    {
        return -1;
    }

    int i = 0;
    while(i < max_rows && fscanf(fp, "%lf", &output[i][0]) != EOF)
    {
        for(int j = 1; j < max_cols; j++)
        {
            if(fscanf(fp, "%lf", &output[i][j]) == EOF)
            {
                fclose(fp);
                return i;
            }
        }
        i++;
    }

    fclose(fp);

    return i;
}

int write_real_2d(const char* filename, const double** data, int rows, int cols)
{
    FILE* fp = fopen(filename, "w");
    if(fp == NULL)
    {
        return -1;
    }

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            fprintf(fp, "%lf ", data[i][j]);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);

    return 0;
}
