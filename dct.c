#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI (atan(1.0) * 4)

void dct(const double* input, int input_size, double* output)
{
    for(int k = 0; k < input_size; k++)
    {
        double c_tmp = 0;
        for(int n = 0; n < input_size; n++)
        {
            c_tmp += input[n] * cos(((2.0 * n + 1) * k * PI) / (2 * input_size));
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
            double vector = ((2.0 * n + 1) * k * PI) / (2 * coeffs_size);
            output[n] += coeffs[k] * cos(vector);
        }
        output[n] *= (2.0 / coeffs_size);
    }
}