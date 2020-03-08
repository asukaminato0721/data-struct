#include <stdio.h>
#include <malloc.h>  //包含 malloc 函数
#include <stdlib.h>  //包含 exit 函数
#include <algorithm> //swap
// using namespace std;
//数据类型
struct Arr
{
    int *pBase; //第一个元素位置
    int len;    //容量
    int cnt;    //有效元素个数
    //    int increase; //自动增长因子
};
void init_arr(struct Arr *pArr, int length);
bool append_arr(struct Arr *pArr, int val);
bool insert_arr(struct Arr *pArr, int pos, int val); // pos from 1
bool delete_arr(struct Arr *pArr, int pos, int *pVal);
bool get(); // too easy to write
bool is_empty(struct Arr *pArr);
bool is_full(struct Arr *pArr);
void sort_arr(struct Arr *pArr);
void show_arr(struct Arr *pArr);
void inversion_arr(struct Arr *pArr);
int main()
{
    struct Arr arr;
    int val;
    init_arr(&arr, 4);
    // show_arr(&arr);
    append_arr(&arr, 76);
    append_arr(&arr, 33);
    append_arr(&arr, 67);
    // append_arr(&arr, 3);
    insert_arr(&arr, 2, 3);
    show_arr(&arr);
    inversion_arr(&arr);
    show_arr(&arr);
    sort_arr(&arr);
    show_arr(&arr);
    // if (append_arr(&arr, 3))
    //     printf("succ");
    // else
    //     printf("fail");
    return 0;
}

void init_arr(struct Arr *pArr, int length) //结构体可以互相赋值
{
    pArr->pBase = (int *)malloc(sizeof(int) * length);
    if (NULL == pArr->pBase)
    {
        printf("失败");
        exit(-1);
    }
    else
    {
        pArr->len = length;
        pArr->cnt = 0;
    }
    return;
}
bool is_empty(struct Arr *pArr)
{
    if (0 == pArr->cnt)
        return true;
    else
    {
        return false;
    }
}
bool is_full(struct Arr *pArr)
{
    if (pArr->cnt == pArr->len)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void show_arr(struct Arr *pArr)
{                       //pArr 已经存放了地址
    if (is_empty(pArr)) //如果空，提示空，else 输出内容
    {
        printf("empty \n");
    }
    else
    {
        for (int i = 0; i < pArr->cnt; i++)
        {
            printf("%d   ", pArr->pBase[i]); //int *
        }
        printf("\n");
    }
}
bool append_arr(struct Arr *pArr, int val)
{
    if (is_full(pArr))
    {
        return false;
    }
    else //不满，通过试数知道赋值 cnt
    {
        pArr->pBase[pArr->cnt] = val;
        (pArr->cnt)++;
        return true;
    }
}

bool insert_arr(struct Arr *pArr, int pos, int val)
{
    if (is_full(pArr))
    {
        return false;
    }
    if (pos < 1 || pos > pArr->cnt + 1)
    {
        return false;
    }
    for (int i = pArr->cnt - 1; i >= pos - 1; --i)
    {
        pArr->pBase[i + 1] = pArr->pBase[i]; // i 处的值赋给 i+1
    }
    pArr->pBase[pos - 1] = val;
    (pArr->cnt)++;
    return true;
}
bool delete_arr(struct Arr *pArr, int pos, int *pVal)
{
    if (is_empty(pArr))
    {
        return false;
    }
    if (pos < 1 || pos > pArr->cnt)
    {
        return false;
    }
    *pVal = pArr->pBase[pos - 1];
    for (int i = pos; i < pArr->cnt; i++)
    {
        pArr->pBase[i - 1] = pArr->pBase[i]; //i 赋给 i-1
    }
    pArr->cnt--;
    return true;
}
void inversion_arr(struct Arr *pArr)
{
    int i = 0, j = pArr->cnt - 1;
    int t;
    while (i < j)
    {
        std::swap(pArr->pBase[i], pArr->pBase[j]);
        i++;
        j--;
    }
    return;
}
void sort_arr(struct Arr *pArr)
{
    int i, j;
    for (int i = 0; i < pArr->cnt; i++)
    {
        for (int j = i + 1; j < pArr->cnt; j++)
        {
            if (pArr->pBase[i] > pArr->pBase[j])
                std::swap(pArr->pBase[i], pArr->pBase[j]);
        }
    }
    return;
}