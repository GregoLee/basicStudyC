//
// Created by invin on 2020-02-17.
//
#include <stdio.h>

int main(void) {
    char a[100];
    // gets() �Լ��� ������ ũ�⸦ ����� �Է��� �޾ƹ���.
    gets(a);
    printf("%s\n", a);
    return 0;
}