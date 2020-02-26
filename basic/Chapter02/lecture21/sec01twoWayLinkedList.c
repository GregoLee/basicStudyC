//
// Created by Jaeyoung Lee on 2020/02/26.
//
/*
 * 양방향 연결 리스트
 * 1. 특징
 *    1) 머리(Head)와 꼬리(Tail)를 모두 가진다.
 *    2) 각 노드는 앞 노드와 뒤 노드의 정보를 모두 저장
 *       (Head)|prev| |next|<--->|prev| |next|<--->|prev| |next|<--->|prev| |next|(Tail)
 *    3) 리스트의 앞에서부터 혹은 뒤에서부터 모두 접근할 수 있다.
 * 2. 학습 시 데이터를'오름차순'으로 저장하는 형태로 작성
 *    - 아래 코드에 덧붙여서 삽입 및 삭제 기능에서의 예외사항을 처리할 필요가 있다.
 *    - 더 이상 삭제할 원소가 없는데 삭제하는 경우 등을 체크해야 한다.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *head, *tail;

// 삽입 함수
// (Head)|prev| |next|<--->|prev|1|next|<--->|prev|2|next|<--------------------->|prev|10|next|<--->|prev| |next|(Tail)
// (Head)|prev| |next|<--->|prev|1|next|<--->|prev|2|next|<--->|prev|5|next|<--->|prev|10|next|<--->|prev| |next|(Tail)
void insert(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    Node* cur = head->next;
    while(cur->data < data && cur != tail) {
        cur = cur->next;
    }
    Node* before = cur->prev;
    before->next = node;
    node->prev = before;
    cur->prev = node;
    node->next = cur;
}

// 제거 함수
// (Head)|prev| |next|<--->|prev|1|next|<--->|prev|2|next|<--->|prev|5|next|<--->|prev|10|next|<--->|prev| |next|(Tail)
// (Head)|prev| |next|<--------------------->|prev|2|next|<--->|prev|5|next|<--->|prev|10|next|<--->|prev| |next|(Tail)
void removeFront() {
    Node* target = head->next;
    head->next = target->next;
    Node* next = target->next;
    next->prev = head;
    free(target);
}

void show() {
    Node* cur = head->next;
    while(cur != tail) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
}

int main(void) {
    head = (Node*)malloc(sizeof(Node));
    tail = (Node*)malloc(sizeof(Node));
    head->next = tail;
    head->prev = head;
    tail->next = tail;
    tail->prev = head;
    insert(2);
    insert(1);
    insert(3);
    insert(9);
    insert(7);
    removeFront();
    show();
    return 0;
}