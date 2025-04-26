#include<iostream>
using namespace std;
void printn(int sum,int n){
    if(n==0){
        cout<<sum;
        return;
    }
    printn(sum + n,n-1);
}
int main(){
    int n,sum=0;
    cin>>n;
    printn(sum,n);
}