//
// Created by invin on 2020-02-17.
//
#include <stdio.h>

int main(void) {
    char a[100];
    // gets() 함수는 버퍼의 크기를 벗어나도 입력을 받아버림.
    gets(a);
    printf("%s\n", a);
    return 0;
}