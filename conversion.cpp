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
    StackNode *p = new StackNode;
    if (!p) return ERROR;  // 内存分配失败
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
    if (!s) return ERROR;  // 栈为空
    e = s->data;
    StackNode *p = s;
    s = s->next;
    delete p;
    return OK;
}

/*
 * 判断栈是否为空 StackEmpty(s)
 * 功能：若栈为空，返回1；否则返回0
 */
int StackEmpty(LinkStack s) {
    return s == NULL;
}

/*
 * 将十进制数转换为八进制数 conversion()
 * 功能：对于输入的任意一个非负十进制数，打印输出与其等值的八进制数
 *本质上和书上的内容一样，只是为了做测试代码，所以添加了一些，请仔细查看 
 */
void conversion() {
    LinkStack S;
    SElemType N, e;
    InitStack(S);  // 构造空栈
    printf("请输入一个非负十进制数: ");
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
