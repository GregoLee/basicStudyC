//
// Created by Jaeyoung Lee on 2020/03/01.
//
/*
 * 스택을 이용한 계산기 만들기
 * 1. 중위 표기법을 후위 표기법으로 변환하는 방법을 이해
 *    1) 중위 표기법 : 일반적으로 사람이 수식을 표기할 때 사용하는 표기 방법
 *                  7 * 5 + 3
 *    2) 후위 표기법 : 컴퓨터가 계산하기에 편한 수식의 형태, 연산자는 뒤쪽에 위치
 *                  7 5 * 3 +
 * 2. 후위 표기법을 계산하여 결과 값을 도출하는 방법을 이해
 *    1) 스택(Stack)을 활용해 수식을 계산하는 방법은 다음과 같다.
 *       가. 중위 표기법을 후위 표기법으로 변환
 *          가) 피연산자가 들어오면 바로 출력한다.
 *          나) 연산자가 들어오면 자기보다 우선순위가 높거나 같은 것들을 빼고 자신을 스택에 담는다.
 *          다) 여는 괄호 '('를 만나면 무조건 스택에 담는다.
 *          라) 닫는 괄호 ')'를 만나면 '('를 만날 때까지 스택에서 출력한다.
 *       나. 후위 표기법을 계산하여 결과를 도출
 * 3. 스택 자료구조를 활용하여 계산기를 구현
 *    1) 피연산자가 들어오면 스택에 담는다.
 *    2) 연산자를 만나면 스택에서 두 개의 연산자를 꺼내서 연산한 뒤에 그 결과를 스택에 담는다.
 *    3) 연산을 마친 뒤에 스택에 남아있는 하나의 피연산자가 연산 수행 결과이다.
 */

// 스택(Stack)의 구현
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INF 99999999

typedef struct {
    char data[100];
    struct Node *next;
} Node;

typedef struct {
    Node *top;
} Stack;

void push(Stack *stack, char *data) {
    Node *node = (Node*)malloc(sizeof(Node));
    strcpy(node->data, data);
    node->next = stack->top;
    stack->top = node;
}

char* getTop(Stack *stack) {
    Node *top = stack->top;
    return top->data;
}

char* pop(Stack *stack) {
    if (stack->top == NULL) {
        printf("Stack underflow가 발생했습니다.\n");
        return -INF;
    }
    Node *node = stack->top;
    char *data = (char*)malloc(sizeof(char) * 100);
    strcpy(data, node->data);
    stack->top = node->next;
    free(node);
    return data;
}

/*
 * 중위 표기법을 후위 표기법으로 변환
 * 1) 피연산자가 들어오면 바로 출력한다.
 * 2) 연산자가 들어오면 자기보다 우선순위가 높거나 같은 것들을 빼고 자신을 스택에 담는다.
 * 3) 여는 괄호 '('를 만나면 무조건 스택에 담는다.
 * 4) 닫는 괄호 ')'를 만나면 '('를 만날 때까지 스택에서 출력한다.
 */
// 1. 우선순위 함수 만들기
int getPriority(char *i) {
    if( !strcmp(i, "(") ) return 0;
    if( !strcmp(i, "+") || !strcmp(i, "-") ) return 1;
    if( !strcmp(i, "*") || !strcmp(i, "/") ) return 2;
    return 3;
}

// 2. 변환 함수 만들기
char* transition(Stack *stack, char **s, int size) {
    char res[1000] = "";
    for(int i=0; i<size; i++) {
        if( !strcmp(s[i], "+") || !strcmp(s[i], "-") || !strcmp(s[i], "*") || !strcmp(s[i], "/") ) {
            while( stack->top != NULL && getPriority(getTop(stack)) >= getPriority(s[i]) ) {
                strcat(res, pop(stack));
                strcat(res, " ");
            }
            push(stack, s[i]);
        } else if( !strcmp(s[i], "(") ) {
            push(stack, s[i]);
        } else if( !strcmp(s[i], ")") ) {
            while( strcmp(getTop(stack),"(") ) {
                strcat(res, pop(stack));
                strcat(res, " ");
            }
            pop(stack);
        } else {
            strcat(res, s[i]);
            strcat(res, " ");
        }
    }
    while(stack->top != NULL) {
        strcat(res, pop(stack));
        strcat(res, " ");
    }
    return res;
}

