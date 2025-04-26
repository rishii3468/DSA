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
void display(Node* root){
  if(root == NULL) return;
  cout<<root->val<<" ";
  display(root->left);
  display(root->right);
}

int main(){
  Node* a = new Node(2);
  Node* b = new Node(4);
  Node* c = new Node(10);
  Node* d = new Node(6);
  Node* e = new Node(5);
  Node* g = new Node(11);
  a->left = b;
  a->right = c;
  b->left = d;
  b->right = e;
  c->right = g;
  display(a);
}