#ifndef COMPLEX_H
#define COMPLEX_H

/**
 * @brief 複素数を表す構造体
 */
typedef struct {
    double re;  /**< 実部 */
    double im;  /**< 虚部 */
} Complex;

/**
 * @brief 複素数の加算
 * @param a 第一オペランド
 * @param b 第二オペランド
 * @return 加算結果の複素数
 */
Complex complex_add(Complex a, Complex b);

/**
 * @brief 複素数の乗算
 * @param a 第一オペランド
 * @param b 第二オペランド
 * @return 乗算結果の複素数
 */
Complex complex_multiply(Complex a, Complex b);

#endif // COMPLEX_H