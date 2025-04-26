#include<iostream>
using namespace std;
int main(){
    int x;
    cout<<"Enter number: ";
    cin>>x;
    if(x/100>=1 && x/999<1){
        cout<<"It is three digit";
    }
    else{
        cout<<"It's not";
    }
    return 0;
}