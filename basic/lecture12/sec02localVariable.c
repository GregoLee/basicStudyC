//
// Created by invin on 2020-02-17.
//
/*
 * ��������(Global Variable)
 * 1) ���α׷����� Ư���� ���(Block)������ ������ �� �ִ� ����
 * 2) �Լ��� ����� ������ �޸𸮿� �Ҵ�Ǿ� �Լ��� ����Ǹ� �޸𸮿��� ����
 * 3) �޸��� ����(Stack) ������ ���
 */
#include <stdio.h>

int main(void) {
    int a = 7;
    if(1) {
        int a = 5;
    }
    printf("%d", a);
    return 0;
}