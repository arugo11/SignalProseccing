/**
 * @brief 複素数の構造体の定義と計算処理の実装
 * @author Argo
 * @date 2024/07/20
 */

#include <stdio.h>

#include "complex.h"

Complex complex_add(Complex a, Complex b)
{
    Complex ret;
    ret.re = a.re + b.re;
    ret.im = a.im + b.im;

    return ret;
}

Complex complex_multiply(Complex a, Complex b)
{
    Complex ret;
    ret.re = a.re * b.re - a.im * b.im;
    ret.im = a.re * b.im + a.im * b.re;

    return ret;
}
