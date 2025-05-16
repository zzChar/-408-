// �����ݽṹ�����������Ա����ʽ�洢-˫����ʵ�� 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ��������Ԫ������Ϊint
typedef int ElemType;

// ����˫����Ľ��ṹ
typedef struct DNode {
    ElemType data;     // �洢����Ԫ��
    struct DNode *prior; // ָ��ǰ������ָ��
    struct DNode *next; // ָ���̽���ָ��
} DLinkNode;

// ͷ�巨����˫����
// ����LΪ˫�����ָ�����ã�ͨ�������޸�˫�����ͷָ��
// a�ǰ�������Ԫ�ص�����
// n������a��Ԫ�صĸ���
void CreateListF(DLinkNode *&L, ElemType a[], int n) {
    DLinkNode *s;     // ���ڴ����½��
    int i;
    L = (DLinkNode *)malloc(sizeof(DLinkNode)); // ����ͷ���ռ�
	/* if (L == NULL) {
        printf("ͷ����ڴ����ʧ�ܣ�\n");
        return;
    }*/
    L->prior = L->next = NULL; // ��ʼ��ͷ����ǰ���ͺ��ָ��ΪNULL
    for (i = 0; i < n; i++) {
        s = (DLinkNode *)malloc(sizeof(DLinkNode)); // Ϊ�½�����ռ�
  	
        s->data = a[i]; // ���½���������ֵ
        s->next = L->next; // �½���nextָ��ָ��ԭͷ����ĵ�һ�����
        if (L->next != NULL) {
            L->next->prior = s; // ��ԭͷ���������ݽ�㣬�޸���ǰ��ָ��
        }
        L->next = s; // ͷ����nextָ��ָ���½��
        s->prior = L; // �½���ǰ��ָ��ָ��ͷ���
    }
}

// β�巨����˫����
// ����LΪ˫�����ָ�����ã�ͨ�������޸�˫�����ͷָ��
// a�ǰ�������Ԫ�ص�����
// n������a��Ԫ�صĸ���
void CreateListR(DLinkNode *&L, ElemType a[], int n) {
    DLinkNode *s, *r; // s���ڴ����½�㣬rʼ��ָ�������β���
    int i;
    L = (DLinkNode *)malloc(sizeof(DLinkNode)); // ����ͷ���ռ�
	/*if (L == NULL) {
        printf("ͷ����ڴ����ʧ�ܣ�\n");
        return;
    }*/
    r = L; // ��ʼ��βָ��rָ��ͷ���
    for (i = 0; i < n; i++) {
        s = (DLinkNode *)malloc(sizeof(DLinkNode)); // Ϊ�½�����ռ�
		/* if (s == NULL) {
            printf("�½���ڴ����ʧ�ܣ�\n");
            continue;
        }*/
        s->data = a[i]; // ���½���������ֵ
        r->next = s; // ���½����뵽β���֮��
        s->prior = r; // �½���ǰ��ָ��ָ��ǰβ���
        r = s; // ����βָ��rָ���µ�β���
    }
    r->next = NULL; // ���β����nextָ����ΪNULL
}

// ��˫�����в�������Ԫ��
// ����LΪ˫�����ָ�����ã�iΪ����λ�ã�eΪҪ�����Ԫ��ֵ
bool ListInsert(DLinkNode *&L, int i, ElemType e) {
    int j = 0;
    DLinkNode *p = L, *s; // pָ��ͷ��㣬s���ڴ����½��
    if (i <= 0) {
        return false; // ����λ�ò��Ϸ�������false
    }
    while (j < i - 1 && p != NULL) { // ���ҵ�i - 1�����
        j++;
        p = p->next;
    }
    if (p == NULL) {
        return false; // δ�ҵ�����λ�õ�ǰ����㣬����false
    } else {
        s = (DLinkNode *)malloc(sizeof(DLinkNode)); // Ϊ�½�����ռ�
 		/*if (s == NULL) {
            printf("�½���ڴ����ʧ�ܣ�����ʧ�ܣ�\n");
            return false;
        }*/
        s->data = e; // ���½���������ֵ
        s->next = p->next; // �½���nextָ��ָ��ԭ����λ�õĺ�̽��
        if (p->next != NULL) {
            p->next->prior = s; // �����ں�̽�㣬�޸����̽���ǰ��ָ��
        }
        s->prior = p; // �½���ǰ��ָ��ָ�����λ�õ�ǰ�����
        p->next = s; // ����λ�õ�ǰ������nextָ��ָ���½��
        return true; // ����ɹ�������true
    }
}

