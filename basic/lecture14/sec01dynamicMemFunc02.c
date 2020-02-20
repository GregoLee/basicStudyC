//
// Created by invin on 2020-02-20.
//
/*
 * 동적 메모리 할당 함수 (Dynamic Memory Allocate Function : malloc() )
 * 5) 동적으로 할당된 변수는 <힙(Heap) 영역>에 저장된다.
 * 6) 전통적인 C언어에서는 스택(Stack)에 선언된 변수는 따로 메모리 해제를 해주지 않아도 된다.
 * 7) 반면에 동적으로 할당된 변수는 반드시 free() 함수로 메모리 해제를 해주어야 한다.
 * 8) 메모리 해제를 하지 않으면 메모리 내의 프로세스 무게가 더해져 언젠가는 오류가 발생
 * 9) 메모리 누수(Memory Leak) 방지는 코어 개발자의 핵심 역량
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // 1) 할당한 메모리를 해제한 뒤에 다시 할당 받아 사용해보자.
    // 2) 이 경우 동일한 메모리 주소를 할당 받을 확률이 높다.
    int *a = malloc(sizeof(int));
    printf("%d\n", a);   //12195224
    free(a);
    a = malloc(sizeof(int));
    printf("%d\n", a);   //12195224
    free(a);
    return 0;
}

