//
// Created by Jaeyoung Lee on 2020/02/21.
//
/*
 * �Լ� ������
 * 3) Ư���� �Լ��� ��ȯ �ڷ����� �����ϴ� ������� ������ �� �ִ�.
 * 4) �̸� �̿��ϸ� ���°� ���� ���� �ٸ� ����� �Լ��� ���������� ����� �� �ִ�.
 * 5) ����
 *    - ��ȯ �ڷ���(*�̸�)(�Ű�����) = �Լ���;
 */
#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

char charFunction() {
    return 'A';
}

int main(void) {
    //�Ű����� �� ��ȯ �ڷ����� �ִ� �Լ� ������
    int(*fp)(int, int) = add;
    printf("%d\n", fp(10, 3));
    fp = sub;
    printf("%d\n", fp(10, 3));

    char(*fp1)() = charFunction;
    printf("%c\n",fp1());

    //��ȯ�ڷ����� ��ġ���� �ʰ� �Լ������͸� ������ �� ������, �������� �ƴ��� �����ϱ� ������ Ȯ���� ������ ����.
    fp1 = add;
    printf("%c\n",fp1());

    return 0;
}