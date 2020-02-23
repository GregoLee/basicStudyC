//
// Created by invin on 2020-02-17.
//
/*
 * 레지스터변수(Register Variable)
 * 1) 메인 메모리 대신 CPU의 레지스터를 사용하는 변수
 * 2) 레지스터는 매우 한정되어 있으므로 실제로 레지스터에서 처리될 지는 장담할 수 없다.
 */
#include <stdio.h>
int main(void) {
    register int a = 10, i;
    for(i=0; i<a; i++) {
        printf("%d ", i);
    }
    return 0;
}