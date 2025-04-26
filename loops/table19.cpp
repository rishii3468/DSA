#include<iostream>
using namespace std;
int main(){
    int a=1,b=2;
    int *p1=&a, *p2=&b;
    cout<<*p1<<" "<<*p2;
}