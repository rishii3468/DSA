#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    string s = "raghav";
    vector<int> v(26,0);
    for(int i=0;i<s.length();i++){
        v[(int)(s[i])-97] += 1;
    }
    int max = v[0];
    for(int i=0;i<26;i++){
        if(max<v[i]) max = v[i];
    }
    for(int i=0;i<26;i++){
        if(max==v[i]) cout<<char(i+97)<<" "<<max<<endl;
    }
}