// �����ݽṹ�����������Ա�Ķ�̬����˳��洢ʵ�� 
#include <stdio.h>
#include <stdlib.h>

// ���Ա�Ķ�̬����˳��洢�ṹ
#define MAXSIZE 100 // ˳�����ܴﵽ����󳤶�
typedef int ElemType;
typedef struct{
    ElemType * data; // �洢�ռ�Ļ���ַ
    int length; // ��ǰ����
}SqList; // ˳���Ľṹ����ΪSqList

// ��ʼ�����Ա�
void InitList(SqList *&L) {
    L = (SqList*)malloc(sizeof(SqList));		//���������Ա��˳���ռ� 
   /* if (L == NULL) {
        printf("�ڴ����ʧ�ܣ�\n");
        exit(1);
    }
    L->data = (ElemType*)malloc(MAXSIZE * sizeof(ElemType));
    if (L->data == NULL) {
        printf("���ݴ洢���ڴ����ʧ�ܣ�\n");
        free(L);
        exit(1);
    }*/ 
    L->length = 0;
}

// ����˳���
void CreateList(SqList *&L, ElemType a[], int n) {
   /* if (n > MAXSIZE) {
        printf("Ԫ�ظ����������������\n");
        return;
    }*/ 
    /*for (int i = 0; i < n; i++) {
        L->data[i] = a[i];
    }*/
    int i=0,k=0;
    L=(SqList *) malloc (n * sizeof(SqList));    
    while(i<n){
	L->data[k]=a[i];
	k++;i++;
    } 
    L->length = k;
}

// �������Ա�
void DestroyList(SqList *&L) {
    free(L);// ���ͷŽṹ��
    
}

// �ж��Ƿ�Ϊ�ձ�
bool ListEmpty(SqList *L) {
    return (L->length == 0);
}

// �����Ա�ĳ���
int ListLength(SqList *L) {
    return (L->length);
}

// ������Ա�
void DispList(SqList *L) {
    int i;
    if (ListEmpty(L))    return;                       
    for ( i = 0; i < L->length; i++) {
        printf("%d ", L->data[i]);
    }
    printf("\n");
}

// ��ĳ������Ԫ��ֵ
bool GetElem(SqList *L, int i, ElemType &e) {
    if (i < 1 || i > L->length)   return false;
    
    e = L->data[i - 1];
    return true;
}

// ��Ԫ��ֵ����
int LocateElem(SqList *L, ElemType e) {
    int i=0;
    while(i < L->length && L->data[i] !=e){
    	i++;
    }
    	if(i>=L->length) return 0;
    	else return i+1;
    
    	
}

// ��������Ԫ��
bool ListInsert(SqList *&L, int i, ElemType e) {
   /* 
    if (L->length >= MAXSIZE) {
        printf("���Ա��������޷����룡\n");
        return false;
    }*/
    int j;
    if (i < 1 || i > L->length + 1) {
       // printf("����λ�ô���λ��Ӧ��1��%d֮��\n", L->length + 1);
        return false;
    }
    i--;
    for (int j = L->length; j > i; j--) 
        L->data[j] = L->data[j - 1];
    
    L->data[i] = e;
    L->length++;
    return true;
}

// ɾ������Ԫ��
bool ListDelete(SqList *&L, int i, ElemType &e) {
    int j;
    if (i < 1 || i > L->length) {
       // printf("ɾ��λ�ô���λ��Ӧ��1��%d֮��\n", L->length);
        return false;
    }
    i--;
    e = L->data[i];
    for (int j = i ; j < L->length - 1; j++) {
        L->data[j] = L->data[j + 1];
    }
    L->length--;
    return true;
}

// ���Դ���
// ���Գ�ʼ������
void test_init(SqList *&L) {
    InitList(L);
    printf("=== ��ʼ������ ===\n");
    printf("��ʼ���󳤶�ӦΪ0��%d\n", ListLength(L));
    printf("��ʼ�����пս��ӦΪ1��%d\n", ListEmpty(L));
}

// ���Դ������������
void test_create(SqList *&L) {
    ElemType arr[] = {5, 3, 8, 2, 7};
    CreateList(L, arr, 5);
    printf("\n=== �������� ===\n");
    printf("�����󳤶�ӦΪ5��%d\n", ListLength(L));
    printf("��ǰ˳������ݣ�");
    DispList(L);
}

// ����Ԫ�ز�������
void test_element_ops(SqList *&L) {
    printf("\n=== Ԫ�ز������� ===\n");
    ElemType e;
    
    // ���ԺϷ�λ�û�ȡ
    GetElem(L, 3, e);
    printf("������Ԫ��ӦΪ8��%d\n", e);
    
    // ����Խ��λ�û�ȡ
    printf("Խ���ȡӦ����0��%d\n", GetElem(L, 6, e));
    
    // ����Ԫ�ز���
    printf("Ԫ��3��λ��ӦΪ2��%d\n", LocateElem(L, 3));
    printf("�����ڵ�Ԫ��Ӧ����0��%d\n", LocateElem(L, 100));
}

// ���Բ��빦��
void test_insert(SqList *&L) {
    printf("\n=== ������� ===\n");
    ListInsert(L, 3, 10);  // �ڵ���λ����10
    printf("����󳤶�ӦΪ6��%d\n", ListLength(L));
    printf("������˳���");
    DispList(L);
    
    // ���Ա߽����
    ListInsert(L, 1, 1);   // ͷ������
    ListInsert(L, 8, 9);   // β������
    printf("�߽������˳���");
    DispList(L);
}

// ����ɾ������
void test_delete(SqList *&L) {
    printf("\n=== ɾ������ ===\n");
    ElemType deleted;
    ListDelete(L, 5, deleted);
    printf("ɾ����Ԫ��ӦΪ8��%d\n", deleted);
    printf("ɾ�����˳���");
    DispList(L);
    
    // ����Խ��ɾ��
    printf("Խ��ɾ��Ӧ����0��%d\n", ListDelete(L, 10, deleted));
}

// �������ٹ���
void test_destroy(SqList *&L) {
    printf("\n=== ���ٲ��� ===\n");
    DestroyList(L);
    printf("���ٳɹ���\n");
}

int main() {
    SqList *L = NULL;
    
    test_init(L);
    test_create(L);
    test_element_ops(L);
    test_insert(L);
    test_delete(L);
    test_destroy(L);

    return 0;
}
