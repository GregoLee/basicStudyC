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

void myFunction() {
    printf("It's my function.\n");
}

void yourFunction() {
    printf("It's your function.\n");
}

int main(void) {
    //매개변수 및 반환자료형이 없는 함수 포인터
    void(*fp)() = myFunction;
    fp();
    fp = yourFunction;
    fp();

    return 0;
}