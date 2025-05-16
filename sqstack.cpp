#include <stdio.h>  // ��׼��������⣬����printf��scanf�Ⱥ���
#include <stdlib.h> // ��׼�⣬�����ڴ����(malloc, realloc)��exit����

// �洢�ռ��ʼ������
#define STACK_INIT_SIZE 100       
// �洢�ռ��������
#define STACKINCREMENT 10          

// ����������״̬��
typedef int Status;               // ��int������ΪStatus�����ڱ�ʾ����ִ��״̬
const int OK = 1;                  // �����ɹ�����ֵ
const int ERROR = 0;               // ����ʧ�ܷ���ֵ
const int OVERFLOW = -1;           // �ڴ����������
const int STACK_FULL_ERROR = -1;   // ջ��������

// ����ջ��Ԫ�ص���������
typedef int SElemType;            // ��int������ΪSElemType����ʾջԪ������

/* ˳��ջ�ṹ���� */
typedef struct {
    SElemType *base;  // ջ��ָ�룬ָ��ջ����ʼ��ַ����ʼ��ʱ�����ڴ�
    SElemType *top;   // ջ��ָ�룬ָ��ջ��Ԫ�ص���һ��λ��(��ջʱ����base)
    int stacksize;    // ��ǰջ�������������baseָ����ڴ���С
} SqStack;

/*
 * ��ʼ��˳��ջ
 * ���ܣ�����һ���յ�˳��ջ�������ʼ�ڴ�ռ�
 */
Status InitStack(SqStack &S) {
    S.base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if (!S.base) exit(OVERFLOW);  // �洢����ʧ��
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    return OK;
}

/*
 * ��ȡ˳��ջ��ջ��Ԫ��
 * ���ܣ���ջ��Ϊ�գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR
 */
Status GetTop(SqStack S, SElemType &e) {
    if (S.top == S.base) return ERROR;
    e = *(S.top - 1);
    return OK;
}

/*
 * ˳��ջ��ջ����
 * ���ܣ���Ԫ��eѹ��ջ������ջ�����Զ�����
 */
Status Push(SqStack &S, SElemType e) {
    if (S.top - S.base >= S.stacksize) {
        SElemType *newBase = (SElemType *)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(SElemType));
        if (!newBase) return STACK_FULL_ERROR;  // ����ʧ��
        S.base = newBase;
        S.top = S.base + S.stacksize;
        S.stacksize += STACKINCREMENT;
    }
    *(S.top++) = e;
    return OK;
}

/*
 * ˳��ջ��ջ����
 * ���ܣ���ջ��Ϊ�գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
 */
Status Pop(SqStack &S, SElemType &e) {
    if (S.top == S.base) return ERROR;
    e = *(--S.top);
    return OK;
}

/*
 * ����˳��ջ�Ļ�������
 * ���ܣ���ʾ˳��ջ�ĳ�ʼ������ջ����ջ�ͻ�ȡջ��Ԫ�ز���
 */
void testSqStack() {
    SqStack S;           // ����˳��ջ����
    SElemType e;         // ���ڴ洢ջ��Ԫ�ػ򵯳���Ԫ��
    Status status;       // �洢�������״̬

    printf("===== ����˳��ջ =====\n");
    
    printf("��ʼ��ջ...");
    status = InitStack(S);
    printf("%s\n", status == OK ? "�ɹ�" : "ʧ��");

    printf("ѹ��Ԫ�� 10, 20, 30...\n");
    Push(S, 10);
    Push(S, 20);
    Push(S, 30);

    printf("��ȡջ��Ԫ��...");
    if (GetTop(S, e) == OK) {
        printf("ջ��Ԫ��: %d\n", e);
    } else {
        printf("ջΪ�գ��޷���ȡջ��Ԫ��\n");
    }

    printf("����Ԫ��: ");
    // ѭ����������Ԫ�ز���ӡ
    while (Pop(S, e) == OK) {
        printf("%d ", e);
    }
    printf("\n");

    printf("���Դӿ�ջ����Ԫ��...");
    status = Pop(S, e);
    printf("%s\n", status == OK ? "�ɹ�" : "ʧ��");
}

/*
 * ������
 * ���ܣ�������ڵ㣬���ò��Ժ�����֤˳��ջ�Ĺ���
 */
int main() {
    testSqStack();
    return 0;
}
