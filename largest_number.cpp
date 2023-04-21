#include<bits/stdc++.h>
using namespace std;

// int main()
// {
//     string str;
//     int K,c=0;
//     cin>>str>>K;
//     int j=0;
//     for(int i=0;i<K;i++)
//     {
//         while(j<str.length()-1)
//         {
//             if(str[j]<str[j+1])
//             {
//                 str.erase(str.begin()+j);
//                 c++;
                
//                 if(j==0)
//                 {
//                     j=0;
//                 }
//                 else{
//                     j--;
//                 }
//                 break;
//             }
//             j++;
//         }
//         if(c!=i+1)
//         {
//             c++;
//             str.erase(str.size()-1);
//         }
//     }
//     cout<<str;
//     return 0;
// }



int main(){
    stack<int> a,b;
    a.push(5);
    a.push(4);
    a.push(3);
    a.push(2);
    a.push(1);
    b=a;
    while(!b.empty()){
        cout<<b.top()<<" ";
        b.pop();
    }
    return 0;
}