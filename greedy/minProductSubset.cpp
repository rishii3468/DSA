#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> ans = {-2,-3,1,4,-2,-5};
    bool positive=true,zero=false;
    int neg = 0;
    int n = ans.size();
    int min = INT32_MAX;
    for(int i=0;i<ans.size();i++){
        if(ans[i]==0) zero = true;
        if(ans[i]<0){
            positive = false;
            neg++;
        }
        if(ans[i]<min) min = ans[i];

    }
    if(positive && zero) cout<<0;
    else if(positive) cout<<min;
    else if(neg%2!=0){
        int sum = 1;
        for(int i=0;i<n;i++){
            sum *= ans[i];
        }
        cout<<sum;
    }
    else {
        int sum = 1;
        int max = INT32_MIN;
        for(int i=0;i<n;i++){
           
                sum *= ans[i];
                if(ans[i]<0){  if(max<ans[i]) max = ans[i];
            } 
            
        }
        cout<<sum/max;
    }
}