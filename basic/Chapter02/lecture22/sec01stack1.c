//
// Created by invin on 2020-02-27.
//
/*
 * 스택(Stack)
 * 1. 개요
 *    1) FILO(First In Last Out) 방식의 자료구조(Data Structure)이다.
 *    2) method
 *       - PUSH : 스택에 데이터를 넣는다.
 *       - POP : 스택에서 데이터를 빼낸다.
 *               (최상단)<---> | | | | | | | | |
 *    PUSH(7) :  (최상단)<---> | | | | | | | |7|
 *    PUSH(5) :  (최상단)<---> | | | | | | |5|7|
 *    PUSH(4) :  (최상단)<---> | | | | | |4|5|7|
 *    POP() :    (최상단)<---> | | | | | | |5|7|
 *    PUSH(6) :  (최상단)<---> | | | | | |6|5|7|
 *    POP() :    (최상단)<---> | | | | | | |5|7|
 *
 *  2. 구현
 *     1) 배열을 이용
 */
#include <stdio.h>
#define SIZE 10000
#define INF 99999999

int stack[SIZE];
int top = -1;

void push(int data) {
    if(top==SIZE - 1) {
        printf("stack overflow가 발생했습니다.\n");
        return;
    }
    stack[++top] = data;
}

int pop(void) {
    if(top==-1) {
        printf("stack underflow가 발생했습니다.\n");
        return -INF;
    }
    return stack[top--];
}

void show() {
    printf("top of stack <=====> | | |");
    for(int i=top; i>=0; i--) {
        printf("%d|", stack[i]);
    }
}

int main(void) {
    push(7);
    push(5);
    push(4);
    pop();
    push(9);
    push(6);
    pop();
    show();
    return 0;
}