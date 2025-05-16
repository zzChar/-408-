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
    StackNode *p;
    p=(StackNode *)malloc(sizeof(StackNode));
   
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
	StackNode *p;
    if(s==NULL) return ERROR;  // ջΪ��
    e = s->data;
    p = s;
    s = s->next;
    free(p);
    return OK;
}

/*
 * ������ջ�Ļ�������
 */
void testLinkStack() {
    LinkStack s;
    SElemType e;
    Status status;

    printf("===== ������ջ =====\n");

    // ��ʼ��ջ
    printf("��ʼ��ջ...\n");
    status = InitStack(s);
    if (status == OK) {
        printf("��ʼ���ɹ�\n");
    } else {
        printf("��ʼ��ʧ��\n");
    }

    // ��ջ����
    printf("��ջԪ�� 10, 20, 30...\n");
    Push(s, 10);
    Push(s, 20);
    Push(s, 30);

    // ȡջ��Ԫ��
    printf("ȡջ��Ԫ��...\n");
    e = GetTop(s);
    printf("ջ��Ԫ��: %d\n", e);

    // ��ջ����
    printf("��ջԪ��: ");
    while (Pop(s, e) == OK) {
        printf("%d ", e);
    }
    printf("\n");

    // �ٴ�ȡջ��Ԫ�أ����Կ�ջ�����
    printf("���Դӿ�ջȡջ��Ԫ��...\n");
    e = GetTop(s);
    printf("ջ��Ԫ��: %d\n", e);
}

int main() {
    testLinkStack();
    return 0;
}
