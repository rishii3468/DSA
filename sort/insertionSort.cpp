#include<iostream>
using namespace std;
int main(){
    int arr[] = {6,3,6,2,3,34,6,3,23,2};
    int n = 10;
    for(int ele : arr){
        cout<<ele<<" ";
    }
    cout<<endl;
    for(int i=1;i<n;i++){
        int j = i;
        if(arr[j-1]>arr[j] ){
            while(arr[j-1]>arr[j] && j>=1){
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
                j--;
            }
        }
    }
    for(int ele : arr){
        cout<<ele<<" ";
    }
}