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
 *       가. PUSH
 *          (Front) |7|next| ---> |5|next| (Rear)
 *          (Front) |7|next| ---> |5|next|-(Rear)----->|4|next|
 *          (Front) |7|next| ---> |5|next|------------>|4|next| (Rear)
 *       나. POP
 *          (Front) |7|next| ---> |5|next|------------>|4|next| (Rear)
 *                        (Front) |5|next|------------>|4|next| (Rear)
 */

// 연결 리스트를 이용한 큐 구현
#include <stdio.h>
#include <stdlib.h>
#define INF 99999999

typedef struct {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
    int count;
} Queue;

void push(Queue *queue, int data) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    if(queue->count==0) {
        queue->front = node;
    } else {
        queue->rear->next = node;
    }
    queue->rear = node;
    queue->count++;
}

int pop(Queue *queue) {
    if(queue->count == 0) {
        printf("Queue Underflow 발생\n");
        return -INF;
    }
    Node *node = queue->front;
    int data = node->data;
    queue->front = node->next;
    free(node);
    queue->count--;
    return data;
}

void show(Queue *queue) {
    Node *cur = queue->front;
    printf("Queue : (Front) ---> |");
    while(cur != NULL) {
        printf("%d|", cur->data);
        cur = cur->next;
    }
    printf(" ---> (Rear)\n");
}

int main(void) {
    Queue queue;
    queue.front = queue.rear = NULL;
    queue.count = 0;
    push(&queue, 7);
    push(&queue, 5);
    push(&queue, 4);
    pop(&queue);
    push(&queue, 6);
    pop(&queue);
    show(&queue);
    return 0;
}