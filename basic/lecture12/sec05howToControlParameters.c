//
// Created by invin on 2020-02-17.
//
/*
 * 함수의 매개변수
 * 1) 함수를 호출할 때 함수에 필요한 데이터를 매개변수로 전달
 * 2) 전달 방식은 다음과 같음
 *    가) 값에 의한 전달 (Call by Value) : 값을 전달, 함수 내에서 변수가 새롭게 생성
 *    나) 참조에 의한 전달 (Call by Reference) : 주소를 전달, 원래의 변수 자체에 접근 가능
 */
#include <stdio.h>

// 2-가) Call by Value
//   - 두 개의 값을 넣으면 새롭게 두 변수가 메모리 내에 할당되어 처리
//   - 원래 변수의 값에는 영향을 미치지 않음
void add_by_value(int a, int b) {
    a = a + b;
}

// 2-나) Call by Reference
//   - 변수의 주소를 전달
//   - 원래 변수의 값에 접근하여 값을 변경할 수 있음
//   - '포인터(pointer)' 변수를 전달
void add_by_reference(int *a, int b) {
    *a = (*a) + b;
}

int main(void) {
    int a = 7;
    add_by_value(a, 10);
    printf("%d\n", a);

    add_by_reference(&a, 10);
    printf("%d\n", a);

    return 0;
}