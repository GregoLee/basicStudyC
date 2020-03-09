//
// Created by Jaeyoung Lee on 2020/03/09.
//
/*
 * 우선순위 큐(Priority Queue)
 * 1. 개요
 *    1) '우선 순위'를 가진 데이터들을 저장하는 큐를 의미
 *    2) 데이터를 꺼낼 때 우선 순위가 높은 데이터가 가장 먼저 나온다는 특징이 있어 많이 활용되고 있다.
 *    3) 운영체제의 작업 스케줄링, 정렬, 네트워크 관리 등의 다양한 기술에 적용되고 있다.
 *    4) 삽입과 삭제는 O(log N)의 시간 복잡도를 가진다.
 *
 * 2. 큐와 우선순위 큐의 차이점
 *    1) 큐 : 선형적인 형태를 가짐
 *    2) 우선순위 큐 : 트리 구조로 보는 것이 합리적, 최대 힙을 이용해 구현한다.
 *
 *       |  |  |  |  |                     30
 *         일반적인 큐               ┌━━━━━━━┘ └━━━━━━━┐
 *                                17               48
 *                            ┌━━┘ └━━┐        ┌━━┘ └━━┐
 *                            5      23        37     50
 *                                     우선순위 큐
 *
 * 3. 최대 힙 (Max Heap)
 *    ; 부모 노드가 자식 노드보다 값이 큰 "완전 이진 트리"를 의미
 *
 *                  8          (O)                      8          (O)
 *         ┌━━━━━━━┘ └━━━━━━━┐                 ┌━━━━━━━┘ └━━━━━━━┐
 *         7                 5                 7                 5
 *     ┌━━┘ └━━┐         ┌━━┘ └━━┐         ┌━━┘ └━━┐
 *     4       1         2       3         4       1
 *
 *                  8          (X)                      8          (X)
 *         ┌━━━━━━━┘ └━━━━━━━┐                 ┌━━━━━━━┘ └━━━━━━━┐
 *         7                 5                 7                 5
 *     ┌━━┘              ┌━━┘ └━━┐         ┌━━┘ └━━┐
 *     4                 2       3         9       1
 *
 *     1) 루트 노드는 전체 트리에서 가장 큰 값을 가진다.
 *     2) PUSH
 *        ; 우선순위 큐에 데이터를 삽입
 *
 *                  8                                    8
 *         ┌━━━━━━━┘ └━━━━━━━┐                  ┌━━━━━━━┘ └━━━━━━━┐
 *         7                 5      =>          7                 5     (삽입 이후에는 루트 노드까지 거슬러 올라가면서 최대 힙을 구성 [상향식])
 *     ┌━━┘ └━━┐         ┌━━┘               ┌━━┘ └━━┐         ┌━━┘ └━━┐
 *     4       1         2                  4       1         2       9 (삽입할 원소)
 *
 *                          8                                        9
 *                 ┌━━━━━━━┘ └━━━━━━━┐                      ┌━━━━━━━┘ └━━━━━━━┐
 *     =>          7                 9          =>          7                 8
 *             ┌━━┘ └━━┐         ┌━━┘ └━━┐              ┌━━┘ └━━┐         ┌━━┘ └━━┐
 *             4       1         2       5              4       1         2       5
 *
 *     3) POP
 *        ; 우선순위 큐에 데이터를 추출
 *
 *                      9 (삭제할 원소)                         5    (루트 노드를 제거하고, 가장 마지막 원소를 루트 노드의 위치로 옮겨준다.)
 *             ┌━━━━━━━┘ └━━━━━━━┐                  ┌━━━━━━━┘ └━━━━━━━┐
 *             8                 7      =>          8                 7
 *         ┌━━┘ └━━┐         ┌━━┘ └━━┐          ┌━━┘ └━━┐         ┌━━┘
 *         4       1         2       5          4       1         2
 *
 *                              8
 *                     ┌━━━━━━━┘ └━━━━━━━┐
 *         =>          5                 7   삭제 이후에는 리프 노드까지 내려가면서 최대 힙을 구성한다. [하향식]
 *                 ┌━━┘ └━━┐         ┌━━┘
 *                 4       1         2
 */

#include <stdio.h>
#define MAX_SIZE 10000

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

typedef struct {
    int heap[MAX_SIZE];
    int count;
} priorityQueue;

void push(priorityQueue *pq, int data) {
    if(pq->count >= MAX_SIZE) return;
    pq->heap[pq->count] = data;
    int now = pq->count;
    int parent = (pq->count - 1) / 2;
    // 새 원소를 삽입한 이후에 상향식으로 힙을 구성한다.
    while(now > 0 && pq->heap[now] > pq->heap[parent]) {
        swap(&pq->heap[now], &pq->heap[parent]);
        now = parent;
        parent = (parent - 1) / 2;
    }
    pq->count++;
}

int pop(priorityQueue *pq) {
    if(pq->count <= 0 ) return -9999;
    int res = pq->heap[0];
    pq->count--;
    pq->heap[0] = pq->heap[pq->count];
    int now = 0, leftChild = 1, rightChild = 2;
    int target = now;
    // 새 원소를 추출한 이후에 하향식으로 힙을 구성한다.
    while(leftChild < pq->count) {
        if(pq->heap[target] < pq->heap[leftChild]) target = leftChild;
        if(pq->heap[target] < pq->heap[rightChild] && rightChild < pq->count) target = rightChild;
        if(target == now) break; // 더 이상 내려가지 않아도 되므로 종료
        else {
            swap(&pq->heap[now], &pq->heap[target]);
            now = target;
            leftChild = now * 2 + 1;
            rightChild = now * 2 + 2;
        }
    }
    return res;
}

int main(void) {
    int n, data;
    scanf("%d", &n);
    priorityQueue pq;
    pq.count = 0;
    for(int i=0; i<n; i++) {
        scanf("%d", &data);
        push(&pq, data);
    }
    for(int i=0; i<n; i++) {
        int data = pop(&pq);
        printf("%d ", data);
    }
    return 0;
}