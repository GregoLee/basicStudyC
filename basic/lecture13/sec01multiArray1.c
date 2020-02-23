//
// Created by invin on 2020-02-20.
//
/*
 * 2차원 배열의 필요성
 * 1) 행렬 데이터를 표현할 때
 *     , 그래프 알고리즘을 처리할 때
 *     , 다수의 실생활 데이터를 처리할 때 등
 * 2) 작성법
 *    - {dataType} {name}[행][열] = { {valueA_1, valueB_1, ...}, {valueA_2, valueB_2, ...}, ... }
 *    - int arr[10][10];
 */
#include<stdio.h>

int a[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} };

int main(void) {
    int i, j;
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}