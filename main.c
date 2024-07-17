/***
 * @file solver.c
 * @brief 課題の内容を計算するためのコード
 * @author argo
 * @date 2024/07/17
*/

#include <stdio.h>
#include "dct.h"
#include "io_handler.h"

void kadai1_3(void)
{
    const double f_n[8] = {2,3,1,0,12,4,1,8};
    double C_k[8];

    dct(f_n,8,C_k);

    write_real_1d("./output/kadai1_3", C_k,8);


}   

void kadai1_4(void)
{
    double C3[100];
    double f3a[100];
    double fc3a[100];
    read_real_1d("./input/DCT_a.txt",C3,100);
    dct(C3,100,f3a);
    idct(f3a,100,fc3a);
    write_real_1d("kadai1_4_f3a",f3a,100);
    write_real_1d("kadai1_4_fc3a",fc3a,100);
}

int main()
{
    kadai1_4();

    return 0;
}