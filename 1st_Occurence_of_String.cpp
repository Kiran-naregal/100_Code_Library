#include <bits/stdc++.h>
using namespace std;
int strStr(string haystack, string needle)
{
    int j = 0;
    int temp = 0;
    bool flag = 0;
    for (int i = 0; i < haystack.length();)
    {
        if (haystack[i] == needle[j] && j < needle.length())
        {
            if (j == needle.length() - 1)
            {
                flag = 1;
                temp = i - j;
                break;
            }
            i++;
            j++;
        }
        else
        {
            i = i - (j - 1);
            j = 0;
        }
    }
    if (flag)
        return temp;
    return -1;
}
int main()
{

    return 0;
}