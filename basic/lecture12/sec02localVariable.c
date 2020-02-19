//
// Created by invin on 2020-02-17.
//
/*
 * 지역변수(Global Variable)
 * 1) 프로그램에서 특정한 블록(Block)에서만 접근할 수 있는 변수
 * 2) 함수가 실행될 때마다 메모리에 할당되어 함수가 종료되면 메모리에서 해제
 * 3) 메모리의 스택(Stack) 영역에 기록
 */
#include <stdio.h>

int main(void) {
    int a = 7;
    if(1) {
        int a = 5;
    }
    printf("%d", a);
    return 0;
}