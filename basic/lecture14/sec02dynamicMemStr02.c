//
// Created by invin on 2020-02-20.
//
/*
 * 동적 메모리 할당의 다양한 예제
 * 참조 : https://codingdog.tistory.com/entry/c%EC%96%B8%EC%96%B4-malloc-%ED%95%A8%EC%88%98-%EB%8F%99%EC%A0%81-%ED%95%A0%EB%8B%B9-%EA%B0%84%EB%8B%A8%ED%95%98%EA%B2%8C-%EC%9D%B4%ED%95%B4%ED%95%B4-%EB%B4%85%EC%8B%9C%EB%8B%A4
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    //메모리 할당
    int n = 3;
    int **p = (int**)malloc(sizeof(int*)*n);

    int m = 5;
    for(int i=0; i<m; i++) {
        *(p+i) = (int*)malloc(sizeof(int)*m);
    }

    //값 할당
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            *(*(p+i)+j) = i * m + j;
        }
    }
    //출력
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            printf("%d ", *(*(p+i)+j) );
        }
        printf("\n");
    }
    printf("\n");
    for(int i=0; i<n; i++) {
        printf("%d\n", (p + i) );
        for(int j=0; j<m; j++) {
            printf("%d ", *(p+i)+j );
        }
        printf("\n");
    }
    return 0;
}