/**
 * @file dct.c
 * @brief DCT(離散コサイン変換),IDCT(逆離散コサイン変換)の実装
 * @author Argo
 * @date 2024/07/20
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "stdio.h"

#define Pi 3.14159265358979323846

void dct(const double* input, int input_size, double* output)
{
    for(int k = 0; k < input_size; k++)
    {
        double c_tmp = 0;
        for(int n = 0; n < input_size; n++)
        {
            c_tmp += input[n] * cos(((2.0 * n + 1) * k * Pi) / (2 * input_size));
        }
        output[k] = c_tmp;
    }
}

void idct(const double* coeffs, int coeffs_size, double* output)
{
    for(int n = 0; n < coeffs_size; n++)
    {
        output[n] = coeffs[0] / 2.0;
        for(int k = 1; k < coeffs_size; k++)
        {
            double vector = ((2.0 * n + 1) * k * Pi) / (2 * coeffs_size);
            output[n] += coeffs[k] * cos(vector);
        }
        output[n] *= (2.0 / coeffs_size);
    }
}

void dct2d(const double** input, int rows, int cols, double** output)
{
    double* temp = (double*)malloc(rows * cols * sizeof(double));
    
    // DCT on rows
    for(int i = 0; i < rows; i++)
    {
        dct(input[i], cols, temp + i * cols);
    }
    
    // Transpose
    double* transposed = (double*)malloc(rows * cols * sizeof(double));
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            transposed[j * rows + i] = temp[i * cols + j];
        }
    }
    
    // DCT on columns (transposed rows)
    for(int i = 0; i < cols; i++)
    {
        dct(transposed + i * rows, rows, temp + i * rows);
    }
    
    // Transpose back
    for(int i = 0; i < cols; i++)
    {
        for(int j = 0; j < rows; j++)
        {
            output[j][i] = temp[i * rows + j];
        }
    }
    
    free(temp);
    free(transposed);
}