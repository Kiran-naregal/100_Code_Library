#include <bits/stdc++.h>
using namespace std;
int xorOperation(int n, int start)
{
    int x = 0;
    int i = 0;
    while (i < n)
    {
        int temp = start + 2 * i;
        x = x ^ temp;
        i = i + 1;
    }

    return x;
}
int main()
{
    int n, start;
    cin >> n >> start;

    cout << xorOperation(n, start);

    return 0;
}