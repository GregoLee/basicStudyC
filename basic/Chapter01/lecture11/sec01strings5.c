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

    //strlen() : 문자열 길이 반환
    printf("Length : %d\n", strlen(a));

    //strcmp() : 문자열 1이 문자열 2보다 사전적으로 앞에 있으면 -1, 뒤에 있으면 1을 반환
    printf("Compare : %d\n", strcmp(a, b));

    //strcpy() : 문자열을 복사
    strcpy(c, a);
    printf("copy : %s\n", c);

    //strcat() : 문자열 1에 문자열 2를 더한다.
    strcat(d, a);
    printf("concat : %s\n", d);

    //strstr()  : 문자열 1개에 문자열 2가 어떻게 포함되어 있는지를 반환
    printf("strstr : %s\n", strstr(a, e));

    return 0;
}