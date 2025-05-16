#include <stdio.h>
#include <stdlib.h>

// ����������״̬��
typedef int Status;
#define OK 1
#define ERROR 0

// ����ջ��Ԫ�ص���������
typedef int SElemType;

// ��ջ��㶨��
typedef struct StackNode {
    SElemType data;      // ������
    struct StackNode *next;  // ָ����
} StackNode, *LinkStack;

/*
 * ��ʼ��ջ InitStack(&s)
 * ���ܣ�����һ����ջs��������ջ��ͷ��㣬������next����ΪNULL
 */
Status InitStack(LinkStack &s) {
    s = NULL;
    return OK;
}

/*
 * ��ջ Push(&s, e)
 * ���ܣ��������ݽ�����ͷ���֮��
 */
Status Push(LinkStack &s, SElemType e) {
    StackNode *p = new StackNode;
    if (!p) return ERROR;  // �ڴ����ʧ��
    p->data = e;
    p->next = s;
    s = p;
    return OK;
}

/*
 * ȡջ��Ԫ�� GetTop(s)
 * ���ܣ���ջ��Ϊ�յ������£�����ջ��Ԫ��
 */
SElemType GetTop(LinkStack s) {
    if (s != NULL) {
        return s->data;
    }
    // ������Ը���ʵ��������ջΪ�յ�����������׳��쳣������򵥷���0
    return 0; 
}

/*
 * ��ջ Pop(&s, &e)
 * ���ܣ���ջ��Ϊ�գ���ɾ��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
 */
Status Pop(LinkStack &s, SElemType &e) {
    if (!s) return ERROR;  // ջΪ��
    e = s->data;
    StackNode *p = s;
    s = s->next;
    delete p;
    return OK;
}

/*
 * �ж�ջ�Ƿ�Ϊ�� StackEmpty(s)
 * ���ܣ���ջΪ�գ�����1�����򷵻�0
 */
int StackEmpty(LinkStack s) {
    return s == NULL;
}

/*
 * ��ʮ������ת��Ϊ�˽����� conversion()
 * ���ܣ��������������һ���Ǹ�ʮ����������ӡ��������ֵ�İ˽�����
 *�����Ϻ����ϵ�����һ����ֻ��Ϊ�������Դ��룬���������һЩ������ϸ�鿴 
 */
void conversion() {
    LinkStack S;
    SElemType N, e;
    InitStack(S);  // �����ջ
    printf("������һ���Ǹ�ʮ������: ");
    scanf("%d", &N);
    while (N) {
        Push(S, N % 8);
        N = N / 8;
    }
    while (!StackEmpty(S)) {
        Pop(S, e);
        printf("%d", e);
    }
    printf("\n");
}

int main() {
    conversion();
    return 0;
}
