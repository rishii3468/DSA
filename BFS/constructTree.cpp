#include<iostream>
#include<queue>
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

int main(){
  int arr[] = {1,2,3,4,5,INT16_MIN,6,7,INT16_MIN,8,INT16_MIN,9,10,INT16_MIN,11,INT16_MIN,12,INT16_MIN,13};
  int n = sizeof(arr)/sizeof(arr[0]);
  Node* root = construct(arr,n);
  levelOrderQueue(root);
  return 0;
}