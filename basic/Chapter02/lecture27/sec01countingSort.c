//
// Created by Jaeyoung Lee on 2020/03/05.
//
/*
 * 계수 정렬(Counting Sort)
 * 1. 개요
 *    1) 크기를 기준으로 데이터의 개수를 세는 정렬 알고리즘
 *    2) 각 데이터를 바로 크기를 기준으로 분류하므로 O(N)의 시간 복잡도를 가진다.
 *    ***데이터의 크기가 한정적일 때 사용할 수 있다.
 * 2. 동작 원리
 *    인덱스  0   1   2   3
 *     원소  2   3   3   2  <--- |2|1|0|2|2|1|3|1|0|3|
 *               ↓
 *         |0|0|1|1|1|2|2|2|3|3|
 */

#include <stdio.h>
#define MAX_VALUE 10001

int n, m;
int a[MAX_VALUE];

int main(void) {
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &m);
        a[m]++;
    }
    for(int i=0; i<MAX_VALUE; i++) {
        while(a[i]!=0) {
            printf("%d ", i);
            a[i]--;
        }
    }
    return 0;
}