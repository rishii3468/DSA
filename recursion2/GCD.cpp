#include<iostream>
using namespace std;
int gcd(int a, int b){
    int rem = b%a;
    if(rem == 0) return a;
    else gcd(rem,a);
}
int main(){
    cout<<gcd(27,27);
}