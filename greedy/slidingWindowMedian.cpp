#include <iostream>
#include <queue>
#include<unordered_map>
#include <vector>
using namespace std;

double getMedian(priority_queue<int> &left,priority_queue<int,vector<int>,greater<int>> &right, int x, int y){
  int totalSize = x+y;
  if(totalSize%2 !=0){
    return right.top();
  }
  else{
    return (left.top()+right.top())/2.0;
  }
}

bool isBalanced(int x, int y){
  return (x == y) || (x+1 ==y) ;
}

vector<double> sliding_median(vector<int> &arr, int n, int k)
{
  priority_queue<int> left;
  priority_queue<int,vector<int>,greater<int>> right;
  right.push(arr[0]);
  int x =0,y=1;
  for(int i=1;i<k;i++){
    int curr = arr[i];
    double med = getMedian(left,right,x,y);
    if(curr < med){
      left.push(curr);
      x++;
      if(!isBalanced(x,y)){
        right.push(left.top());
        left.pop();
        x--;
        y++;
      }
    }
    else{
      right.push(curr);
      y++;
      if(!isBalanced(x,y)){
        left.push(right.top());
        right.pop();
        y--;
        x++;
      }
    }
  }
  double m = getMedian(left,right,x,y);
  vector<double> result;
  result.push_back(m);
  unordered_map<int,int> mp;
  for(int i=k; i<n;i++){
    int newElementIndex = i;
    int oldElementToBeDeleted = i-k;
    double med = getMedian(left,right,x,y);
    if(arr[newElementIndex] >= med){
      right.push(arr[newElementIndex]);
      y++;
      if(!isBalanced(x,y)){
        left.push(right.top());
        right.pop();
        y--;
        x++;
      }
    } else{
      left.push(arr[newElementIndex]);
      x++;
      if(!isBalanced(x,y)){
        right.push(left.top());
        left.pop();
        x--;
        y++;
      }
    }
    mp[arr[oldElementToBeDeleted]] = oldElementToBeDeleted;
    if(arr[oldElementToBeDeleted] < right.top()) x--;
    else y--;
    while(mp.count(left.top())){
      mp.erase(left.top());
      left.pop();
    
      
      if(!isBalanced(x,y)){
        left.push(right.top());
        right.pop();
        y--;
        x++;
      }
    }
    while(mp.count(right.top())){
      mp.erase(right.top());
      right.pop();
  
      if(!isBalanced(x,y)){
        right.push(left.top());
        left.pop();
        x--;
        y++;
      }
    }
    cout<<"top ele "<<left.top()<<" "<<right.top()<<endl;
    cout<<"size "<<left.size()<<" "<<right.size()<<endl;

    result.push_back(getMedian(left,right,x,y));
  }
  return result;
}

int main()
{
  priority_queue<int> left;
  priority_queue<int, vector<int>, greater<int>> right;
  int n, k;
  cin >> n >> k;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  vector<double> ans = sliding_median(arr,n,k);
  for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<endl;
  }
  return 0;
  // 1 3 -1 -3 5 3 6 7
}