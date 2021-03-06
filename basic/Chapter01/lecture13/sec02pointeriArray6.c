//
// Created by invin on 2020-02-20.
//
/*
 * 포인터 배열(Pointer Array)
 * 1) 포인터와 동일한 방식으로 동작
 * 2) 배열의 이름은 배열의 원소 중 첫번째 주소가 된다.
 * 3) 유일한 차이점이라고 하면, 포인터는 변수이며 배열의 이름은 상수이다.
 */
#include<stdio.h>

int main(void) {
    int a[2][5] = {{11111, 2222, 333, 44, 5}, {1, 22, 333, 4444, 55555}};
    int (*p)[5] = a[1];
    int i;
    for(i=0; i<5; i++) {
        printf("%d ", (*p)[i]);       // (a[1][0]~a[1][4]==p[0][0]~p[0][4]) : 1 22 333 4444 55555
        printf("%d ", p[0][i]);        // (p[0][0]~p[0][4]) : 1 22 333 4444 55555
        printf("%d ", *p[i]);         // (???) : 1 6422276 4198966 0 4199141
        printf("%d ", (*(p-1))[i]);    // (a[0][0]~a[0][4]) : 11111 2222 333 44 5
        printf("%d\n", (*(p-5))[i]);  // (???) : 1 2004502048 2004242406 1797267952 4199120
    }
    return 0;
}