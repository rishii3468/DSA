#include<iostream>
using namespace std;

int maxVal(int arr[],int length,int idx){
    if(idx == length) return INT32_MIN;
    return max(arr[idx],maxVal(arr,length,idx+1));
}
int main(){
    int arr[] = {3,2,5,5,3,2};
    int length = sizeof(arr)/sizeof(arr[0]);
    cout<<maxVal(arr,length,0);
}