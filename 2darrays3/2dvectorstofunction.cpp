#include<iostream>
#include<vector>
using namespace std;
void changevec(vector< vector<int> > &v){
    v[0][1] = 7;
}

int main(){
    vector< vector<int> > v;
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(1);
    v1.push_back(1);
    vector<int> v2;
    v2.push_back(1);
    v2.push_back(1);
    v2.push_back(1);
    v.push_back(v1);
    v.push_back(v2);
    changevec(v);
    cout<<v[0][1];
    return 0;

}