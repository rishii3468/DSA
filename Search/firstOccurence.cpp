#include<iostream>
using namespace std;
int main(){
    int arr[] = {1,2,2,3,3,3,3,3,4,4,5,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int low = 0;
    int high = n-1;
    int target = 3;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid]==target){
            if(arr[mid-1]==target) high = mid-1;
            else {
                cout<<mid;
                break;
            }
        }
        else if(arr[mid]<target) low = mid+1;
        else high = mid-1;
    }
}