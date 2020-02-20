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

int(*process(char* a))(int, int) {
    printf("%s\n", a);
    return add;
}

int(*process2(char* a, int* b))(int, int) {
    printf("%s\n", a);
    return b;
}

int main(void) {
    //함수 포인터를 반환하여 사용하기
    printf("%d\n", process("10과 20을 더해보겠습니다.")(10, 20));

    //callback처럼 활용해보기
    printf("%d\n", process2("20과 10을 빼보겠습니다.", sub)(20, 10));

    return 0;
}