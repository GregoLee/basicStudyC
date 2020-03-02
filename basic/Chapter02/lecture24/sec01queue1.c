//
// Created by invin on 2020-03-02.
//
/*
 * 큐(Queue)
 * 1. 개요
 *    1) FIFO(First In First Out)인 자료 구조(Data Structure)이다.
 *    2) 스케줄링, 탐색 알고리즘 등에서 다방면으로 활용
 *    3) method
 *       - PUSH : 큐에 데이터를 넣음
 *       - POP : 큐에서 데이터를 빼낸다.
 *               (출구)<--- | | | | | | | | | <--- (입구)
 *    PUSH(7) :  (출구)<--- |7| | | | | | | | <--- (입구)
 *    PUSH(5) :  (출구)<--- |7|5| | | | | | | <--- (입구)
 *    PUSH(4) :  (출구)<--- |7|5|4| | | | | | <--- (입구)
 *    POP() :    (출구)<--- | |5|4| | | | | | <--- (입구)
 *    PUSH(6) :  (출구)<--- | |5|4|6| | | | | <--- (입구)
 *    POP() :    (출구)<--- | | |4|6| | | | | <--- (입구)
 * 2. 구현
 *    1) 배열을 이용
 *    2) 연결 리스트를 이용
 */

// 배열을 이용한 큐 구현
#include <stdio.h>
#define SIZE 10000
#define INF 99999999

int queue[SIZE];
int front = 0;
int rear = 0;

void push(int data) {
    if(rear >= SIZE) {
        printf("Queue Overflow가 발생했습니다.\n");
        return;
    }
    queue[rear++] = data;
}

int pop() {
    if(front == rear) {
        printf("Queue Underflow가 발생했습니다.\n");
        return -INF;
    }
    return queue[front++];
}

void show() {
    printf("Queue : (Front) ---> |");
    for(int i=front; i<rear; i++) {
        printf("%d|", queue[i]);
    }
    printf(" ---> (Rear)\n");
}

int main(void) {
    push(7);
    push(5);
    push(4);
    pop();
    push(6);
    pop();
    show();
    return 0;
}