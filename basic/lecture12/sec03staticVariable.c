//
// Created by invin on 2020-02-17.
//
/*
 * ��������(Static Variable)
 * 1) Ư���� ��Ͽ����� ������ �� �ִ� ����
 * 2) ���α׷��� ����� �� �޸𸮿� �Ҵ�Ǿ� ���α׷��� ����Ǹ� �޸𸮿��� ����
 * 3) �޸��� ������(Data) ������ ����
 */
#include <stdio.h>
void process() {
    static int a = 5;
    a += 1;
    printf("%d\n", a);
}

int main(void) {
    process();
    process();
    process();
    return 0;
}