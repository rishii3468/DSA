#include<iostream>
#include<vector>
using namespace std;


int main(){
    vector< vector<int> > v(3,vector<int> (4));
    v[0][0] = 0;
    v[0][1] = 0;
    v[0][2] = 1;
    v[0][3] = 1;    
    v[1][0] = 1; 
    v[1][1] = 0; 
    v[1][2] = 1; 
    v[1][3] = 0;
    v[2][0] = 1; 
    v[2][1] = 1; 
    v[2][2] = 0; 
    v[2][3] = 0; 
    for(int i=0;i<v.size();i++){
        if(v[i][0] == 0){
            for(int j=0;j<v[i].size();j++){
                if(v[i][j] == 0) v[i][j] = 1;
                else v[i][j] = 0;
            }
        }
    }
    for(int i=1;i<v[0].size();i++){
        int count1 = 0, count0 = 0;
        for(int j=0;j<v.size();j++){
            if(v[j][i] == 1) count1++;
            else count0++;
        }
        if (count0>count1){
            for(int j=0;j<v.size();j++){
                if(v[j][i] == 0) v[j][i] = 1;
                else v[j][i] = 0;
            }
        }
    }
    int sum = 0;
    for(int i=0;i<v.size();i++){
        int x = 1;
        for(int j=v[i].size()-1;j>=0;j--){
            sum+=v[i][j] * x;
            x*=2;
        }
    }
    cout<<"Highest sum = "<<sum;
}