#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v;
    int arr[] = {0,1,2,3,4,5,6,7,8,9};
    int n = 10;
    int low = 0;
    int high = n-1;
    int mid;
    while(low<=high){
        mid = low + (high-low)/2;
        if(arr[mid]==mid) low = mid+1;
        if(arr[mid]>mid) high = mid-1;
    }
    if(mid == n-1) cout<<-1;
    else cout<<mid;
}