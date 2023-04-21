#include<bits/stdc++.h>
using namespace std;

string frequencySort(string s)
{
    string temp = "";
    string t = "";
    int flag = 0;
    for(int i = 0; i < s.size(); i++)
    {
        flag = 0;
        for(int j = 0; j < temp.size(); j++)
        {
            if(s[i] == temp[j])
            {
                flag = 1;
            }
        }

        if(flag == 0)
            temp += s[i];
    }

    sort(temp.begin(),temp.end());

    int count[temp.size()],count1[temp.size()],cnt = 0;

    for(int i = 0; i < temp.size(); i++)
    {
        count[i] = 0;
        count1[i] = 0;
    }

    for(int i = 0; i < temp.size(); i++)
    {
        for(int j = 0; j < s.size(); j++)
        {
            if(temp[i] == s[j])
            {
                count[cnt]++;
                count1[cnt]++;
            }
        }

        cnt++;
    }


    sort(count, count + temp.size(), greater<int>());
    for(int i = 0; i < cnt; i++)
    {
        for(int j = 0; j < cnt; j++)
        {
            if(count[i] == count1[j])
            {
                while(count[i]--)
                {
                    t += temp[j];
                }
                count1[j] = 0;
                break;
            }
        }
    }

    return t;
}

int main()
{
    string f;
    cin >> f;
    string d = frequencySort(f);
    cout << d << endl;
}