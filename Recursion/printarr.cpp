#include<iostream>
using namespace std;
void printarr(int arr[],int n,int idx){
    if(n==idx) return;
    cout<<arr[idx]<<" ";
    return printarr(arr,n,idx+1);
}
int main(){
    int arr[] = {3,2,5,5,3,2};
    int length = sizeof(arr)/sizeof(arr[0]);
    printarr(arr,length,0);
}