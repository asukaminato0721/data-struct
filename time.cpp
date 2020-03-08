#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
clock_t start, stop;
double during;
void myfunc()
{
    vector<int> a = {1, 2, 3, 4, 5};
    for (auto num : a)
    {
    }
}
int main()
{
    start = clock();
    for (int i = 0; i < 10000; i++)
    {
        myfunc();
    }
    stop = clock();
    during = (double)(stop - start) / CLK_TCK;
    cout << during;
    return 0;
}