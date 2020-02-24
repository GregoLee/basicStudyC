//
// Created by invin on 2020-02-20.
//
/*
 * 포인터 배열(Pointer Array)
 * 1) 포인터와 동일한 방식으로 동작
 * 2) 배열의 이름은 배열의 원소 중 첫번째 주소가 된다.
 * 3) 유일한 차이점이라고 하면, 포인터는 변수이며 배열의 이름은 상수이다.
 */
#include<stdio.h>

int main(void) {
    // 1) 포인터는 연산을 통해 자료형의 크기만큼 이동한다.
    // 2) 정수(int)형 포인터는 4바이트(4Bytes)씩 이동한다.
    int a[5] = {11111,2222,333,44,5};
    int i;

    for(i=0; i<5; i++) {
        printf("%d ", a + i); // (주소값) : 6422280, 6422284, 6422288, 6422292, 9422296
        printf("%d ", *(a + i)); // (value) : 11111, 2222, 333, 44, 5 --- 배열을 포인터처럼 사용해 각 원소에 접근할 수 있다.
        printf("%d\n", a[i]); // (value) : 11111, 2222, 333, 44, 5
    }

    printf("\n");

    // 3) 크기가 10인 double형 배열을 선언했을 때 배열의 시작 주소가 X라 하자.
    // 4) 이 때 배열의 마지막 원소의 주소는 몇일까?
    double b[10];
    printf("%d, %d\n", b, b+9); // (X, X+72)
    return 0;
}