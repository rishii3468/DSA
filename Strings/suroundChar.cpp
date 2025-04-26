#include<iostream>
#include<string>
using namespace std;
int main(){
    string s = "ab";
    int count = 0;
    for(int i=0;i<s.size();i++){
        if(s.size() == 1){
            break;
        }
        if(i==0){
            if(s[i]!=s[i+1]) count++;
        }
        else if(i==s.size()-1){
            if(s.size() == 2) break;
            if(s[i]!=s[i-1]) count++;
        }
        else{
            if(s[i]!=s[i+1] && s[i]!=s[i-1]) count++;
        }
    }
    cout<<count;
}
