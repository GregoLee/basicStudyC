//
// Created by Jaeyoung Lee on 2020/03/11.
//
/*
 * 그래프 (Graph)
 * 1. 개요
 *    1) 사물을 정점(Vertex)와 간선(Edge)으로 나타내기 위한 도구
 *    2) 구현 방식
 *       - 인접 행렬(Adjacency Matrix) : 2차원 배열을 사용하는 방식
 *          - 공간복잡도 : 모든 정점들의 연결 여부를 저장하여 O(V^2)의 공간을 요구, 공간효율성 떨어짐
 *          - 서로 연결되어 있는지 확인하기 위해 O(1)의 시간을 요구
 *                     | 0 |                    0 | 3 | 7
 *              ┌━━ 3 ━━┘ └━━ 7 ━━┐             3 | 0 | ∞
 *            | 1 |             | 2 |           7 | ∞ | 0
 *
 *       - 인접 리스트(Adjacency List) : 리스트를 사용하는 방식
 *          - 공간복잡도 : 연결된 간선의 정보만을 저장하여 O(E)의 공간을 요구, 공간효율성 우수
 *          - 시간복잡도 : 두 정점이 서로 연결되어 있는지 확인하기 위해 O(V)의 시간을 요구
 *
 * 3. 방향 가중치 그래프와 인접 리스트
 *    1) 모든 간선이 방향성을 가지지는 그래프를 방향 그래프라고 한다.
 *    2) 모든 간선에 가중치가 있는 그래프를 가중치 그래프라고 한다.
 *    3) 무방향 비가중치 그래프가 주어졌을 때 연결되어 있는 상황을 인접 리스로 출력할 수 있다.
 */
#include <stdio.h>
#include <stdlib.h>

// 1. 연결 리스트 구조체 만들기
typedef struct {
    int index;
    int distance;
    struct Node *next;
} Node;

// 2. 연결 리스트 삽입 함수
void addFront(Node *root, int index, int distance) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->index = index;
    node->distance = distance;
    node->next = root->next;
    root->next = node;
}

// 3. 연결 리스트 출력 함수
void showAll(Node *root) {
    Node *cur = root->next;
    printf("root → ");
    while(cur != NULL) {
        printf("%d(거리: %d) → ", cur->index, cur->distance);
        cur = cur->next;
    }
}

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    Node** a = (Node**)malloc(sizeof(Node*)*(n+1));
    for(int i=1; i<=n; i++) {
        a[i] = (Node*)malloc(sizeof(Node));
        a[i]->next = NULL;
    }
    for(int i=0; i<m; i++) {
        int x, y, distance;
        scanf("%d %d %d", &x, &y, &distance);
        addFront(a[x], y, distance);
    }
    for(int i=1; i<=n; i++) {
        printf("원소 [%d]: ", i);
        showAll(a[i]);
        printf("\n");
    }
    return 0;
}