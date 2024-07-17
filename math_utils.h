#ifndef MATH_UTILS_H
#define MATH_UTILS_H

#include <math.h>

/**
 * @brief 円周率のマクロ
*/
#define Pi atan(1.0) * 4;


/**
 * @brief 高速な二乗根計算
 * @param x 入力値
 * @return 二乗根
 */
double fast_sqrt(double x);

/**
 * @brief 高速な逆数計算
 * @param x 入力値
 * @return 逆数
 */
double fast_inverse(double x);

#endif // MATH_UTILS_H