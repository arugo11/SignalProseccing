/***
 * @file solver.c
 * @brief 課題の内容を計算するためのコード
 * @author argo
 * @date 2024/07/17
*/

#include <stdio.h>
#include "dct.h"

void kadai1_3(void)
{
    const double f_n[8] = {2,3,1,0,12,4,1,8};
    double C_k[8];

    dct(f_n,8,C_k);

    for(int i = 0; i < 8;i++ )
    {
        printf("%lf ",C_k[i]);
    }
}   

void kadai1_4(void)
{
    
}

int main()
{
    kadai1_3();

    return 0;
}