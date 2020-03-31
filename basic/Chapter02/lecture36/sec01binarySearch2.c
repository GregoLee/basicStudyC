//
// Created by Jaeyoung Lee on 2020/03/31.
//
/*
 * 이진 탐색 트리 (Binary Search Tree)
 * 2. 삭제
 *    1) 자식이 없는 경우 : 삭제할 노드의 자식이 없는 경우 단순히 제거하면 된다.
 *                         30 ⬅                 삭제할 원소 : 23
 *               ┏━━━━━━━━━┛┗━━━━━━━━━━┓
 *              17                     48
 *        ┏━━━━━┛┗━━━━━┓         ┏━━━━━┛
 *        5            23       37
 *
 *                         30  ︎                  삭제할 원소 : 23
 *               ┏━━━━━━━━━┛┗━━━━━━━━━━┓
 *              17 ⬅                  48
 *        ┏━━━━━┛┗━━━━━┓         ┏━━━━━┛
 *        5            23       37
 *
 *                         30                   삭제할 원소 : 23
 *               ┏━━━━━━━━━┛┗━━━━━━━━━━┓
 *              17                     48
 *        ┏━━━━━┛┗━━━━━┓         ┏━━━━━┛
 *        5            23 ⬅     37
 *
 *                         30                   삭제할 원소 : 23
 *               ┏━━━━━━━━━┛┗━━━━━━━━━━┓
 *              17                     48
 *        ┏━━━━━┛                ┏━━━━━┛
 *        5                     37
 *
 *    2) 자식이 하나만 존재하는 경우 : 삭제할 노드의 자리에 자식 노드를 넣는다.
 *                         30 ⬅                 삭제할 원소 : 48
 *               ┏━━━━━━━━━┛┗━━━━━━━━━━┓
 *              17                     48
 *        ┏━━━━━┛┗━━━━━┓         ┏━━━━━┛
 *        5            23       37
 *
 *                         30  ︎                  삭제할 원소 : 48
 *               ┏━━━━━━━━━┛┗━━━━━━━━━━┓
 *              17                     48 ⬅
 *        ┏━━━━━┛┗━━━━━┓         ┏━━━━━┛
 *        5            23       37
 *
 *                         30                   삭제할 원소 : 48
 *               ┏━━━━━━━━━┛┗━━━━━━━━━━┓
 *              17                     37
 *        ┏━━━━━┛┗━━━━━┓
 *        5            23
 *
 *    3) 자식이 둘 다 존재하는 경우 : 삭제할 노드의 자리에 다음으로 큰 노드를 넣는다.
 *                         30 ⬅                 삭제할 원소 : 30
 *               ┏━━━━━━━━━┛┗━━━━━━━━━━┓
 *              17                     48
 *        ┏━━━━━┛┗━━━━━┓         ┏━━━━━┛
 *        5            23       37 ⬅
 *
 *                         37  ︎                  삭제할 원소 : 30
 *               ┏━━━━━━━━━┛┗━━━━━━━━━━┓
 *              17                     48
 *        ┏━━━━━┛┗━━━━━┓
 *        5            23
 *
 */
// 이진 탐색 트리의 정의
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    struct Node* leftChild;
    struct Node* rightChild;
} Node;

// 이진 탐색 트리의 삽입
Node* insertNode(Node* root, int data) {
    if(root == NULL) {
        root = (Node*)malloc(sizeof(Node));
        root->leftChild = root->rightChild = NULL;
        root->data = data;
        return root;
    }
    else {
        if(root->data > data) {
            root->leftChild = insertNode(root->leftChild, data);
        } else {
            root->rightChild = insertNode(root->rightChild, data);
        }
    }
    return root;
}

// 이진 탐색 트리의 탐색
Node* searchNode(Node* root, int data) {
    if(root==NULL) return NULL;
    if(root->data==data) return root;
    else if(root->data > data) return searchNode(root->leftChild, data);
    else return searchNode(root->rightChild, data);
}

// 이진 탐색 트리의 순회 : 중위 순회
void preorder(Node* root) {
    if(root==NULL) return;
    printf("%d ", root->data);
    preorder(root->leftChild);
    preorder(root->rightChild);
}

// 이진 탐색 트리의 가장 작은 원소 찾기 함수
Node* findMinNode(Node* root) {
    Node* node = root;
    while(node->leftChild != NULL) {
        node = node->leftChild;
    }
    return node;
}

// 이진 탐색 트리의 삭제 함수
Node* deleteNode(Node* root, int data) {
    Node* node = NULL;
    if(root==NULL) return NULL;
    else if(root->data > data) root->leftChild = deleteNode(root->leftChild, data);
    else if(root->data < data) root->rightChild = deleteNode(root->rightChild, data);
    else {
        if(root->leftChild != NULL && root->rightChild != NULL) {
            node = findMinNode(root->rightChild);
            root->data = node->data;
            root->rightChild = deleteNode(root->rightChild, node->data);
        } else {
            node = root->leftChild != NULL ? root->leftChild : root->rightChild;
            free(root);
            return node;
        }
    }
    return root;
}

// 이진 탐색 트리 이용해보기
int main(void) {
    Node* root = NULL;
    root = insertNode(root, 30);
    root = insertNode(root, 17);
    root = insertNode(root, 48);
    root = insertNode(root, 5);
    root = insertNode(root, 23);
    root = insertNode(root, 37);
    root = insertNode(root, 50);
    root = deleteNode(root, 23);
    preorder(root);
    return 0;
}