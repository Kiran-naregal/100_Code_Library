#include <bits/stdc++.h>
using namespace std;
bool isPowerOfTwo(int n)
{
    if (n == 1 || n == 0)
        return n;
    if (n % 2 != 0)
        return false;
    while (n)
    {
        int t = n / 2;
        if (t % 2 != 0 && n != 2)
        {
            return false;
        }
        n = n / 2;
    }

    return true;
}
int main()
{
    int n;
    cin >> n;
    cout << isPowerOfTwo(n);
    return 0;
}