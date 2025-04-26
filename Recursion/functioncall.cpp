#include<iostream>
using namespace std;
void greet(int n){
    if(n==0) return;
    cout<<"goodmorning"<<endl;
    greet(n-1);
}
int main(){
    int n;
    cin>>n;
    greet(n);
    return 0;
}