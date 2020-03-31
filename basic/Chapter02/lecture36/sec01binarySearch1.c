//
// Created by Jaeyoung Lee on 2020/03/31.
//
/*
 * 이진 탐색 트리 (Binary Search Tree)
 * 1. 개요
 *    1) 이진 탐색(Binary Search)이 항상 동작하도록 구현하여 탐색 속도를 극대화 시킨 자료구조를 이진 탐색 트리라고 한다.
 *    2) 이진 탐색 트리에서는 항상 부모 노드가 왼쪽 자식보다는 크고, 오른쪽 자식보다는 작다.
 *    3) 이진 탐색 트리 (Binary Search Tree) 에서는 한 번 확인할 때마다 보아야 하는 원소의 개수가 절반씩 줄어든다는 점에서 '완전 이진 트리'인 경우 탐색 시간에 O(log N)의 시간 복잡도를 가진다.
 *    4) 이진 탐색 트리에서 탐색을 할 때는 찾고자 하는 값이 부모 노드보다 작을 경우 왼쪽 자식으로, 찾고자 하는 값이 부모 노드보다 클 경우 오른쪽 자식으로 이어 나가면서 방문한다.
 *                         30 ⬅                 찾을 원소 : 37
 *               ┏━━━━━━━━━┛┗━━━━━━━━━━┓
 *              17                     48
 *        ┏━━━━━┛┗━━━━━┓         ┏━━━━━┛┗━━━━━┓
 *        5            23       37            50
 *
 *                         30  ︎                 찾을 원소 : 37
 *               ┏━━━━━━━━━┛┗━━━━━━━━━━┓
 *              17                     48  ⬅
 *        ┏━━━━━┛┗━━━━━┓         ┏━━━━━┛┗━━━━━┓
 *        5            23       37            50
 *
 *                         30                  찾을 원소 : 37
 *               ┏━━━━━━━━━┛┗━━━━━━━━━━┓
 *              17                     48
 *        ┏━━━━━┛┗━━━━━┓         ┏━━━━━┛┗━━━━━┓
 *        5            23       37 ⬅          50
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
    preorder(root);
    return 0;
}