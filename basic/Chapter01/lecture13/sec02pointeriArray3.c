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
    int a[5] = {100,2,3,4,5};
    int *b = &a[0];  //6422280 (&a[0]==b), 배열의 이름은 배열의 원소 중 첫번째 원소의 주소를 나타낸다.
    printf("%d\n", b[2]);
    printf("%d\n", *b);
    printf("%d\n", b);
    return 0;
}