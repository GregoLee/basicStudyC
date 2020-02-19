//
// Created by invin on 2020-02-17.
//
/*
 * �Լ��� �Ű�����
 * 1) �Լ��� ȣ���� �� �Լ��� �ʿ��� �����͸� �Ű������� ����
 * 2) ���� ����� ������ ����
 *    ��) ���� ���� ���� (Call by Value) : ���� ����, �Լ� ������ ������ ���Ӱ� ����
 *    ��) ������ ���� ���� (Call by Reference) : �ּҸ� ����, ������ ���� ��ü�� ���� ����
 */
#include <stdio.h>

// 2-��) Call by Value
//   - �� ���� ���� ������ ���Ӱ� �� ������ �޸� ���� �Ҵ�Ǿ� ó��
//   - ���� ������ ������ ������ ��ġ�� ����
void add_by_value(int a, int b) {
    a = a + b;
}

// 2-��) Call by Reference
//   - ������ �ּҸ� ����
//   - ���� ������ ���� �����Ͽ� ���� ������ �� ����
//   - '������(pointer)' ������ ����
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