#include<iostream>
using namespace std;
int main(){
    int x;
    cout<<"Enter the number: ";
    cin>>x;
    if((x%5==0 || x%3==0) && x%15!=0){
        cout<<"divisible by 3 or 5 but not 15";
    }
    else{
        cout<<"no";
    }
}