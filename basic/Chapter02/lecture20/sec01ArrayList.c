//
// Created by Jaeyoung Lee on 2020/02/26.
//
/*
 * 연결리스트
 * 1. 필요성
 *    1) 일반적으로 배열을 사용하여 데이터를 순차적으로 저장하고, 나열할 수 있다.
 *    2) 배열을 사용하는 경우 메모리 공간이 불필요하게 낭비 될 수 있다.
 * 2. 배열 기반 리스트 (ArrayList) - "특정한 인덱스에 바로 찹조하는 경우가 많을 때 유리"
 *    1) 데이터를 순차적으로 저장하고, 처리할 때는 배열 기반의 리스트를 간단히 이용할 수 있다.
 *       1 5 4 7 6 8
 *    2) 특징
 *       - 배열로 만들었으므로 특정한 위치의 원소에 즉시 접근할 수 있다는 장점
 *       - 데이터가 들어갈 공간을 미리 메모리에 할당해야 한다는 단점
 *       - 원하는 위치로의 삽입이나 삭제가 비효율적이다.
 */
#include <stdio.h>
#define INF 10000

int arr[INF];
int count = 0;

void addBack(int data) {
    arr[count] = data;
    count++;
}

void addFirst(int data) {
    for(int i=count; i>=1; i--) {
        arr[i] = arr[i -1];
    }
    arr[0] = data;
    count++;
}

void removeData(int index) {
    for(int i=index; i<count-1; i++) {
        arr[i] = arr[i+1];
    }
    count--;
}

void show() {
    for(int i=0; i<count; i++) {
        printf("%d ", arr[i]);
    }
}

int main(void) {
    addFirst(4);
    addFirst(5);
    addFirst(1);
    addBack(7);
    addBack(6);
    addBack(8);
    removeData(3);
    show();
    return 0;
}