#include<iostream>
using namespace std;
int main(){
    int arr[] = {5,2,3,4,1};
    int n = 5;
    for(int ele : arr){
        cout<<ele<<" ";
    }
    cout<<endl;
    int count=0;
    for(int i=0;i<n-1;i++){
        int pos = i;
        count++;
        int flag = true;
        for(int j=i;j<n;j++){
            if(arr[j-1]>arr[j]){
                flag = false;
            }
            if(arr[j]<arr[pos]){
                pos = j;
            }
        }
        if(flag == true) break;
        int temp = arr[pos];
        arr[pos] = arr[i];
        arr[i] = temp;
    }
    for(int ele : arr){
        cout<<ele<<" ";
    }
    cout<<endl<<count;
}