#include<iostream>
#include<unordered_set>
using namespace std;
int main(){
  unordered_set<int> s;
  s.insert(1);
  s.insert(2);
  s.insert(3);
  s.insert(4);
  s.insert(5);
  s.erase(2);
  int target = 4; 
  // is s.find() doesn't find the ele then returns last iterator after last element
  if(s.find(target)!=s.end()){
    cout<<"Exits"<<endl;
  }
  else{
    cout<<"Does not exist";
  }
  for(int ele : s){
    cout<<ele<<" ";
  }
}