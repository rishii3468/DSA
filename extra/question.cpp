#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;
string solve(vector<vector<string>> &paths){
    unordered_set<string> in;
    for(auto el : paths){
        in.insert(el[0]);

    }
    for(auto el : paths){
        if(in.find(el[1]) == in.end()){
            return el[1];
        }
    }
    return "";
}

int main(){
    vector<vector<string>> paths = {{"London","New York"},{"New York","Lima"},{"Lima", "Sao Paulo"}};
    string ans = solve(paths);
    cout<<ans;
}