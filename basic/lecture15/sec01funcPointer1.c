//
// Created by Jaeyoung Lee on 2020/02/21.
//
/*
 * 함수 포인터
 * 1) C언어에서는 함수의 이름을 이용해 특정한 함수를 호출한다.
 * 2) 함수 이름은 메모리 주소를 반환한다.
 */
#include <stdio.h>

void function() {
    printf("It's my function.");
}

int main(void) {
    printf("%d\n", function);
    return 0;
}