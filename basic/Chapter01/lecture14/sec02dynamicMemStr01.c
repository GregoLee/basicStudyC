//
// Created by invin on 2020-02-20.
//
/*
 * 동적으로 문자열 처리하기
 * 1) 일괄적인 범위의 메모리를 모두 특정한 값으로 설정하기 위해서는 memset()을 사용
 * 2) 사용법
 *    - memset(포인터, 값, 크기);
 * 3) 한 바이트 씩 값을 저장하므로 문자열 배열의 처리 방식과 흡사하다.
 * 4) 따라서 memset() 함수는 <string.h> 라이브러리에 선언되어 있다.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    // 1) memset() 함수를 이용해 특정 범위의 메모리를 가득 채운다.
    // 2) 기존에는 단순히 반복문을 이용해 원소를 처리했으나 memset()은 일반적으로 더 빠르게 동작한다.
    char *a = malloc(100);
    memset(a, 'A', 100);
    for(int i=0; i<100; i++) {
        printf("%c ", a[i]);
    } // A A A ... A (A가 100개 출력)
    return 0;
}