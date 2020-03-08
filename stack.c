#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>
// pop
// push

typedef struct Node
{
    int data;
    struct Node *pNext;
} NODE, *PNODE;

typedef struct Stack
{
    PNODE pTop;
    PNODE pBottom; // pBottom 指向头
} STACK, *PSTACK;

void init(PSTACK);
void push(PSTACK, int);
bool pop(PSTACK, int *);
void traverse(PSTACK); //遍历输出
void clear(PSTACK pS);

int main()
{
    STACK S; //S 有 pTop pBottom
    init(&S);
    int val;
    push(&S, 7);
    push(&S, 3);
    push(&S, 5);
    push(&S, 6);
    push(&S, 8);
    pop(&S, &val);
    traverse(&S);
    if (pop(&S, &val))
    {
        printf("succ\n");
    }
    else
    {
        printf("fail\n");
    }

    traverse(&S);
    clear(&S);
    traverse(&S);
    if (pop(&S, &val))
        printf("succ");
    else
    {
        printf("fail\n");
    }

    return 0;
}

void init(PSTACK pS)
{
    pS->pTop = (PNODE)malloc(sizeof(NODE));
    // S 是个栈,pTop 指向一个新申请的节点
    if (NULL == pS->pTop)
    {
        printf("fail\n");
        exit(-1);
    }
    else
    {
        pS->pBottom = pS->pTop;
        pS->pTop->pNext = NULL;
    }
    // 经过这一步,
    // pTop -> 新节点 S
    // 新节点 S 的指针域为空
    //
    // pBottom -> 新节点 S
}

void push(PSTACK pS, int val)
{
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    pNew->data = val;
    pNew->pNext = pS->pTop; // 指向栈顶
    pS->pTop = pNew;
    return;
}

void traverse(PSTACK pS)
{
    PNODE p = pS->pTop;
    while (p != pS->pBottom)
    {
        printf("%d  ", p->data);
        p = p->pNext;
    }
    printf("\n");
    return;
}
bool empty(PSTACK pS)
{
    if (pS->pTop == pS->pBottom)
        return true;
    else
        return false;
}

bool pop(PSTACK pS, int *pVal)
{
    if (empty(pS))
        return false;
    else
    {
        PNODE r = pS->pTop;
        *pVal = r->data;
        pS->pTop = pS->pTop->pNext; //这里写 r->pNext 也行
        free(r);
        r = NULL;
        return true;
    }
}
void clear(PSTACK pS)
{
    if (empty(pS))
        return;
    else
    {
        PNODE p = pS->pTop;
        PNODE q = NULL;
        while (p != pS->pBottom)
        {
            q = p->pNext;
            free(p);
            p = q;
        }
        pS->pTop = pS->pBottom;
    }
}
/*

首先 init

pTop
pBottom

都指向头结点



*/