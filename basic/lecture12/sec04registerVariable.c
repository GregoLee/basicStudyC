//
// Created by invin on 2020-02-17.
//
/*
 * �������ͺ���(Register Variable)
 * 1) ���� �޸� ��� CPU�� �������͸� ����ϴ� ����
 * 2) �������ʹ� �ſ� �����Ǿ� �����Ƿ� ������ �������Ϳ��� ó���� ���� ����� �� ����.
 */
#include <stdio.h>
int main(void) {
    register int a = 10, i;
    for(i=0; i<a; i++) {
        printf("%d ", i);
    }
    return 0;
}