#include<iostream>
#include<vector>
using namespace std;
bool check(int mid, vector<int>& weights, int days){
        int i = 0;
        int count = 0;
        while(i<weights.size()){
            int sum = 0;
            while(sum<=mid){
                sum += weights[i];
                if(sum<=mid) i++; 
            }
            count++;
        }
        if(count>days) return false;
        else return true;
    }
int main(){
    vector<int> v = {3,2,2,4,1,4};
    cout<<check(6,v,3);
}