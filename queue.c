#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

//静态队列
//    循环队列:
//        为何是循环队列:利用空间
//        需要几个参数:2
//        参数的意义:front rear
//        初始化: front = rear = 0
//        非空,[front,rear)
//        空,front=end 不一定=0
//        入队算法
//        出队
//        为空 front=rear
//        已满,无法区分 是空还是满
//        1. 新增一个 cnt 统计个数(麻烦)
//        2. 规定只存放 length-1 个元素,
//链式队列
//出队
//入队

typedef struct Queue
{
    int *pBase;
    int front;
    int rear;
} QUEUE, *pQUEUE;

void init(QUEUE *);

bool empty(QUEUE *);
bool full(QUEUE *);
bool en_queue(QUEUE *, int val);
void traverse_queue(QUEUE *);
bool out(QUEUE *, int *);

int main()
{
    int val;
    QUEUE Q;
    init(&Q);
    en_queue(&Q, 1);
    en_queue(&Q, 2);
    en_queue(&Q, 3);
    en_queue(&Q, 4);
    en_queue(&Q, 5);
    en_queue(&Q, 6);
    en_queue(&Q, 7);
    en_queue(&Q, 8);
    traverse_queue(&Q);
    printf("\n");
    out(&Q, &val);
    printf("%d", val);
    printf("\n");
    traverse_queue(&Q);
    printf("\n");
    return 0;
}

void init(QUEUE *pQ)
{
    pQ->pBase = (int *)malloc(sizeof(int) * 6);
    pQ->front = 0;
    pQ->rear = 0;
}

bool en_queue(QUEUE *pQ, int val)
{
    if (full(pQ))
        return true;
    else
    {
        pQ->pBase[pQ->rear] = val;
        pQ->rear = (pQ->rear + 1) % 6;
        return true;
    }
}

bool empty(QUEUE *pQ)
{
    return pQ->front == pQ->rear ? true : false;
}

bool full(QUEUE *pQ)
{
    //return abs(front - rear) == 1 ? true : false;
    return (pQ->rear + 1) % 6 == pQ->front ? true : false;
}
void traverse_queue(QUEUE *pQ)
{
    int i = pQ->front;
    while (i != pQ->rear)
    {
        printf("%d  ", pQ->pBase[i]);
        i = (i + 1) % 6;
    }
    return;
}

bool out(QUEUE *pQ, int *pVal)
{
    if (empty(pQ))
        return false;
    else
    {
        *pVal = pQ->pBase[pQ->front];
        pQ->front = (pQ->front + 1) % 6;
        return true;
    }
}