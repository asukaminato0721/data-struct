// n 个节点离散分配
// 用指针相连
// 只有前驱,后续
// 首节点:第一个有效节点
// 尾节点:finally
// 头结点: 不存放有效数据
// 头指针: 指向头结点
// 头 -> 首 ->  ->  ->  尾
// 只需要头指针就行
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *pNext;
};

struct Node *init();
bool insert(struct Node *, int, int);
bool delete (struct Node *, int, int *);
void sort(struct Node *);
bool is_empty(struct Node *);
void traverse(struct Node *);
int length(struct Node *);

int main()
{
    int val;
    struct Node *pHead = init();
    traverse(pHead);
    //    printf("%d", length(pHead));
    sort(pHead);
    traverse(pHead);
    delete (pHead, 2, &val);
    traverse(pHead);
    insert(pHead, 2, 4);
    traverse(pHead);
    return 0;
}

struct Node *init()
{
    int len;
    printf("len: ");
    scanf("%d", &len);
    struct Node *pHead = (struct Node *)malloc(sizeof(struct Node));
    struct Node *pTail = pHead; //p:pTail
    pTail->pNext = NULL;
    for (int i = 0; i < len; i++)
    {
        int val;
        printf("%dth:", i + 1);
        scanf("%d", &val);
        struct Node *pNew = (struct Node *)malloc(sizeof(struct Node));
        //这里很妙
        pNew->data = val;
        pTail->pNext = pNew;
        pNew->pNext = NULL;
        pTail = pNew;
    }
    // pHead->pNext = NULL;
    return pHead;
}
void traverse(struct Node *pHead)
{
    struct Node *p = pHead->pNext;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->pNext;
    }
    printf("\n");
}
bool insert(struct Node *pHead, int pos, int val)
{
    int i;
    struct Node *p = pHead;
    //循环到p指向pos-1的位置
    while (NULL != p && i < pos - 1)
    {
        p = p->pNext;
        ++i;
    }
    if (NULL == p || i > pos - 1)
    {
        return false;
    }
    //插入的数申请内存
    struct Node *pNew = (struct Node *)malloc(sizeof(struct Node));
    if (NULL == pNew)
    {
        printf("分配内存失败，程序终止！\n");
        exit(-1);
    }
    pNew->data = val;
    struct Node *q = p->pNext;
    p->pNext = pNew;
    pNew->pNext = q;
    return true;
}

bool is_empty(struct Node *pHead)
{
    pHead->pNext == NULL ? true : false;
}

bool delete (struct Node *pHead, int pos, int *pVal)
{
    int i;
    struct Node *p = pHead;
    //循环到p指向pos-1的位置
    while (NULL != p->pNext && i < pos - 1)
    {
        p = p->pNext;
        ++i;
    }
    if (NULL == p->pNext || i > pos - 1)
    {
        return false;
    }
    struct Node *q = p->pNext;
    *pVal = p->data;
    p->pNext = q->pNext;
    free(q);
    q = NULL;
    return true;
}

int length(struct Node *pHead)
{
    int l = 0;
    struct Node *p = pHead->pNext;
    while (p != NULL)
    {
        l++;
        p = p->pNext;
    }
    return l;
}
void sort(struct Node *pHead)
{
    int i, j, t;
    struct Node *p, *q;
    int len = length(pHead);
    for (i = 0, p = pHead->pNext; i < len - 1; i++, p = p->pNext)
    {
        for (j = i + 1, q = p->pNext; j < len; j++, q = q->pNext)
        {
            if (p->data > q->data)
            {
                t = p->data;
                p->data = q->data;
                q->data = t;
            }
        }
    }
}