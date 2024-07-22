/**@file
 * @brief 数学補助ライブラリ
 * @author argo
 * @2024/07/20
 */

#include <stdio.h>
#include <math.h>


#include "math_utils.h"

double roundN(double src, int n)
{
    n --;
    src = src * pow(10, n); 
    double dst = (double)(int)(src + 0.5); // 四捨五入
    dst = dst * pow(10, -n); 

    return dst;
}

double decimalN(double src, int n){
    double multiplier = pow(10.0, n);
    return floor(src * multiplier) / multiplier;
}

// double square_sum(double* input)
// {
//     int N = (sizeof(input) / sizeof(input[0]));
//     double sum = 0;
//     for(int i = 0; i < N; i++)
//     {
//         sum += input[i] * input[i];
//     }

//     return sum;
// }