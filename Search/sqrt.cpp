#include<iostream>
using namespace std;
int main(){
    int x = 26;
    int low = 0;
    int high = x;
    int mid;
    bool flag = false;
    while(low<=high){
        mid = low + (high-low)/2;
        if(mid*mid == x){
            flag = true;
            cout<<mid;
            break;
        } 
        else if(mid*mid > x){
            high = mid-1;
        } 
        else low = mid +1;
    }
    if(flag==false){
        if(mid*mid>x) cout<<mid-1;
        else cout<<mid;
    }
}