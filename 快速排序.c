#include <stdio.h>

void QuickSort(int *, int, int);
int FindPos(int *, int, int);
int main()
{
    int a[] = {-2e4, 2, 2e5, 2 << 1, 3 << 4, 3};
    //printf("%d\n", FindPos(a, 0, 5));
    QuickSort(a, 0, 5);
    for (int i = 0; i < 6; i++)
    {
        printf("%d\n", a[i]);
    }
    return 0;
}

int FindPos(int *a, int low, int high)
{
    int val = a[low];
    while (low < high) //这 4 行是精华
    {
        while (low < high && a[high] >= val)
            --high;
        a[low] = a[high];
        while (low < high && a[low] <= val)
            ++low;
        a[high] = a[low];
    }
    a[low] = val;
    return low;
}

void QuickSort(int *a, int low, int high)
{
    if (low < high)
    {
        int pos = FindPos(a, low, high);
        QuickSort(a, low, pos - 1);
        QuickSort(a, pos + 1, high);
    }
}