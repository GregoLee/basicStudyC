//
// Created by pharosinfo on 2020-03-10.
//
/*
 * 이진 탐색 (Binary Search)
 * 1. 개요
 *    1) 배열 내부 데이터가 "이미 정렬되어 있는 상황에서 사용 가능"한 알고리즘
 *    2) 탐색 범위를 절반씩 좁혀가며 데이터를 탐색하는 특징
 *       ; 한 번 확인할 때마다 보아야 하는 원소의 개수가 절반씩 줄어든다
 *    3) 시간 복잡도 : O(log N)
 *       찾을 원소 : 37
 *       INDEX  0   1   2   3   4   5   6   7   8
 *       원소   15  27  37  46  57* 69  73  85  98
 *
 *       INDEX  0   1   2   3   4   5   6   7   8
 *       원소   15  27* 37  46  57- 69- 73- 85- 98-
 *
 *       INDEX  0   1   2   3   4   5   6   7   8
 *       원소   15- 27- 37* 46  57- 69- 73- 85- 98-
 */
#include <stdio.h>
#define MAX_SIZE 100000

int a[MAX_SIZE];
int founded = -1;

int search(int start, int end, int target) {
    if(start>end) return -9999;
    int mid = (start+end) / 2;
    if(a[mid]==target) return mid;
    else if(a[mid]<target) return search(mid+1, end, target);
    else return search(start, mid-1, target);
}

int main(void) {
    int n, target;
    scanf("%d %d", &n, &target);
    for(int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    founded = search(0, n-1, target);
    if(target<0) printf("원소를 찾을 수 없습니다.\n");
    else printf("원소는 %d번째에 있습니다.\n", founded+1);
    return 0;
}