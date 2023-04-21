#include <iostream> 
using namespace std; 
int main() { 
 long long T, n, j; 
    long long arr[300000], extra=0, flag; 
    cin>>T; 
    if(T<1 || T>100000) 
        exit(0); 
    for(long long i=0; i<T; i++){ 
        cin>>n; 
        if(n<1 || n>300000) 
            exit(0); 
        for(j=0; j<n;j++){ 
            cin>>arr[j]; 
        } 
        extra = 0;
        flag = 0; 
        for(j=0; j<n; j++){ 
            if(arr[j]==(j+1)) 
                continue; 
            if(arr[j] > (j+1)){ 
                extra += (arr[j] - (j+1)); 
            } 
            else{ 
                if(extra < ((j+1) - arr[j])){ 
                    flag++; 
                    break; 
                } 
                extra -= ((j+1) - arr[j]); 
            } 
        } 
        if(flag == 1 || extra != 0) 
            cout<<"NO"<<endl; 
        else 
            cout<<"YES"<<endl; 
    } 
    return 0; 
}
