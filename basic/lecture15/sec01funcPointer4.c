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

int(*process(char* a))(int, int) {
    printf("%s\n", a);
    return add;
}

int(*process2(char* a, int* b))(int, int) {
    printf("%s\n", a);
    return b;
}

int main(void) {
    //�Լ� �����͸� ��ȯ�Ͽ� ����ϱ�
    printf("%d\n", process("10�� 20�� ���غ��ڽ��ϴ�.")(10, 20));

    //callbackó�� Ȱ���غ���
    printf("%d\n", process2("20�� 10�� �����ڽ��ϴ�.", sub)(20, 10));

    return 0;
}