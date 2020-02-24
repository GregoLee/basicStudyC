//
// Created by Jaeyoung Lee on 2020/02/21.
//
/*
 * 함수 포인터
 * 3) 특정한 함수의 반환 자료형을 지정하는 방식으로 선언할 수 있다.
 * 4) 이를 이용하면 형태가 같은 서로 다른 기능의 함수를 선택적으로 사용할 수 있다.
 * 5) 사용법
 *    - 반환 자료형(*이름)(매개변수) = 함수명;
 */
#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

char charFunction() {
    return 'A';
}

int main(void) {
    //매개변수 및 반환 자료형이 있는 함수 포인터
    int(*fp)(int, int) = add;
    printf("%d\n", fp(10, 3));
    fp = sub;
    printf("%d\n", fp(10, 3));

    char(*fp1)() = charFunction;
    printf("%c\n",fp1());

    //반환자료형을 일치하지 않고도 함수포인터를 실행할 수 있으나, 오류인지 아닌지 실행하기 전까지 확인할 도리가 없다.
    fp1 = add;
    printf("%c\n",fp1());

    return 0;
}