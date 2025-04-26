#include<iostream>
using namespace std;
void printn(int i,int n){
    
    if (i>n) return;
    cout<<i<<endl;
    printn(i+1,n);
}
int main(){
    int n,i;
    cin>>i>>n;
    printn(i,n);
}