//
// Created by invin on 2020-02-17.
//
#include <stdio.h>

int main(void) {
    char a[100];
    // gets() �Լ��� ������ ũ�⸦ ����� �Է��� �޾ƹ���.
    gets(a);

    // 1. C11 ǥ�غ��ʹ� ������ ũ�⸦ ö���� ��Ű�� gets_s() �Լ��� �߰��Ǿ���.
    // 2. gets_s()�� �̿��ϴ� ��� ������ ������ �� ��� ��Ÿ��(Runtime)���� �߻�
    // 3. gcc������ ������ �ȵ� �� ������ �����ϱ�...
    //gets_s(a, sizeof(a));
    printf("%s\n", a);
    return 0;
}