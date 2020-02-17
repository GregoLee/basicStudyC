//
// Created by invin on 2020-02-17.
//
#include <stdio.h>

int main(void) {
    char a[100];
    // gets() 함수는 버퍼의 크기를 벗어나도 입력을 받아버림.
    gets(a);

    // 1. C11 표준부터는 버퍼의 크기를 철저히 지키는 gets_s() 함수가 추가되었다.
    // 2. gets_s()를 이용하는 경우 범위를 넘으면 그 즉시 런타임(Runtime)오류 발생
    // 3. gcc에서는 구동이 안될 수 있으니 참조하길...
    //gets_s(a, sizeof(a));
    printf("%s\n", a);
    return 0;
}