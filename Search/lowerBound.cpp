#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v = {1,2,4,5,9,15,18,21,24,45,67};
    int low = 0;
    int high = v.size()-1;
    int target = 67;
    while(true){
        int mid = low + (high-low)/2;
        if(target == v[mid]){
            cout<<v[mid-1];
            break;
        } 
        if(high-low == 1 || high == low){
            cout<<v[low];
            break;
        }

        else if(v[mid]<target) low = mid;
        else high = mid-1;
    }
}   