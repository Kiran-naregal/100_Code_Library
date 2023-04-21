#include <bits/stdc++.h>
using namespace std;
int MOD = 1e9 + 7;
long long power(long long a, long long b)
{
    if (b == 0)
    {
        return 1;
    }
    long long r = power(a, b / 2);
    r *= r;
    r %= MOD;
    if (b % 2)
    {
        r *= a;
    }
    r %= MOD;
    return r;
}
int countGoodNumbers(long long n)
{
    // long long r= pow(10,9)+8;
    // long long temp=1;
    // long long t=1;
    // long int res=1;
    // if(n%2==0)
    // {
    //     temp=pow(5,n/2);
    //     t=pow(4,n/2);
    //     res=(temp*t);
    // }
    // else
    // {
    //     temp=pow(4,n/2);
    //     t=pow(5,n-(n/2));
    //     res=(temp*t);
    // }
    // while(n)
    // {
    //     if(n%2==0)
    //     {
    //         res*=4;
    //     }
    //     else
    //     {
    //         res*=5;
    //     }
    //     n--;
    // }
    // int ans=res%r;
    // return ans;

    long long oddplaces = n / 2;
    long long evenplaces = n / 2 + n % 2;

    return (power(5, evenplaces) * power(4, oddplaces)) % MOD;
}
int main()
{

    return 0;
}