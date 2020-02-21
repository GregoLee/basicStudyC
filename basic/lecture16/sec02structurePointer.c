//
// Created by invin on 2020-02-21.
//
/*
 * 구조체(Structure)
 * 1) 구조체를 활용하여 커스텀 자료형을 만든다.
 *    - 여러 개의 변수를 묶어 하나의 객체를 표현하고자 할 때 구조체를 사용
 *    - struct 구조체명 {
 *        자료형1 변수명1;
 *        자료형2 변수명2;
 *        ...
 *      }
 * 2) 케릭터, 몬스터, 학생, 좌표 등 다양한 객체들을 표현할 수 있다.
 */
#include <stdio.h>
#include <string.h>

typedef struct { // 학생 구조체 정의
    char studentId[20];
    char name[20];
    int grade;
    char major[51];
} Student;

int main(void) {
    // 구조체가 포인터 변수로 사용되는 경우 내부 변수에 접근할 때 화살표(->)를 사용한다.
    Student *s = malloc(sizeof(Student));
    strcpy(s->studentId, "2007231115");  // 구조체 포인터 변수에 접근
    strcpy(s->name, "Jaeyoung Lee");
    s->grade = 4;
    strcpy(s->major, "Economy");

    // 구조체 내용 출력
    printf("ID : %s\n", s->studentId);
    printf("Name : %s\n", s->name);
    printf("Grade : %d\n", s->grade);
    printf("Major : %s\n", s->major);
    return 0;
}