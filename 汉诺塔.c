#include <stdio.h>
void h(int n, char A, char B, char C)
{
    /*如果就一个盘子
    A 上的第 n 个移动到 C
    else
    先 A 的 n-1 to B by C
    A 的第 n 个盘子to C
    最后 B 的 n-1 to C by A
    */
    if (1 == n)
    {
        printf("let %d panzi from %c to %c\n", n, A, C);
    }
    else
    {
        h(n - 1, A, C, B);
        printf("let %d panzi from %c to %c\n", n, A, C);
        h(n - 1, B, A, C);
    }
}
int main()
{
    h(5, 'A', 'B', 'C');
    return 0;
}