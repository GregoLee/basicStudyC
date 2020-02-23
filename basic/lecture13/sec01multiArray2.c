//
// Created by invin on 2020-02-20.
//
/*
 * 다차원 배열 - 3차원 배열 다루기
 */
#include<stdio.h>

int a[2][3][3] = {{{1,2,3}, {4,5,6}, {7,8,9}},
                  {{1,2,3}, {4,5,6}, {7,8,9}}};

int main(void) {
    int i, j, k;
    for(i=0; i<2; i++) {
        for(j=0; j<3; j++) {
            for(k=0; k<3; k++) {
                if(i%2==1) {
                    printf("%d ", a[1-i][2-j][2-k]);
                } else {
                    printf("%d ", a[i][j][k]);
                }
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}