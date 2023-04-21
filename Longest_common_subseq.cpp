#include<string>
#include<iostream>

using namespace std;

int main(){
    string arr1, arr2;
    int DP[100][100], i,j;
    cout<<"Enter string 1"<<endl;
    cin>>arr1;
    cout<<"Enter string 2"<<endl;
    cin>>arr2;
    for (i = 0; i < (arr1.length() + 1); i++){
        DP[i][0] = 0;
    }
    for (i = 0; i < (arr2.length() + 1); i++){
        DP[0][i] = 0;
    }
    for(i=1; i <= arr1.length(); i++){
        for(j=1; j <= arr2.length(); j++){
            if(arr1[i-1]==arr2[j-1])
                DP[i][j] = DP[i-1][j-1] + 1;
            // else if(DP[i-1][j]>DP[i][j-1])//max(DP[i][j-1],DP[i-1][j]);
            //     DP[i][j] = DP[i-1][j];
            // else
            //     DP[i][j] = DP[i][j-1];
            else
                DP[i][j] = max(DP[i][j-1],DP[i-1][j]);
        }
    }
    for(i=0; i <= arr1.length(); i++){
        for(j=0; j <= arr2.length(); j++){
            cout<<DP[i][j]<<" \n"[j==arr2.length()];
        }
    }
    return 0;
}