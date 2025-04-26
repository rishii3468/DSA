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
int level(Node* root){
  if(root==NULL) return 0;
  return 1 + max(level(root->right),level(root->left));
}
void display(Node* root){
  if(root == NULL) return;
  cout<<root->val<<" ";
  display(root->left);
  display(root->right);
}

void nth(Node* root,int target,int height){
  if(root==NULL) return;
  if(height==target){
    cout<<root->val<<" ";
    return;
  }
  
  nth(root->left,target,height+1);
  nth(root->right,target,height+1);
}

void levelTraversal(Node* root){
  int n = level(root);
  for(int i=1;i<=n;i++){
    nth(root,i,1);
    cout<<endl;
  }
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
  cout<<endl;
  
  //level order traversal
  levelTraversal(a);
  levelOrderQueue(a);
}