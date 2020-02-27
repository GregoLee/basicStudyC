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
 *     2) 연결 리스트를 이용
 */
#include <stdio.h>
#include <stdlib.h>
#define INF 99999999

typedef struct {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *top;
} Stack;

void push(Stack *stack, int data) {
    Node *node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = stack->top;
    stack->top = node;
}

int pop(Stack *stack) {
    if(stack->top == NULL) {
        printf("Stack underflow가 발생했습니다.\n");
        return -INF;
    }
    Node *node = stack->top;
    int data = node->data;
    stack->top = node->next;
    free(node);
    return data;
}

void show(Stack *stack) {
    Node *cur = stack->top;
    printf("top of stack <=====> |");
    while(cur != NULL) {
        printf("%d|", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

// 연결 리스트를 활용하여 Stack을 작성할 수 있다.
// 아래 두 가지 모두 정상 동작한다.
int main(void) {
    Stack *s = (Stack*) malloc(sizeof(Stack));
    s->top = NULL;
    push(s, 10);
    push(s, 5);
    push(s, 7);
    push(s, 2);
    show(s);
    pop(s);
    show(s);
    push(s, 21);
    push(s, 12);
    push(s, 9);
    show(s);
    push(s, 19);
    show(s);
    pop(s);
    show(s);

    /*
    Stack s;
    s.top = NULL;
    push(&s, 10);
    push(&s, 5);
    push(&s, 7);
    push(&s, 2);
    show(&s);
    pop(&s);
    show(&s);
    push(&s, 21);
    push(&s, 12);
    push(&s, 9);
    show(&s);
    push(&s, 19);
    show(&s);
    pop(&s);
    show(&s);
    */
    return 0;
}