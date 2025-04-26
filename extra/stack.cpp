#include<iostream>
using namespace std;

int countLayer(int n){
    int ans=n;
    for(int i=0;;i++){
        ans -= i;
        if(ans>n/2) break;
    }
}

int main(){
    int n = 6;
    cout<<1/2;
}