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
 * 2. 무방향 비가중치 그래프와 인접 행렬
 *    1) 모든 간선이 방향성을 가지지 않는 그래프를 무방향 그래프라고 한다.
 *    2) 모든 간선에 가중치가 없는 그래프를 비가중치 그래프라고 한다.
 *    3) 무방향 비가중치 그래프가 주어졌을 때 연결되어 있는 상황을 인접 행렬로 출력할 수 있다.
 */
#include <stdio.h>

int a[1001][1001];
int n, m; // n: n*n 행렬, m : 간선 입력 횟수

int main(void) {
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        a[x][y] = 1;
        a[y][x] = 1;
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}