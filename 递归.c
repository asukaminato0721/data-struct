#include <stdio.h>

int sum(int n, int s)
{
    if (n == 0)
    {
        return s;
    }
    else
    {
        s += n;
        return sum(n - 1, s);
    }
}

int main()
{
    int s = 0;
    printf("%d\n", sum(100, s));
    printf("%d", s);
    return 0;
}
