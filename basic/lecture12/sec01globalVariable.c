//
// Created by invin on 2020-02-17.
//
/*
 * 전역변수(Global Variable)
 * 1) 프로그램의 어디서든 접근 가능한 변수를 말한다.
 * 2) main 함수가 실행되기도 전에 프로그램의 시작과 동시에 메모리에 할당
 * 3) 프로그램의 크기가 커질 수록 전역 변수로 인해 프로그램이 복잡해질 수 있다.
 * 4) 메모리의 데이터(Data) 영역에 적재된다.
 */
#include <stdio.h>

int a = 5;

int changeValue() {
    a = 10;
}

int main(void) {
    printf("%d\n", a);
    changeValue();
    printf("%d\n", a);
    return 0;
}