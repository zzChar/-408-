#include <stdio.h>  // 标准输入输出库，用于printf和scanf等函数
#include <stdlib.h> // 标准库，用于内存分配(malloc, realloc)和exit函数

// 存储空间初始分配量
#define STACK_INIT_SIZE 100       
// 存储空间分配增量
#define STACKINCREMENT 10          

// 定义操作结果状态码
typedef int Status;               // 将int重命名为Status，用于表示函数执行状态
const int OK = 1;                  // 操作成功返回值
const int ERROR = 0;               // 操作失败返回值
const int OVERFLOW = -1;           // 内存溢出错误码
const int STACK_FULL_ERROR = -1;   // 栈满错误码

// 定义栈中元素的数据类型
typedef int SElemType;            // 将int重命名为SElemType，表示栈元素类型

/* 顺序栈结构定义 */
typedef struct {
    SElemType *base;  // 栈底指针，指向栈的起始地址，初始化时分配内存
    SElemType *top;   // 栈顶指针，指向栈顶元素的下一个位置(空栈时等于base)
    int stacksize;    // 当前栈的最大容量，即base指向的内存块大小
} SqStack;

/*
 * 初始化顺序栈
 * 功能：创建一个空的顺序栈，分配初始内存空间
 */
Status InitStack(SqStack &S) {
    S.base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if (!S.base) exit(OVERFLOW);  // 存储分配失败
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    return OK;
}

/*
 * 获取顺序栈的栈顶元素
 * 功能：若栈不为空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR
 */
Status GetTop(SqStack S, SElemType &e) {
    if (S.top == S.base) return ERROR;
    e = *(S.top - 1);
    return OK;
}

/*
 * 顺序栈入栈操作
 * 功能：将元素e压入栈顶，若栈满则自动扩容
 */
Status Push(SqStack &S, SElemType e) {
    if (S.top - S.base >= S.stacksize) {
        SElemType *newBase = (SElemType *)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(SElemType));
        if (!newBase) return STACK_FULL_ERROR;  // 扩容失败
        S.base = newBase;
        S.top = S.base + S.stacksize;
        S.stacksize += STACKINCREMENT;
    }
    *(S.top++) = e;
    return OK;
}

/*
 * 顺序栈出栈操作
 * 功能：若栈不为空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
 */
Status Pop(SqStack &S, SElemType &e) {
    if (S.top == S.base) return ERROR;
    e = *(--S.top);
    return OK;
}

/*
 * 测试顺序栈的基本操作
 * 功能：演示顺序栈的初始化、入栈、出栈和获取栈顶元素操作
 */
void testSqStack() {
    SqStack S;           // 定义顺序栈变量
    SElemType e;         // 用于存储栈顶元素或弹出的元素
    Status status;       // 存储操作结果状态

    printf("===== 测试顺序栈 =====\n");
    
    printf("初始化栈...");
    status = InitStack(S);
    printf("%s\n", status == OK ? "成功" : "失败");

    printf("压入元素 10, 20, 30...\n");
    Push(S, 10);
    Push(S, 20);
    Push(S, 30);

    printf("获取栈顶元素...");
    if (GetTop(S, e) == OK) {
        printf("栈顶元素: %d\n", e);
    } else {
        printf("栈为空，无法获取栈顶元素\n");
    }

    printf("弹出元素: ");
    // 循环弹出所有元素并打印
    while (Pop(S, e) == OK) {
        printf("%d ", e);
    }
    printf("\n");

    printf("尝试从空栈弹出元素...");
    status = Pop(S, e);
    printf("%s\n", status == OK ? "成功" : "失败");
}

/*
 * 主函数
 * 功能：程序入口点，调用测试函数验证顺序栈的功能
 */
int main() {
    testSqStack();
    return 0;
}
