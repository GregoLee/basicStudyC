//
// Created by Jaeyoung Lee on 2020/03/13.
//
/*
 * 깊이 우선 탐색 (Depth First Search)
 * 1. 개요
 *    1) 탐색을 함에 있어서 보다 깊은 것을 우선적으로 하여 탐색하는 알고리즘
 *    2) 기본적으로 전체 노드를 맹목적으로 탐색하고자 할 때 사용, 빠르게 모든 경우의 수를 탐색하고자 할 때 쉽게 사용
 *    3) 스택(Stack) 자료구조에 기초, 실제로는 스택을 쓰지 않아도 된다.
 *    4) 시간복잡도 : O(N)
 * 2. 처리 방법
 *    1) 탐색 시작 노드를 스택에 삽입하고 방문 처리를 한다.
 *    2) 스택의 최상단 노드에게 방문하지 않은 인접 노드가 하나라도 있으면 그 노드를 스택에 넣고 방문 처리를 한다.
 *       방문하지 않은 인접 노드가 없으면 스택에서 최상단 노드를 꺼낸다.
 *    3) 2)번의 과정을 더 이상 수행할 수 없을때까지 반복한다.
 *
 *              |3|━━━|1|━━━━━━|2|━━━━┐           |1| | | | | | ⇨ 1 방문
 *       ┌━━━━━━━┘┃    ┃             |7|          |1|2| | | | | ⇨ 2 방문
 *      |4|━━━━━|5|    ┗━━━━━━┐┌━━━━━━┘┃          |1|2|7| | | | ⇨ 7 방문
 *                            |8|      |6|        |1|2|7|6| | | ⇨ 6 방문
 *                                                |1|2|7| | | |
 *                                                |1|2|7|8| | | ⇨ 8 방문
 *                                                |1|2|7| | | |
 *                                                |1|2| | | | |
 *                                                |1| | | | | |
 *                                                |1|3| | | | | ⇨ 3 방문
 *                                                |1|3|4| | | | ⇨ 4 방문
 *                                                |1|3|4|5| | | ⇨ 5 방문
 *                                                |1|3|4| | | |
 *                                                |1|3| | | | |
 *                                                |1| | | | | |
 *                                                | | | | | | |
 */
// 1) 연결리스트 정의
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1001

typedef struct {
    int index;
    struct Node *next;
} Node;

Node** a;
int n, m, c[MAX_SIZE];

// 2) 연결 리스트 삽입 함수
void addFront(Node *root, int index) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->index = index;
    node->next = root->next;
    root->next = node;
}

// 3) 깊이 우선 탐색 함수
void dfs(int x) {
    if(c[x]) return;
    c[x] = 1;
    printf("%d → ", x);
    Node *cur = a[x]->next;
    while(cur != NULL) {
        int next = cur->index;
        dfs(next);
        cur = cur->next;
    }
}

// 4) 깊이 우선 탐색 이용해보기
int main(void) {
    scanf("%d %d", &n, &m);
    a = (Node**) malloc(sizeof(Node*) * MAX_SIZE);
    for(int i=1; i<=n; i++) {
        a[i] = (Node*) malloc(sizeof(Node));
        a[i]->next = NULL;
    }
    for(int i=0; i<m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        addFront(a[x], y);
        addFront(a[y], x);
    }
    dfs(1);
    return 0;
}