#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;

class Node{ // This is a TreeNode
public:
  int val;
  Node* left;
  Node* right;
  Node(int val){
    this->val = val;
    this->left = NULL;
    this->right = NULL;
  }
};

Node* construct(int arr[],int n){
  queue<Node*> q;
  Node* root = new Node(arr[0]);
  q.push(root);
  int i = 1, j = 2;
  while(q.size()>0 && i<n){
    Node* temp = q.front();
    q.pop();
    Node* l;
    Node* r;
    if(arr[i]!=INT16_MIN) l = new Node(arr[i]);
    else l = NULL;
    if(j!=n && arr[j]!=INT16_MIN) r = new Node(arr[j]);
    else r = NULL;  
    temp->left = l;
    temp->right = r;
    if(l!=NULL) q.push(l);
    if(r!=NULL) q.push(r);
    i+=2;
    j+=2;

  }
  return root;
}

void levelOrderQueue(Node* root){
    queue<Node*> q;
    q.push(root);
    while(q.size()>0){
      Node* temp = q.front();
      q.pop();
      cout<<temp->val<<" ";
      if(temp->left) q.push(temp->left);
      if(temp->right) q.push(temp->right);
    }
    cout<<endl;
}

void topview(Node* root){
  unordered_map<int,int> m;
  queue< pair<Node*, int> >q;
  pair<Node*, int> r;
  r.first = root;
  r.second = 0;
  q.push(r);
  while(q.size()>0){
    Node* temp = (q.front()).first;
    int level = (q.front()).second;
    q.pop();
    if(m.find(level)==m.end()) m[level] = temp->val;
    if(temp->left){
      pair<Node*, int> s;
      s.first = temp->left;
      s.second = level-1;
      q.push(s);
    }
    if(temp->left){
      pair<Node*, int> s;
      s.first = temp->right;
      s.second = level+1;
      q.push(s);
    }
  }

  int minLevel = INT16_MAX;
  int maxLevel = INT16_MIN;
  for(auto x: m){
    int level = x.first;
    minLevel = min(minLevel,level);
    maxLevel = max(maxLevel,level);
  }
  for(int i=minLevel;i<=maxLevel;i++){
    cout<<m[i]<<" ";
  }
  cout<<endl;
}

int main(){
  int arr[] = {1,2,3,4,5,INT16_MIN,6,INT16_MIN,INT16_MIN,7,8};
  int n = sizeof(arr)/sizeof(arr[0]);
  Node* root = construct(arr,n);
  levelOrderQueue(root);
  cout<<endl;
  topview(root);
  return 0;
}