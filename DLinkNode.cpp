// 《数据结构精深解读》线性表的链式存储-双链表实现 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 定义数据元素类型为int
typedef int ElemType;

// 定义双链表的结点结构
typedef struct DNode {
    ElemType data;     // 存储数据元素
    struct DNode *prior; // 指向前驱结点的指针
    struct DNode *next; // 指向后继结点的指针
} DLinkNode;

// 头插法建立双链表
// 参数L为双链表的指针引用，通过它来修改双链表的头指针
// a是包含数据元素的数组
// n是数组a中元素的个数
void CreateListF(DLinkNode *&L, ElemType a[], int n) {
    DLinkNode *s;     // 用于创建新结点
    int i;
    L = (DLinkNode *)malloc(sizeof(DLinkNode)); // 分配头结点空间
	/* if (L == NULL) {
        printf("头结点内存分配失败！\n");
        return;
    }*/
    L->prior = L->next = NULL; // 初始化头结点的前驱和后继指针为NULL
    for (i = 0; i < n; i++) {
        s = (DLinkNode *)malloc(sizeof(DLinkNode)); // 为新结点分配空间
  	
        s->data = a[i]; // 给新结点的数据域赋值
        s->next = L->next; // 新结点的next指针指向原头结点后的第一个结点
        if (L->next != NULL) {
            L->next->prior = s; // 若原头结点后有数据结点，修改其前驱指针
        }
        L->next = s; // 头结点的next指针指向新结点
        s->prior = L; // 新结点的前驱指针指向头结点
    }
}

// 尾插法建立双链表
// 参数L为双链表的指针引用，通过它来修改双链表的头指针
// a是包含数据元素的数组
// n是数组a中元素的个数
void CreateListR(DLinkNode *&L, ElemType a[], int n) {
    DLinkNode *s, *r; // s用于创建新结点，r始终指向链表的尾结点
    int i;
    L = (DLinkNode *)malloc(sizeof(DLinkNode)); // 分配头结点空间
	/*if (L == NULL) {
        printf("头结点内存分配失败！\n");
        return;
    }*/
    r = L; // 初始化尾指针r指向头结点
    for (i = 0; i < n; i++) {
        s = (DLinkNode *)malloc(sizeof(DLinkNode)); // 为新结点分配空间
		/* if (s == NULL) {
            printf("新结点内存分配失败！\n");
            continue;
        }*/
        s->data = a[i]; // 给新结点的数据域赋值
        r->next = s; // 将新结点插入到尾结点之后
        s->prior = r; // 新结点的前驱指针指向当前尾结点
        r = s; // 更新尾指针r指向新的尾结点
    }
    r->next = NULL; // 最后将尾结点的next指针置为NULL
}

// 在双链表中插入数据元素
// 参数L为双链表的指针引用，i为插入位置，e为要插入的元素值
bool ListInsert(DLinkNode *&L, int i, ElemType e) {
    int j = 0;
    DLinkNode *p = L, *s; // p指向头结点，s用于创建新结点
    if (i <= 0) {
        return false; // 插入位置不合法，返回false
    }
    while (j < i - 1 && p != NULL) { // 查找第i - 1个结点
        j++;
        p = p->next;
    }
    if (p == NULL) {
        return false; // 未找到插入位置的前驱结点，返回false
    } else {
        s = (DLinkNode *)malloc(sizeof(DLinkNode)); // 为新结点分配空间
 		/*if (s == NULL) {
            printf("新结点内存分配失败，插入失败！\n");
            return false;
        }*/
        s->data = e; // 给新结点的数据域赋值
        s->next = p->next; // 新结点的next指针指向原插入位置的后继结点
        if (p->next != NULL) {
            p->next->prior = s; // 若存在后继结点，修改其后继结点的前驱指针
        }
        s->prior = p; // 新结点的前驱指针指向插入位置的前驱结点
        p->next = s; // 插入位置的前驱结点的next指针指向新结点
        return true; // 插入成功，返回true
    }
}

// 在双链表中删除第i个结点
// 参数L为双链表的指针引用，i为删除位置，e用于存储被删除的元素值
bool ListDelete(DLinkNode *&L, int i, ElemType &e) {
    int j = 0;
    DLinkNode *p = L, *s; // p指向头结点，s用于指向要删除的结点
    if (i <= 0) {
        return false; // 删除位置不合法，返回false
    }
    while (j < i - 1 && p != NULL) { // 查找第i - 1个结点
        j++;
        p = p->next;
    }
    if (p == NULL) {
        return false; // 未找到删除位置的前驱结点，返回false
    } else {
        s = p->next; // s指向要删除的结点
        if (s == NULL) {
        	
            return false; // 要删除的结点不存在，返回false
        }
        e = s->data; // 保存要删除的结点的数据
        p->next = s->next; // 前驱结点的next指针跳过要删除的结点
        if (p->next != NULL) {
            p->next->prior = p; // 修改后继结点的前驱指针
        }
        free(s); // 释放要删除的结点的内存
        return true; // 删除成功，返回true
    }
}

// 输出双链表
// 参数L为双链表的头指针
void DispList(DLinkNode *L) {
    DLinkNode *p = L->next; // p指向头结点后的第一个数据结点
    while (p != NULL) {
        printf("%d ", p->data); // 输出当前结点的数据
        p = p->next; // 移动指针到下一个结点
    }
    printf("\n");
}


// 测试函数
void testDLinkedList() {
    DLinkNode *L;
    ElemType a[] = {1, 2, 3, 4, 5};
    int n = sizeof(a) / sizeof(a[0]);
    ElemType e;

    // 测试头插法建立双链表
    printf("测试头插法建立双链表:\n");
    CreateListF(L, a, n);
    printf("头插法建立的双链表: ");
    DispList(L);

    // 测试尾插法建立双链表
    printf("\n测试尾插法建立双链表:\n");
    free(L); // 释放头插法创建的链表
    CreateListR(L, a, n);
    printf("尾插法建立的双链表: ");
    DispList(L);

    // 测试插入数据元素
    printf("\n测试插入数据元素:\n");
    if (ListInsert(L, 2, 10)) {
        printf("在位置2插入元素10后的双链表: ");
        DispList(L);
    } else {
        printf("插入失败\n");
    }

    // 测试删除数据元素
    printf("\n测试删除数据元素:\n");
    if (ListDelete(L, 2, e)) {
        printf("删除位置2的元素，删除的元素值为: %d\n", e);
        printf("删除后的双链表: ");
        DispList(L);
    } else {
        printf("删除失败\n");
    }

    // 释放双链表内存
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
