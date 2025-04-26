#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int test;
    cin>>test;
    for(int l=0;l<test;l++){
        int n,num=0;
        cin>>n;
        int arr[n+1];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int mult =1;
        for(int i=n-1;i>=0;i--){
            
            num+=mult*arr[i];
            mult*=10;
        }
        num++;
        for(int i=n-1;i>=0;i--){
            arr[i] = num %10;
            num=num/10;
        }
        if(arr[0]==0){
            arr[0]=1;
            arr[n] = 0;
            for(int i=0;i<n+1;i++){
                cout<<arr[i]<<" ";
            }
        }
        else{
            for(int i=0;i<n;i++){
                cout<<arr[i]<<" ";
            }
        }
        
    }
    return 0;
}