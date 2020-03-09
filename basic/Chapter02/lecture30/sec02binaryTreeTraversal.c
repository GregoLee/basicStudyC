//
// Created by invin on 2020-03-09.
//
/*
 * 이진 트리의 순회 (Traversal)
 *                         30
 *                ┌━━━━━━━┘ └━━━━━━━┐
 *                17               48
 *            ┌━━┘ └━━┐        ┌━━┘ └━━┐
 *            5      23        37     50
 * 1. 전위 순회 (Preorder Traversal)
 *    ; 자기 자신 출력 -> 왼쪽 자식 노드 방문 -> 오른쪽 자식 노드 방문
 *      30 - 17 - 5 - 23 - 48 - 37 - 50
 *
 * 2. 중위 순회 (Inorder Traversal)
 *    ; 왼쪽 자식 노드 방문 -> 자기 자신 출력 -> 오른쪽 자식 노드 방문
 *      5 - 17 - 23 - 30 - 37 - 48 - 50
 *
 * 3. 후위 순회 (Postorder Traversal)
 *    ; 왼쪽 자식 노드 방문 -> 오른쪽 자식 노드 방문 -> 자기 자신 출력
 *      5 - 23 - 17 - 37 - 50 - 48 -30
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

// 전위 순회 (Preorder Traversal)
void preorder(Node* root) {
    if(root) {
        printf("%d ", root->data);
        preorder(root->leftChild);
        preorder(root->rightChild);
    }
}

// 중위 순회 (Inorder Traversal)
void inorder(Node* root) {
    if(root) {
        inorder(root->leftChild);
        printf("%d ", root->data);
        inorder(root->rightChild);
    }
}

// 후위 순회 (Postorder Traversal)
void postorder(Node* root) {
    if(root) {
        postorder(root->leftChild);
        postorder(root->rightChild);
        printf("%d ", root->data);
    }
}

int main(void) {
    Node* n7 = initNode(50, NULL, NULL);
    Node* n6 = initNode(37, NULL, NULL);
    Node* n5 = initNode(23, NULL, NULL);
    Node* n4 = initNode(5, NULL, NULL);
    Node* n3 = initNode(48, n6, n7);
    Node* n2 = initNode(17, n4, n5);
    Node* n1 = initNode(30, n2, n3);
    preorder(n1);
    printf("\n");
    inorder(n1);
    printf("\n");
    postorder(n1);
    return 0;
}