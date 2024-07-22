    #ifndef FFT_H_
    #define FFT_H_

    #include "complex.h"

    /**
     * @brief 高速フーリエ変換（FFT）を実行
     * @param input 入力信号
     * @param input_size 入力信号のサイズ
     * @param output FFT係数の出力先
     * @return なし
     */
    void fft(const double* input, int input_size, Complex* output);

    /**
     * @brief 逆高速フーリエ変換（IFFT）を実行
     * @param coeffs FFT係数
     * @param coeffs_size FFT係数のサイズ
     * @param output 復元された信号の出力先
     * @return なし
     */
    void ifft(const Complex* coeffs, int coeffs_size, double* output);


    /**
     * @brief bit反転
     * @param num 入力値
     * @param m ビット数
     * @return bit反転した値
     */
    int reverse_bit(int num, int m);

    /**
     * @brief fftの２次元変換
     * @param input 入力信号
     * @param n 行数
     * @param m 列数
     * @param output 出力信号
     */
    void fft2d(const double** input, int rows, int cols, Complex** output);

    /**
     * @brief ifftの２次元変換
     * @param input 入力信号
     * @param n 行数
     * @param m 列数
     * @param output 出力信号
     */
    void ifft2d(const Complex** coeffs, int rows, int cols, double** output);

    #endif // FFT_H_