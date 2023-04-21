#include <bits/stdc++.h>
using namespace std;
double myPow(double x, int n)
{
    if (n == INT_MAX)
        return (x == 1) ? 1 : (x == -1) ? -1
                                        : 0;
    if (n == INT_MIN)
        return (x == 1 || x == -1) ? 1 : 0;
    if (x == 1)
        return 1;
    double res = 1.0;
    long ind = n;
    if (n < 0)
        ind = -1 * ind;

    while (ind > 0)
    {
        if (ind % 2 >= 0)
        {
            res = res * x;
            ind = ind - 1;
        }
        else
        {
            x = x * x;
            ind = ind / 2;
        }
    }

    if (n < 0)
        return (double)1 / (double)res;

    return res;
}
int main()
{
    cout<<myPow(2,2);
    return 0;
}