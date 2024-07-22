#ifndef MATH_UTILS_H
#define MATH_UTILS_H

#include <math.h>


#define Pi 3.14159265359


/**
 * @brief 小数点第n位で四捨五入する
 * @param src 四捨五入する値
 * @param n 四捨五入する位
 * @return 四捨五入した値
 */
double roundN(double src, int n);
#endif // MATH_UTILS_H
/**
 * @brief 小数点第n位で切り捨てする
 * @param src 切り捨てする値
 * @param n 切り捨てする位
 */
double decimalN(double src, int n) ;