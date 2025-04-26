#include<iostream>
using namespace std;

class Node{
public:
  int val;
  Node* next;
  Node(int val){
    this->val = val;
    this->next = NULL;
  }
};

void display(Node* head){
  while(head!=NULL){
    cout<<head->val<<" ";
    head = head->next;
  }
  cout<<endl;
}

int size(Node* head){
  int n = 0;
  Node* temp = head;
  while(temp!=NULL){
    n++;
    temp = temp->next;
  }
  return n;
}

void recursiveDisplay(Node* head){ 
  cout<<head->val<<" ";
  if(head->next == NULL) return;
  recursiveDisplay(head->next);
}

void revDisplay(Node* head){
  if(head == NULL) return;
  revDisplay(head->next);
  cout<<head->val<<" ";
}

int main(){
  Node* a = new Node(10);
  Node* b = new Node(20);
  Node* c = new Node(30);
  Node* d = new Node(40);
  Node* e = new Node(50);
  a->next = b;
  b->next = c;
  c->next = d;
  d->next = e;
  Node* temp = a;
  //display with temp node
  revDisplay(a);
}