/***
 * @file main.c
 * @brief 課題の内容を計算
 * @author argo
 * @date 2024/07/17
*/


#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "complex.h"
#include "math_utils.h"
#include "dct.h"
#include "io_handler.h"
#include "dft.h"
#include "signal_analyzer.h"
#include "signal_filter.h"
#include "fft.h"
// #include "signal_processing.h"



void kadai1_1(void)
{
    int sum = 0;
    for(int i = 0; i < 50; i++)
    {
        sum += i * (i - 10);
        if((i == 24) || (i == 49))
        {
            printf("%d \n",sum);
        }
    }
}

void kadai1_2(void)
{

    float sum = 0;
    float vector;
    for(int i = 0; i < 50; i++)
    {
        vector = (i * Pi) / 100.0;
        sum += sin(vector);
        if((i == 29) || (i == 49))
        {
            sum = roundN(sum,2);
            printf("%.1f \n",sum);
        }
    }
}

void kadai1_3(void)
{
    const double f_n[8] = {2,3,1,0,12,4,1,8};
    double C_k[8];

    dct(f_n,8,C_k);

    write_real_1d("kadai1_3", C_k,8);

    double ans = roundN(C_k[4],2);
    printf("%.1lf \n", ans);
}   

void kadai1_4(void)
{
    int N = 100;
    double c3[N];
    double c3a[N];
    double f3[N];
    double f3a[N];
    read_real_1d("DCT_a.txt",f3,N);
    dct(f3,N,c3);
    LPF_real(c3,N,20,c3a);
    idct(c3a,N,f3a);
    // printf("kadai1-4 : %.1lf \n",roundN(f3a[10],2));
    write_real_1d("kadai1_4_f3",f3,N);
    write_real_1d("kadai1_4_f3a",f3a,N);
    // write_real_1d("kadai1_4_c3a",c3a,N);/

}

void kadai1_5(void)
{
    int N = 100;
    
    double f3[N];
    double c3[N];
    double c3b[N];
    double f3b[N];

    read_real_1d("DCT_a.txt",f3,N);

    dct(f3,N,c3);

    for(int i = 0; i < N ; i++)
    {
        c3b[i] = floor(c3[i]/20.0+0.5)*20;
    }

    idct(c3b,N,f3b);
    write_real_1d("kadai1_5_c3b",c3b,N);
    write_real_1d("kadai1_5_f3",f3,N);
    write_real_1d("kadai1_5_f3b",f3b,N);
    
    double ans = roundN(f3b[10],2);
    printf("%.1lf \n",ans);


}



void kadai2_1(void) {
    Complex f;
    f.re = 2; f.im = 1;

    Complex b;
    b.re = 1; b.im = 2;

    Complex result = f;
    
    for(int i = 1; i <= 20; i++) {
        result = complex_multiply(result, b);
        if (i == 10) {
            printf("f1(10) = %.0lf + j%.0lf\n", result.re, result.im);
        } else if (i == 20) {
            printf("f1(20) = %.0lf + j%.0lf\n", result.re, result.im);
        }
    }
}

void kadai2_2(void)
{
    double ft[] = {2,3,1,0,12,4,1,8};
    double ft_t[8];
    int N = sizeof(ft) / sizeof(ft[0]);
    Complex Ft[N];
    dft(ft, N, Ft);
    idft(Ft,N,ft_t);
    write_real_1d("kadai2_2_ft_t",ft_t,N);
    printf("%.1lf + j%.1lf\n",roundN(Ft[4].re,2), roundN(Ft[4].im,2));
}

void kadai2_3(void)
{
    double ft[] = {2,3,1,0,12,4,1,8};
    double ft_t[8];
    int N = sizeof(ft) / sizeof(ft[0]);
    Complex Ft[N];
    dft(ft, N, Ft);
    idft(Ft,N,ft_t);
    for(int i = 0; i < N; i++)
    {
        printf("%.1lf + j%.1lf \n",roundN(Ft[i].re,2), roundN(Ft[i].im,2));
    }
    // 2,1,3,4
}

