/***
 * @file dct.c
 * @brief dct(離散コサイン変換)とidct(離散コサイン変換)の実装
 * @author Argo
 * @date 2024/07/17
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "dct.h"
#include "math_utils.h"


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