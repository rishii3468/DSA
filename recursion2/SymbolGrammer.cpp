#include<iostream>
#include<string>
using namespace std;
int gram(string s,int row,int n, int k){

    for(int i=0;i<s.size();i++){
        if(s[i]=='0') gram("01",row+1,n,k);
        else if(s[i]=='1') gram("10",row+1,n,k);
        if(i==k && n==row) return s;
    }
}

int main(){
    cout<<gram("0",1,3,4);
}