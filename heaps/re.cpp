#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
  int val;
  Node* left;
  Node* right;
  Node(int val){
    this->val = val;
  }
};

void inorder(Node* root, vector<int>& dec){
  if(root==NULL) return;
  inorder(root->right,dec);
  dec.push_back(root->val);    
  inorder(root->left,dec);

}

int main(){
  Node* a = new Node(10);
  Node* b = new Node(5);
  Node* c = new Node(16);
  Node* d = new Node(1);
  Node* e = new Node(8);
  Node* f = new Node(12);
  Node* g = new Node(20);
  a->left = b; 
  a->right = c;
  b->left = d;
   b->right = e;
  c->left = f;
   c->right = g;
  vector<int> dec;
  inorder(a,dec);
  for(int i=0;i<dec.size();i++){
    cout<<dec[i]<<" ";
  }

  return 0;
}