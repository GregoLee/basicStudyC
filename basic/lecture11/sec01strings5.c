//
// Created by invin on 2020-02-17.
//
#include <stdio.h>

int main(void) {
    char a[40] = "Jaeyoung Lee";
    char b[20] = "Gildong Hong";
    char c[20] = "My Name";
    char d[20] = "My Name is ";
    char e[10] = "you";

    //strlen() : ���ڿ� ���� ��ȯ
    printf("Length : %d\n", strlen(a));

    //strcmp() : ���ڿ� 1�� ���ڿ� 2���� ���������� �տ� ������ -1, �ڿ� ������ 1�� ��ȯ
    printf("Compare : %d\n", strcmp(a, b));

    //strcpy() : ���ڿ��� ����
    strcpy(c, a);
    printf("copy : %s\n", c);

    //strcat() : ���ڿ� 1�� ���ڿ� 2�� ���Ѵ�.
    strcat(d, a);
    printf("concat : %s\n", d);

    //strstr()  : ���ڿ� 1���� ���ڿ� 2�� ��� ���ԵǾ� �ִ����� ��ȯ
    printf("strstr : %s\n", strstr(a, e));

    return 0;
}