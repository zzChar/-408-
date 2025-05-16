#include <stdio.h>
#include <stdlib.h>

// 定义操作结果状态码
typedef int Status;
#define OK 1
#define ERROR 0

// 定义栈中元素的数据类型
typedef int SElemType;

// 链栈结点定义
typedef struct StackNode {
    SElemType data;      // 数据域
    struct StackNode *next;  // 指针域
} StackNode, *LinkStack;

/*
 * 初始化栈 InitStack(&s)
 * 功能：建立一个空栈s，创建链栈的头结点，并将其next域置为NULL
 */
Status InitStack(LinkStack &s) {
    s = NULL;
    return OK;
}

/*
 * 入栈 Push(&s, e)
 * 功能：将新数据结点插入头结点之后
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
 * 取栈顶元素 GetTop(s)
 * 功能：在栈不为空的条件下，返回栈顶元素
 */
SElemType GetTop(LinkStack s) {
    if (s != NULL) {
        return s->data;
    }
    // 这里可以根据实际需求处理栈为空的情况，比如抛出异常，这里简单返回0
    return 0; 
}

/*
 * 出栈 Pop(&s, &e)
 * 功能：若栈不为空，则删除栈顶元素，用e返回其值，并返回OK；否则返回ERROR
 */
Status Pop(LinkStack &s, SElemType &e) {
	StackNode *p;
    if(s==NULL) return ERROR;  // 栈为空
    e = s->data;
    p = s;
    s = s->next;
    free(p);
    return OK;
}

/*
 * 测试链栈的基本操作
 */
void testLinkStack() {
    LinkStack s;
    SElemType e;
    Status status;

    printf("===== 测试链栈 =====\n");

    // 初始化栈
    printf("初始化栈...\n");
    status = InitStack(s);
    if (status == OK) {
        printf("初始化成功\n");
    } else {
        printf("初始化失败\n");
    }

    // 入栈操作
    printf("入栈元素 10, 20, 30...\n");
    Push(s, 10);
    Push(s, 20);
    Push(s, 30);

    // 取栈顶元素
    printf("取栈顶元素...\n");
    e = GetTop(s);
    printf("栈顶元素: %d\n", e);

    // 出栈操作
    printf("出栈元素: ");
    while (Pop(s, e) == OK) {
        printf("%d ", e);
    }
    printf("\n");

    // 再次取栈顶元素（测试空栈情况）
    printf("尝试从空栈取栈顶元素...\n");
    e = GetTop(s);
    printf("栈顶元素: %d\n", e);
}

int main() {
    testLinkStack();
    return 0;
}
