#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int test, m, n;
    vector<int> team1,team2,sizes;
    cin>>test;
    for(int k=0;k<test;k++){
        cin>>m;
        sizes.push_back(m);
        for(int i=0;i<m;i++){
            int temp;
            cin>>temp;
            team1.push_back(temp);
        }
        cin>>n;
        sizes.push_back(n);
        for(int i=0;i<n;i++){
            int temp;
            cin>>temp;
            team2.push_back(temp);
        }
        vector<int> res;
        int i=0,j=0;
        int s1=team1.size(), s2=team2.size();
        while(i<s1 && j<s2){
            if(team1[i]<team2[j]){
                res.push_back(team1[i]);
                i++;
            } 
            else{
                res.push_back(team2[j]);
                j++;
            }
        }
        if(i<s1){
            while(i<s1){
                res.push_back(team1[i]);
                i++;
            }
        }
        if(j<s2){
            while(j<s2){
                res.push_back(team2[j]);
                j++;
            }
        }
        int s3 = res.size();
        int a=0,b=1;
        if(k==test-1){
            for(int i=0;i<s3;i++){    
        
                cout<<res[i]<<" ";

            }
        cout<<endl;
        }
        
    }


    return 0;
}