#include<iostream>
using namespace std;
int main(){
    int n;

    cout<<"Enter number of columns : ";
    cin>>n;
    int a=7;
    for(int i=1;i<=2*n-1;i++){
        int a = i;
        int b = i-1;
        if (b<n){
            b=2*b-1;
        }
        else{
            b=2*n-(2*i-1)+2;
        }
        if (a<n){
             a=n-a;
        }
        for(int j=1;j<=n-1){
            cout<<" ";
        }
        cout<<"*";
        for (int k=1;k<=b;k++){

        }
        cout<<endl;
    }
}