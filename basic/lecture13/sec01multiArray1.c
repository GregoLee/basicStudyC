//
// Created by invin on 2020-02-20.
//
/*
 * 2���� �迭�� �ʿ伺
 * 1) ��� �����͸� ǥ���� ��
 *     , �׷��� �˰����� ó���� ��
 *     , �ټ��� �ǻ�Ȱ �����͸� ó���� �� ��
 * 2) �ۼ���
 *    - {dataType} {name}[��][��] = { {valueA_1, valueB_1, ...}, {valueA_2, valueB_2, ...}, ... }
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