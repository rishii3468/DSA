#include<iostream>
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
int sumOfTree(Node* root){
  if(root == NULL) return 0;
  return root->val + sumOfTree(root->left) + sumOfTree(root->right);
}
int sizeOfTree(Node* root){
  if(root==NULL) return 0;
  return 1 + sizeOfTree(root->left) + sizeOfTree(root->right);
} 

int max1(Node* root){
  if(root==NULL) return INT16_MIN;
  return max(root->val,max(max1(root->left),max1(root->right)));
}

int mul(Node* root){
  if(root==NULL) return 1;
  return root->val * mul(root->left) * mul(root->right);
}

int level(Node* root){
  if(root==NULL) return 0;
  return max(1+level(root->right), 1+ level(root->left));
}

int height(Node* root){
  if(root==NULL) return -1;
  return max(1+height(root->right), 1+ height(root->left));
}

int main(){
  Node* a = new Node(1);
  Node* b = new Node(1);
  Node* c = new Node(10);
  Node* d = new Node(2);
  Node* e = new Node(1);
  Node* f = new Node(1);
  a->left = b;
  a->right = c;
  b->left = d;
  b->right = e;
  e->left = f;

  cout<<sumOfTree(a)<<endl;
  cout<<sizeOfTree(a)<<endl;
  cout<<max1(a)<<endl;
  cout<<mul(a)<<endl;
  cout<<level(a)<<endl;
  cout<<height(a);
}