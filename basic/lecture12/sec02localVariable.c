//
// Created by invin on 2020-02-17.
//
/*
 * ��������(Global Variable)
 * 1) ���α׷��� ��𼭵� ���� ������ ������ ���Ѵ�.
 * 2) main �Լ��� ����Ǳ⵵ ���� ���α׷��� ���۰� ���ÿ� �޸𸮿� �Ҵ�
 * 3) ���α׷��� ũ�Ⱑ Ŀ�� ���� ���� ������ ���� ���α׷��� �������� �� �ִ�.
 * 4) �޸��� ������(Data) ������ ����ȴ�.
 */
#include <stdio.h>

int a = 5;

int changeValue() {
    a = 10;
}

int main(void) {
    printf("%d\n", a);
    changeValue();
    printf("%d\n", a);
    return 0;
}