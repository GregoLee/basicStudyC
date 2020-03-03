//
// Created by Jaeyoung Lee on 2020/03/04.
//
/*
 * 선택 정렬(Selection Sort)
 * 1. 개요
 *    1) 가장 작은 것을 선택해서 앞으로 보내는 정렬 기법
 *    2) 가장 작은 것을 선택하는 데에 N번, 앞으로 보내는 데에 N번의 연산으로 O(N^2)의 시간 복잡도를 가진다.
 *       | 2| 4| 3| 1| 9| 6| 7| 8|10| 5|
 *       | 1| 4| 3| 2| 9| 6| 7| 8|10| 5| : 1, 2 자리 교체
 *       | 1| 2| 3| 4| 9| 6| 7| 8|10| 5| : 2, 4 자리 교체
 *       | 1| 2| 3| 4| 9| 6| 7| 8|10| 5| : 3 고정
 *       | 1| 2| 3| 4| 9| 6| 7| 8|10| 5| : 4 고정
 *       | 1| 2| 3| 4| 5| 6| 7| 8|10| 9| : 5, 9 자리 교체
 *       | 1| 2| 3| 4| 5| 6| 7| 8|10| 9| : 6 고정
 *       | 1| 2| 3| 4| 5| 6| 7| 8|10| 9| : 7 고정
 *       | 1| 2| 3| 4| 5| 6| 7| 8|10| 9| : 8 고정
 *       | 1| 2| 3| 4| 5| 6| 7| 8|10| 9| : 9. 10 자리 교체
 *       | 1| 2| 3| 4| 5| 6| 7| 8|10| 9| : 10 고
 */
#include <stdio.h>
#include <limits.h>
#define SIZE 1000

int a[SIZE];

int swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void) {
    int n, min, index;
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    for(int i=0; i<n; i++) {
        min = INT_MAX;
        for(int j=i; j<n; j++) {
            if(min>a[j]) {
                min = a[j];
                index = j;
            }
        }
        swap(&a[i], &a[index]);
    }
    for(int i=0; i<n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}