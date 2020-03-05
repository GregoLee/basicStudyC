//
// Created by invin on 2020-03-05.
//
/*
 * 퀵 정렬(Quick Sort)
 * 1. 개요
 *    1) 피벗을 기준으로 큰 값과 작은 값을 서로 교체하는 정렬 기법
 *    2) 값을 서로 교체하는 데에 N번,
 *       엇갈린 경우 교체 이후에 원소가 반으로 나누어지므로
 *       전체 원소를 나누는데에 평균적으로 log N번이 소요
 *    3) 평균적으로 O(N*log N)의 시간 복잡도를 가진다.
 *                pivot-5   | 5| 4| 3| 8| 9| 6| 7| 1|10| 2|
 *       5보다 큰 수 --->   | 5| 4| 3| 8| 9| 6| 7| 1|10| 2|    <--- 5보다 작은 수
 *               2, 8 교체  | 5| 4| 3| 2| 9| 6| 7| 1|10| 8|
 *               1, 9 교체  | 5| 4| 3| 2| 1| 6| 7| 9|10| 8|
 *                          | 5| 4| 3| 2| 1| 6| 7| 9|10| 8| ===> 1과 6의 인덱스가 교차
 *               1, 5 교체  | 1| 4| 3| 2| 5| 6| 7| 9|10| 8|
 *              pivot-1, 6  | 1| 4| 3| 2| 5| 6| 7| 9|10| 8|
 *                           ...
 * 2. log N의 시간복잡도가 나오는 대표적인 예시는 완전 이진 트리이다.
 *    완전 이진 트리 형태는 흔히 컴퓨터 공학에서 가장 선호하는 이상적인 형태이다.
 *    1) 완전 이진트리의 높이는 log N 이다.
 */
#include <stdio.h>
#define SIZE 1000

int a[SIZE];

int swap(int *a, int *b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

void quickSort(int start, int end) {
    if(start>=end) return;
    int key = start, i = start + 1, j = end, temp;
    while(i <= j) { //엇갈릴 때까지 반복한다.
        while(i <= end && a[i] <= a[key]) i++;
        while(j > start && a[j] >= a[key]) j--;
        if(i>j) swap(&a[key], &a[j]);
        else swap(&a[i], &a[j]);
    }
    quickSort(start, j-1);
    quickSort(j+1, end);
}

int main(void) {
    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    quickSort(0, n-1);

    for(int i=0; i<n; i++) printf("%d ", a[i]);
    return 0;
}
