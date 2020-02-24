//
// Created by invin on 2020-02-17.
//
/*
 * 정적변수(Static Variable)
 * 1) 특정한 블록에서만 접근할 수 있는 변수
 * 2) 프로그램이 실행될 때 메모리에 할당되어 프로그램이 종료되면 메모리에서 해제
 * 3) 메모리의 데이터(Data) 영역에 적재
 */
#include <stdio.h>
void process() {
    static int a = 5;
    a += 1;
    printf("%d\n", a);
}

int main(void) {
    process();
    process();
    process();
    return 0;
}