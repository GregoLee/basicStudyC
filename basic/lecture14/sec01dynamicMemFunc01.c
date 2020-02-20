//
// Created by invin on 2020-02-20.
//
/*
 * 동적 메모리 할당 함수 (Dynamic Memory Allocate Function : malloc() )
 * 1) C언어에서는 malloc() 함수를 이용해 원하는 만큼의 메모리 공간을 확보할 수 있다.
 * 2) malloc() 함수는 메모리 할당에 성공하면 주소를 반환하고, 그렇지 않으면 NULL을 반환
 * 3) malloc() 함수는 <stdlib.h> 라이브러리에 정의되어 있음
 * 4) 사용법
 *    malloc(할당할 바이트 크기);
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // 동적 메모리 할당을 수행할 때마다 할당되는 포인터의 주소는 변칙적이다.
    int *a = malloc(sizeof(int));
    printf("%d\n", a);   //10229144
    a = malloc(sizeof(int));
    printf("%d\n", a);   //10239824
    return 0;
}

