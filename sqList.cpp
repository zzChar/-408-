// 《数据结构精深解读》线性表的动态分配顺序存储实现 
#include <stdio.h>
#include <stdlib.h>

// 线性表的动态分配顺序存储结构
#define MAXSIZE 100 // 顺序表可能达到的最大长度
typedef int ElemType;
typedef struct{
    ElemType * data; // 存储空间的基地址
    int length; // 当前长度
}SqList; // 顺序表的结构类型为SqList

// 初始化线性表
void InitList(SqList *&L) {
    L = (SqList*)malloc(sizeof(SqList));		//分配存放线性表的顺序表空间 
   /* if (L == NULL) {
        printf("内存分配失败！\n");
        exit(1);
    }
    L->data = (ElemType*)malloc(MAXSIZE * sizeof(ElemType));
    if (L->data == NULL) {
        printf("数据存储区内存分配失败！\n");
        free(L);
        exit(1);
    }*/ 
    L->length = 0;
}

// 建立顺序表
void CreateList(SqList *&L, ElemType a[], int n) {
   /* if (n > MAXSIZE) {
        printf("元素个数超过最大容量！\n");
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

// 销毁线性表
void DestroyList(SqList *&L) {
    free(L);// 再释放结构体
    
}

// 判定是否为空表
bool ListEmpty(SqList *L) {
    return (L->length == 0);
}

// 求线性表的长度
int ListLength(SqList *L) {
    return (L->length);
}

// 输出线性表
void DispList(SqList *L) {
    int i;
    if (ListEmpty(L))    return;                       
    for ( i = 0; i < L->length; i++) {
        printf("%d ", L->data[i]);
    }
    printf("\n");
}

// 求某个数据元素值
bool GetElem(SqList *L, int i, ElemType &e) {
    if (i < 1 || i > L->length)   return false;
    
    e = L->data[i - 1];
    return true;
}

// 按元素值查找
int LocateElem(SqList *L, ElemType e) {
    int i=0;
    while(i < L->length && L->data[i] !=e){
    	i++;
    }
    	if(i>=L->length) return 0;
    	else return i+1;
    
    	
}

// 插入数据元素
bool ListInsert(SqList *&L, int i, ElemType e) {
   /* 
    if (L->length >= MAXSIZE) {
        printf("线性表已满，无法插入！\n");
        return false;
    }*/
    int j;
    if (i < 1 || i > L->length + 1) {
       // printf("插入位置错误，位置应在1到%d之间\n", L->length + 1);
        return false;
    }
    i--;
    for (int j = L->length; j > i; j--) 
        L->data[j] = L->data[j - 1];
    
    L->data[i] = e;
    L->length++;
    return true;
}

// 删除数据元素
bool ListDelete(SqList *&L, int i, ElemType &e) {
    int j;
    if (i < 1 || i > L->length) {
       // printf("删除位置错误，位置应在1到%d之间\n", L->length);
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

// 测试代码
// 测试初始化功能
void test_init(SqList *&L) {
    InitList(L);
    printf("=== 初始化测试 ===\n");
    printf("初始化后长度应为0：%d\n", ListLength(L));
    printf("初始化后判空结果应为1：%d\n", ListEmpty(L));
}

// 测试创建和输出功能
void test_create(SqList *&L) {
    ElemType arr[] = {5, 3, 8, 2, 7};
    CreateList(L, arr, 5);
    printf("\n=== 创建测试 ===\n");
    printf("创建后长度应为5：%d\n", ListLength(L));
    printf("当前顺序表内容：");
    DispList(L);
}

// 测试元素操作功能
void test_element_ops(SqList *&L) {
    printf("\n=== 元素操作测试 ===\n");
    ElemType e;
    
    // 测试合法位置获取
    GetElem(L, 3, e);
    printf("第三个元素应为8：%d\n", e);
    
    // 测试越界位置获取
    printf("越界获取应返回0：%d\n", GetElem(L, 6, e));
    
    // 测试元素查找
    printf("元素3的位置应为2：%d\n", LocateElem(L, 3));
    printf("不存在的元素应返回0：%d\n", LocateElem(L, 100));
}

// 测试插入功能
void test_insert(SqList *&L) {
    printf("\n=== 插入测试 ===\n");
    ListInsert(L, 3, 10);  // 在第三位插入10
    printf("插入后长度应为6：%d\n", ListLength(L));
    printf("插入后的顺序表：");
    DispList(L);
    
    // 测试边界插入
    ListInsert(L, 1, 1);   // 头部插入
    ListInsert(L, 8, 9);   // 尾部插入
    printf("边界插入后的顺序表：");
    DispList(L);
}

// 测试删除功能
void test_delete(SqList *&L) {
    printf("\n=== 删除测试 ===\n");
    ElemType deleted;
    ListDelete(L, 5, deleted);
    printf("删除的元素应为8：%d\n", deleted);
    printf("删除后的顺序表：");
    DispList(L);
    
    // 测试越界删除
    printf("越界删除应返回0：%d\n", ListDelete(L, 10, deleted));
}

// 测试销毁功能
void test_destroy(SqList *&L) {
    printf("\n=== 销毁测试 ===\n");
    DestroyList(L);
    printf("销毁成功！\n");
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
