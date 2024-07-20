/***
 * @file main.c
 * @brief 課題の内容を計算
 * @author argo
 * @date 2024/07/17
*/

#include <stdio.h>
#include <math.h>

#include "math_utils.h"
#include "dct.h"
#include "io_handler.h"
#include "complex.h"
#include "dft.h"




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
    dct(f3,100,c3);

    int CUTOFF = 20;
    for(int i = 0; i < N; i++)
    {
        if(i < CUTOFF) c3a[i] = c3[i];
        else c3a[i] = 0.0;
    }

    idct(c3a,N,f3a);
    write_real_1d("kadai1_4_f3",f3,N);
    write_real_1d("kadai1_4_f3a",f3a,N);

    double ans = roundN(f3a[10],2);
    printf("%.1lf\n",ans);
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



void kadai2_1(void)
{
    Complex f;
    f.re = 2;f.im = 1;

    Complex b;
    b.re = 1; b.im = 2;

    for(int i = 1; i <= 20; i++)
    {
        f = complex_multiply(f,b);
        if((i == 10) || (i == 20))
        {
            printf("%.0lf + j%.0lf\n",f.re,f.im);
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
    printf("%.1lf + j%.1lf",roundN(Ft[4].re,2), roundN(Ft[4].im,2));
}
int main()
{

    return 0;
}