// ��˫������ɾ����i�����
// ����LΪ˫�����ָ�����ã�iΪɾ��λ�ã�e���ڴ洢��ɾ����Ԫ��ֵ
bool ListDelete(DLinkNode *&L, int i, ElemType &e) {
    int j = 0;
    DLinkNode *p = L, *s; // pָ��ͷ��㣬s����ָ��Ҫɾ���Ľ��
    if (i <= 0) {
        return false; // ɾ��λ�ò��Ϸ�������false
    }
    while (j < i - 1 && p != NULL) { // ���ҵ�i - 1�����
        j++;
        p = p->next;
    }
    if (p == NULL) {
        return false; // δ�ҵ�ɾ��λ�õ�ǰ����㣬����false
    } else {
        s = p->next; // sָ��Ҫɾ���Ľ��
        if (s == NULL) {
        	
            return false; // Ҫɾ���Ľ�㲻���ڣ�����false
        }
        e = s->data; // ����Ҫɾ���Ľ�������
        p->next = s->next; // ǰ������nextָ������Ҫɾ���Ľ��
        if (p->next != NULL) {
            p->next->prior = p; // �޸ĺ�̽���ǰ��ָ��
        }
        free(s); // �ͷ�Ҫɾ���Ľ����ڴ�
        return true; // ɾ���ɹ�������true
    }
}

// ���˫����
// ����LΪ˫�����ͷָ��
void DispList(DLinkNode *L) {
    DLinkNode *p = L->next; // pָ��ͷ����ĵ�һ�����ݽ��
    while (p != NULL) {
        printf("%d ", p->data); // �����ǰ��������
        p = p->next; // �ƶ�ָ�뵽��һ�����
    }
    printf("\n");
}


// ���Ժ���
void testDLinkedList() {
    DLinkNode *L;
    ElemType a[] = {1, 2, 3, 4, 5};
    int n = sizeof(a) / sizeof(a[0]);
    ElemType e;

    // ����ͷ�巨����˫����
    printf("����ͷ�巨����˫����:\n");
    CreateListF(L, a, n);
    printf("ͷ�巨������˫����: ");
    DispList(L);

    // ����β�巨����˫����
    printf("\n����β�巨����˫����:\n");
    free(L); // �ͷ�ͷ�巨����������
    CreateListR(L, a, n);
    printf("β�巨������˫����: ");
    DispList(L);

    // ���Բ�������Ԫ��
    printf("\n���Բ�������Ԫ��:\n");
    if (ListInsert(L, 2, 10)) {
        printf("��λ��2����Ԫ��10���˫����: ");
        DispList(L);
    } else {
        printf("����ʧ��\n");
    }

    // ����ɾ������Ԫ��
    printf("\n����ɾ������Ԫ��:\n");
    if (ListDelete(L, 2, e)) {
        printf("ɾ��λ��2��Ԫ�أ�ɾ����Ԫ��ֵΪ: %d\n", e);
        printf("ɾ�����˫����: ");
        DispList(L);
    } else {
        printf("ɾ��ʧ��\n");
    }

    // �ͷ�˫�����ڴ�
    DLinkNode *p = L, *q;
    while (p != NULL) {
        q = p;
        p = p->next;
        free(q);
    }
}

int main() {
    testDLinkedList();
    return 0;
}    
