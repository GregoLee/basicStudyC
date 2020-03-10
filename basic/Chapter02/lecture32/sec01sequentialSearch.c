//
// Created by pharosinfo on 2020-03-10.
//
/*
 * 순차 탐색 (Sequential Search)
 * 1. 개요
 *    1) 특정한 원소를 찾기 위해 원소를 순차적으로 하나씩 탐색하는 방법
 *          찾을 문자열 : 강종구
 *          INDEX      0        1        2        3        4
 *          원소       나동빈    이태일   박한울    강종구   이상욱
 *    2) 시간복잡도 : O(N)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LENGTH 1000

char **array;
int founded;

int main(void) {
    int n;
    char *word;
    word = malloc(sizeof(char)*LENGTH);
    scanf("%d %s", &n, word);
    array = (char**) malloc(sizeof(char*) * n);
    for(int i=0; i<n; i++) {
        array[i] = malloc(sizeof(char)*LENGTH);
        scanf("%s", array[i]);
    }
    for(int i=0; i<n; i++) {
        if(!strcmp(array[i], word)) {
            printf("%d번째 원소입니다.\n", i+1);
            founded = 1;
        }
    }
    if(!founded) printf("원소를 찾을 수 없습니다.\n");

    return 0;
}
