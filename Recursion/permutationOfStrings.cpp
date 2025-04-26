#include<iostream>
#include<string>
using namespace std;

void permutations(string s1,string s2){
    if(s2.size()==0){
        cout<<s1<<endl;
    }
    for(int i=0;i<s2.size();i++){
        string s;
        if(i==s2.size()-1){
            s = s2.substr(0,s2.size()-1);
        }
        else{
            if(i==0) s=s2.substr(1);
            else s = s2.substr(0,i) + s2.substr(i+1);
        }
        permutations(s1+s2[i],s);
    }
}

int main(){
    permutations("","abcd");
}