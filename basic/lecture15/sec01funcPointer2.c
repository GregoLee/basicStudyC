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

void myFunction() {
    printf("It's my function.\n");
}

void yourFunction() {
    printf("It's your function.\n");
}

int main(void) {
    //�Ű����� �� ��ȯ�ڷ����� ���� �Լ� ������
    void(*fp)() = myFunction;
    fp();
    fp = yourFunction;
    fp();

    return 0;
}