//
// Created by pharosinfo on 2020-03-14.
//
/*
 * 너비 우선 탐색 (Breadth First Search)
 * 1. 개요
 *    1) 너비를 우선으로 하여 탐색을 수행하는 전수 탐색 알고리즘
 *    2) 깊이 우선 탐색(Depth First Search, DFS)와 마찬가지로 맹목적으로 전체 노드를 탐색하고자 할 때 자주 사용
 *    3) 큐(Queue) 자료구조에 기초
 *    4) 고급 그래프 탐색 알고리즘에서 자주 활용
 *    5) 시간복잡도
 *       - O(N)
 *       - 실제로 구현함에 있어 큐 STL을 사용하면 좋다
 *       - 일반적인 경우 실제 수행 시간은 DFS보다 좋은 편
 * 2. 처리 방법
 *    1) 탐색 시작 노드를 큐에 삽입하고 방문 처리를 한다.
 *    2) 큐에서 노드를 꺼내 해당 노드의 인접 노드 중에서 방문하지 않은 노드들을 모두 큐에 삽입하고, 방문 처리를 한다.
 *    3) 2번의 과정을 더 이상 수행할 수 없을 때까지 반복한다.
 *
 *              |3|━━━|1|━━━━━━|2|━━━━┐           |1| | | | | | | | ⇨ 1 삽입
 *       ┌━━━━━━━┘┃    ┃             |7|          |2|3|8| | | | | | ⇨ 1 방문 및 제거 / 2, 3, 8 삽입
 *      |4|━━━━━|5|    ┗━━━━━━┐┌━━━━━━┘┃          | |3|8|7| | | | | ⇨ 2 방문 및 제거 / 7 삽입
 *                            |8|      |6|        | | |8|7|4|5| | | ⇨ 3 방문 및 제거 / 4, 5 삽입
 *                                                | | | |7|4|5| | | ⇨ 8 방문 및 제거
 *                                                | | | | |4|5|6| | ⇨ 7 방문 및 제거 / 6 삽입
 *                                                | | | | | |5|6| | ⇨ 4 방문 및 제거
 *                                                | | | | | | |6| | ⇨ 5 방문 및 제거
 *                                                | | | | | | | | | ⇨ 6 방문 및 제거
 */
// 너비 우선 탐색
// 1) 연결리스트 정의
#include <stdio.h>
#include <stdlib.h>
#define INF 99999999
#define MAX_SIZE 1001

typedef struct {
    int index;
    struct Node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
    int count;
} Queue;

Node** a;
int n, m, c[MAX_SIZE];

// 2) 연결 리스트 삽입 함수
void addFront(Node *root, int index) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->index = index;
    node->next = root->next;
    root->next = node;
}

// 3) 큐 삽입 함수
void queuePush(Queue *queue, int index) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->index = index;
    if(queue->count == 0) {
        queue->front = node;
    }
    else {
        queue->rear->next = node;
    }
    queue->rear = node;
    queue->count++;
}

// 4) 큐 추출 함수
int queuePop(Queue *queue) {
    if(queue->count == 0) {
        printf("큐 underflow가 발생했습니다.\n");
        return -INF;
    }
    Node *node = queue->front;
    int index = node->index;
    queue->front = node->next;
    free(node);
    queue->count--;
    return index;
}

// 5) 너비 우선 탐색 함수
void bfs(int start) {
    Queue q;
    q.front = q.rear = NULL;
    q.count = 0;
    queuePush(&q, start);
    c[start] = 1;
    while (q.count != 0) {
        int x = queuePop(&q);
        printf("%d ", x);
        Node *cur = a[x]->next;
        while (cur != NULL) {
            int next = cur->index;
            if(!c[next]) {
                queuePush(&q, next);
                c[next] = 1;
            }
            cur = cur->next;
        }
    }
}

// 6) 너비 우선 탐색 이용해보기
/*
 * 8 9
 * 1 2
 * 1 3
 * 1 8
 * 2 7
 * 3 4
 * 3 5
 * 4 5
 * 7 6
 * 7 8
 */
int main(void) {
    scanf("%d %d", &n, &m);
    a = (Node**)malloc(sizeof(Node*)*(MAX_SIZE));
    for(int i=1; i<=n; i++) {
        a[i] = (Node*)malloc(sizeof(Node));
        a[i]->next = NULL;
    }
    for(int i=0; i<m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        addFront(a[x], y);
        addFront(a[y], x);
    }
    bfs(1);
    return 0;
}