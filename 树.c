//暴力建树
#include <stdio.h>
#include <malloc.h>

struct BTNode //Binary Tree
{
  int data;
  struct BTNode *pL;
  struct BTNode *pR;
};

struct BTNode *CreateBTree();
void PreTraverseBTree(struct BTNode *);
void InTraverseBTree(struct BTNode *);
void PostTraverseBTree(struct BTNode *);

int main()
{
  struct BTNode *pT = CreateBTree(); //动态造树,因为这样函数终止空间还能用
  PreTraverseBTree(pT);
  printf("\n");
  InTraverseBTree(pT);
  printf("\n");
  PostTraverseBTree(pT);

  return 0;
}

struct BTNode *CreateBTree()
{
  struct BTNode *pA = (struct BTNode *)malloc(sizeof(struct BTNode));
  //pA 指向节点
  struct BTNode *pB = (struct BTNode *)malloc(sizeof(struct BTNode));
  struct BTNode *pC = (struct BTNode *)malloc(sizeof(struct BTNode));
  struct BTNode *pD = (struct BTNode *)malloc(sizeof(struct BTNode));
  struct BTNode *pE = (struct BTNode *)malloc(sizeof(struct BTNode));
  pA->data = 'A';
  pB->data = 'B';
  pC->data = 'C';
  pD->data = 'D';
  pE->data = 'E';
  pA->pL = pB;
  pA->pR = pC;
  pB->pL = NULL;
  pB->pR = NULL;
  pC->pL = pD;
  pC->pR = NULL;
  pD->pL = NULL;
  pD->pR = pE;
  pE->pL = NULL;
  pE->pR = NULL;
  return pA;
}
void PreTraverseBTree(struct BTNode *pT)
{
  if (pT != NULL)
  {
    //根左右
    printf("%c\n", pT->data);
    if (pT->pL != NULL)
      PreTraverseBTree(pT->pL); //代表左子树
    if (pT->pR != NULL)
      PreTraverseBTree(pT->pR);
    return;
  }
}
void InTraverseBTree(struct BTNode *pT)
{
  if (pT != NULL)
  {
    if (pT->pL != NULL)
      PreTraverseBTree(pT->pL); //代表左子树
    printf("%c\n", pT->data);
    if (pT->pR != NULL)
      PreTraverseBTree(pT->pR);
  }
  return;
}
void PostTraverseBTree(struct BTNode *pT)
{
  if (pT != NULL)
  {
    if (pT->pL != NULL)
      PreTraverseBTree(pT->pL); //代表左子树
    if (pT->pR != NULL)
      PreTraverseBTree(pT->pR);
    printf("%c\n", pT->data);
    return;
  }
}
/*
完全二叉树:
     1
  1     1
P  Q  M   N
按照 N,M,Q,P 删就是完全二叉树
数组存树的条件:完全二叉树
优点:直接找出父节点&子节点
缺点:空间消耗大
链表存树:
不消耗空间

二叉树表示法:

保证任意一个节点的左指针域指向第一个孩子
右指向 兄弟

先序遍历:
根左右
中:
左根右
后:
左右根

通过 先中/中后 可以确定
*/