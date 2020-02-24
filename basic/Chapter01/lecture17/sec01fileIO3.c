//
// Created by Jaeyoung Lee on 2020/02/24.
//
/*
 * 파일 입출력(File Input/Output)
 * 1. 프로그램이 꺼진 이후에도 데이터를 저장하기 위해서는 파일 입출력이 필요
 * 2. 파일이 실질적으로 저장되는 위치는? HDD(O), SSD(O), RAM(X), CPU(X)
 * 3. 사용법
 *    1) 파일 입출력 변수는 FILE 형식의 포인터 변수로 선언
 *    2) 파일을 열 때는 fopen() 할수를 이용
 *       - 파일 경로와 접근 방식을 설정
 *       - 파일 경로 : 기본 경로는 현재 프로그램의 경로
 *       - 접근 방식
 *         - r : 파일에 접근하여 데이터를 읽는다.
 *         - w : 파일에 접근하여 데이터를 기록한다. 이미 존재하면 덮어쓴다.
 *         - a : 파일에 접근하여 데이터를 뒤에서부터 기록한다.
 *    3) 파일을 닫을 때는 fclose() 함수를 이용
 * 4. 파일 입출력은 fprintf()와 fscanf()가 사용
 *    - fprintf(파일 포인터, 서식, 형식지정자);
 *    - fscanf(파일 포인터, 서식, 형식지정자);
 * 5. 파일 입출력의 과정
 *    1) 파일 입출력은 열고, 읽고/쓰고, 닫기의 과정을 철저히 따라야 한다.
 *    2) 파일을 열 때는 파일 포인터가 사용되며, 이는 동적으로 할당된 것이다.
 *    3) 따라서 파일 처리 이후에 파일을 닫아주지 않으면 메모리 누수가 발생한다.
 */
#include <stdio.h>
#include <stdlib.h>

// 학생 구조체 선언
typedef struct {
    char name[20];
    int score;
} Student;

// 학생 데이터 읽어 그대로 출력하기
int main(void) {
    int n, sum = 0;
    FILE *fp;
    fp = fopen("input.txt", "r");
    fscanf(fp, "%d", &n);
    Student *students = (Student*)malloc(sizeof(Student) * n);
    for(int i=0; i<n; i++) {
        fscanf(fp, "%s %d", &((students + i)->name), &((students + i)->score));
        printf("이름 : %s, 성적 : %d\n", (students + i)->name, (students + i)->score);
    }
    return 0;
}