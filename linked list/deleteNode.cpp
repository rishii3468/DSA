#include<iostream>
using namespace std;

class Node{//data type
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

Node* deletenode(Node* head, int target){
  if(head->val==target){
    head = head->next;
    return head;
  }
  Node* temp = head;
  while(temp->next->val!=target){
    temp = temp->next;
  }
  temp->next = temp->next->next;
  return head;
}

int main(){
  Node* a = new Node(10);
  Node* b = new Node(20);
  Node* c = new Node(30);
  Node* d = new Node(40);
  a->next = b;
  b->next = c;
  c->next = d;
  Node* head = a;
  display(head);
  head = deletenode(head,30);
  display(head);
}