//
// Created by invin on 2020-03-09.
//
/*
 * 이진 트리의 구현 및 순회
 * 1. 포인터를 이용하여 구현하면 효과적인 데이터 관리가 가능하다.
 *             부모
 *          ┌━━┘ └━━┐
 *    왼쪽자식    오른쪽자식
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    struct Node *leftChild;
    struct Node *rightChild;
} Node;

Node* initNode(int data, Node* leftChild, Node* rightChild) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->leftChild = leftChild;
    node->rightChild = rightChild;
    return node;
}