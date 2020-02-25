//
// Created by Jaeyoung Lee on 2020/02/26.
//
/*
 * 연결리스트 - "삽입과 삭제가 많은 경우에서 효율적"
 * 1. 필요성
 *    1) 일반적으로 배열을 사용하여 데이터를 순차적으로 저장하고, 나열할 수 있다.
 *    2) 배열을 사용하는 경우 메모리 공간이 불필요하게 낭비 될 수 있다.
 * 2. 구현방법
 *    1) 구조체와 포인터를 함께 사용하여 구현
 *    2) 리스트의 중간 지점에 노드를 추가하거나 삭제할 수 있어야 한다.
 *    3) 필요할 때마다 메모리 공간을 할당 받는다.
 * 3. 형태
 *    1) 단일 연결 리스트는 다음과 같은 형태로 나타낼 수 있다.
 *       |data|next|--->|data|next|--->|data|next|
 *    2) 포인터를 이용해 단방향적으로 다음 노드를 가리킨다.
 *    3) 일반적으로 연결 리스트의 시작 노드를 헤드(Head)라고 하며 별도로 관리한다.
 *    4) 다음 노드가 없는 끝 노드의 다음 위치 값으로는 NULL을 넣는다.
 *       (Head)|    |next|--->|data|next|--->|data|next|--->NULL
 *       (Head)|    |next|--->| 1 |next|--->| 2 |next|--->NULL
 * 4. 특징
 *    1) 삽입과 삭제가 배열에 비해서 간단하다는 장점이 있다.
 *    2) 배열과 다르게 특정 인덱스로 즉시 접근하지 못하며, 원소를 차례대로 검색해야 한다.
 *    3) 추가적인 포인터 변수가 사용되므로 메모리 공간이 낭비된다.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    struct Node *next;
} Node;

Node *head;

void addFront(int data) {
    Node *node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = head->next;
    head->next = node;
}

void removeFront() {
    Node *front = head->next;
    head->next = front->next;
    free(front);
}

void freeAll() {
    Node *cur = head->next;
    while(cur != NULL) {
        Node *next = cur->next;
        free(cur);
        cur = next;
    }
    head->next = NULL;
}

void showAll() {
    Node *cur = head->next;
    while(cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
}

int main(void) {
    head = (Node*) malloc(sizeof(Node));
    head->next = NULL;
    addFront(2);
    addFront(1);
    addFront(7);
    addFront(9);
    addFront(8);
    removeFront();
    showAll();
    freeAll();
    showAll();
    return 0;
}