void kadai2_4(void)
{
    int N = 250;
    double Hz = 10;
    double ft[N];
    // double Ft[N];

    read_real_1d("DFT_a.txt",ft,N);
    // dct(ft, N, Ft);
    // write_real_1d("kadai2_4_Ft",Ft,N);

    printf("%.1lf \n",roundN(calculate_main_frequency(ft,N,Hz),2));


}

void kadai2_5(void)
{
    int N = 100;
    double f4[N];
    double fc4[N];
    Complex F4[N];
    Complex Fc4[N];

    read_real_1d("DFT_b.txt",f4,N);
    dft(f4,N,F4);
    HPF_complex(F4,N,10,Fc4);
    idft(Fc4,N,fc4);
    write_real_1d("kadai2_5_f4",f4,N);
    write_real_1d("kadai2_5_fc4",fc4,N);

    printf("%.0lf \n",roundN(fc4[10],1));


}

void kadai2_6(void)
{
    int N = 1000; 
    double sampling_freq = 500.0;  
    double input[N];

    read_real_1d("DFT_c.txt", input, N);

    double power_2_4 = calculate_signal_power(input, N, sampling_freq, 2.0, 4.0);
    double power_15_17 = calculate_signal_power(input, N, sampling_freq, 15.0, 17.0);
    double power_61_63 = calculate_signal_power(input, N, sampling_freq, 61.0, 63.0);


    printf("2-4 Hz:   %e\n", power_2_4);
    printf("15-17 Hz: %e\n", power_15_17);
    printf("61-63 Hz: %e\n", power_61_63);


    if (power_2_4 > power_15_17 && power_2_4 > power_61_63) {
        printf("最大パワー: 2-4 Hz\n");
    } else if (power_15_17 > power_2_4 && power_15_17 > power_61_63) {
        printf("最大パワー: 15-17 Hz\n");
    } else {
        printf("最大パワー: 61-63 Hz\n");
    }
}



void kadai3_1()
{

    int WINDOW_SIZE = 256;
    int SAMPLING_RATE = 100;
    int MAX_DATA_SIZE = 4096;

    double* data = (double*)malloc(sizeof(double) * MAX_DATA_SIZE);
    int data_size = read_real_1d("FFT_a.txt", data, MAX_DATA_SIZE);


    double initial_freq = calculate_main_frequency(data, WINDOW_SIZE, SAMPLING_RATE);
    double final_freq = calculate_main_frequency(data + data_size - WINDOW_SIZE, WINDOW_SIZE, SAMPLING_RATE);

    printf(" 初期周波数 : %d Hz\n", (int)round(initial_freq));
    printf("最終周波数 :%d Hz\n", (int)round(final_freq));

    free(data);
}

void kadai4()
{
    double x[4][4] = {
        {1, 2, 4, -1},
        {3, 5, 11, 4},
        {-4, 23, 2, -10},
        {4, 9, -3, 2}
    };
    
    double X_dct[4][4];


    double* x_ptr[4];
    double* X_dct_ptr[4];

    for (int i = 0; i < 4; i++) {
        x_ptr[i] = x[i];
        X_dct_ptr[i] = X_dct[i];

    }

    dct2d((const double**)x_ptr, 4, 4, X_dct_ptr);

    for(int i = 0;i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            printf("%.1lf ",X_dct[i][j]);
        }
        printf("\n");
    }

}

void test2023_2_1()
{
    double input[1024];
    double output[1024];
    read_real_1d("Signal2.txt",input,1024);
    dct(input,1024,output);
    printf("%.1lf\n",decimalN(output[123],2));
}




int main()
{
    // (void)argc;
    // if (argc > 1 && strcmp(argv[1], "c") == 0)
    // {
    //     signal_processing();//どうしよっかなーー！！
    //     return 0;
    // }
    
    kadai1_1();
    kadai1_2();
    kadai1_3();
    kadai1_4();
    kadai1_5();


    return 0;
}