/*
 * 후위 표기법 계산
 * 1) 피연산자가 들어오면 스택에 담는다.
 * 2) 연산자를 만나면 스택에서 두 개의 연산자를 꺼내서 연산한 뒤에 그 결과를 스택에 담는다.
 * 3) 연산을 마친 뒤에 스택에 남아있는 하나의 피연산자가 연산 수행 결과이다.
 */
void calculate(Stack *stack, char **s, int size) {
    int x, y, z;
    for(int i=0; i<size; i++) {
        if( !strcmp(s[i], "+") || !strcmp(s[i], "-") || !strcmp(s[i], "*") || !strcmp(s[i], "/") ) {
            x = atoi(pop(stack));
            y = atoi(pop(stack));
            if( !strcmp(s[i], "+") ) z = y + x;
            if( !strcmp(s[i], "-") ) z = y - x;
            if( !strcmp(s[i], "*") ) z = y * x;
            if( !strcmp(s[i], "/") ) z = y / x;
            char buffer[100];
            sprintf(buffer, "%d", z);
            push(stack, buffer);
            printf("%s ", buffer);
        } else {
          push(stack, s[i]);
        }
    }
    printf("%s ", pop(stack));
}

int main(void) {
    Stack stack;
    stack.top = NULL;

    char a[100] = "( ( 1 + 2 ) * 3 + 4 ) / 5 + 6 * 7 - 8";
    printf("%s\n", a); // 중위 표기법 출력

    // 1. " "단위로 토큰으로 분리했을 경우의 갯수
    int size = 1;
    for(int i=0; i<strlen(a); i++) {
        if (a[i]==' ') size++;
    }

    // 2. 토큰화 (a의 문자는 분리단위에 해당하는 부분에 "\0" 값을 넣는다. 따라서 문자열의 값(a)이 변형된다.)
    char *ptr = strtok(a, " ");

    // 3. 메모리 할당 - 1.번의 갯수만큼 char 포인터 메모리를 생성
    char **input = (char**)malloc(sizeof(char*) * size );

    // 4. 메모리 할당 - 1.번의 갯수만큼 char의 값 메모리를 생성
    for(int i=0; i<size; i++) {
        input[i] = (char*)malloc(sizeof(char) * 100);
    }

    // 5. 토큰의 포인터 값을 input 배열을 순회하면서 복사한다.
    for(int i=0; i<size; i++) {
        strcpy(input[i], ptr);   //문자열 복사함수 : strcpy(p1, p2) -> p2의 데이터를 p1에 복사한다.
        ptr = strtok(NULL, " ");  //토큰 관련 함수이다. 자세한 이해를 위해서는 다음 내용을 참조한다. https://www.notion.so/invinciblefunc/C-strtok-61a9c1f1ec4f45a6b45af3b2775db314
    }

    // 6. 중위표기법의 수식을 후위표기법으로 변환한 값을 복사한다.
    char b[1000] = "";
    strcpy(b, transition(&stack, input, size));
    printf("===> %s\n", b);  // 후위표기법 출력

    // 7. 후위표기법 계산
    // 7-1. 후위표기법 " "단위로 문자열 갯수 계산
    size = 1;
    for(int i=0; i<strlen(b)-1; i++) {  //마지막은 항상 공백이 들어가므로 1을 빼기
        if( b[i]==' ' ) size++;
    }

    // 7-2. 토큰에 따른 input 배열을 순회하면서 복사한다.
    char *ptr2 = strtok(b, " ");
    for(int i=0; i<size; i++) {
        strcpy(input[i], ptr2);
        ptr2 = strtok(NULL, " ");
    }

    // 7-3. 계산
    calculate(&stack, input, size);

}