#include<iostream>
using namespace std;
int main(){
    int arr[] = {1,2,3,4,5,6,5,4,3};
    int n = 9;
    int low = 1;
    int high = n-2;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid-1]<arr[mid] && arr[mid+1]<arr[mid]){
            cout<<mid;
            break;
        }
        else if(arr[mid-1]>arr[mid]) high = mid-1;
        else low = mid+1;
    }
}