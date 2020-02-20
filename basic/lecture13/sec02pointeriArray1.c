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
    int a = 10;
    int b[10];
    b = &a; //배열의 이름이 변수인지 상수인지 확인할 수 있다.
    return 0;
}