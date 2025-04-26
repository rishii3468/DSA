#include<iostream>
using namespace std;

class  Node{
public:
  int val;
  Node* next;
  Node* prev;
  Node(int val){
    this->next = NULL;
    this->val = val;
    this->prev = NULL;
  }
};

void display(Node* head){
  while(head){
    cout<<head->val<<" ";
    head =  head->next;
  }
}

void displayRec(Node* head){
  if(head==NULL) return;
  cout<<head->val<<" ";
  displayRec(head->next);
}

void displayRecRev(Node* head){
  if(head==NULL) return;
  displayRec(head->next);
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
  b->prev = a;
  c->prev = b;
  d->prev = c;
  e->prev = d;
  displayRec(a);
}