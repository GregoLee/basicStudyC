//
// Created by invin on 2020-02-20.
//
/*
 * ���� �޸� �Ҵ� �Լ� (Dynamic Memory Allocate Function : malloc() )
 * 1) C������ malloc() �Լ��� �̿��� ���ϴ� ��ŭ�� �޸� ������ Ȯ���� �� �ִ�.
 * 2) malloc() �Լ��� �޸� �Ҵ翡 �����ϸ� �ּҸ� ��ȯ�ϰ�, �׷��� ������ NULL�� ��ȯ
 * 3) malloc() �Լ��� <stdlib.h> ���̺귯���� ���ǵǾ� ����
 * 4) ����
 *    malloc(�Ҵ��� ����Ʈ ũ��);
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // ���� �޸� �Ҵ��� ������ ������ �Ҵ�Ǵ� �������� �ּҴ� ��Ģ���̴�.
    int *a = malloc(sizeof(int));
    printf("%d\n", a);   //10229144
    a = malloc(sizeof(int));
    printf("%d\n", a);   //10239824
    return 0;
}

