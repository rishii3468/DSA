#include<iostream>
using namespace std;
int power(int a,int b){
    if(a==0 && b==0) return -1;
    if(b==0) return 1;

    return a*power(a,b-1);
}
int main(){
    int a=0, b=0;
    cout<<power(a,b);
}