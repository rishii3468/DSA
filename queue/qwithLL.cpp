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

class Queue{ // User defined data structure
public:
  Node* head;
  Node* tail;
  int size;
  Queue(){
    head = tail = NULL;
    size = 0;
  }
  void push(int val){
    Node* temp = new Node(val);
    if(size == 0) head = tail = temp;
    else{
      tail->next = temp;
      tail = temp;
    }
    size++;
  }
  void display(){
    Node* temp = head;
    while(temp != NULL){
      cout<<temp->val<<" ";
      temp = temp->next;
    }
    cout<<endl;
  }

  void displaySize(){
    cout<<this->size<<endl;
  }

  int front(){
    if(size==0) return -1;
    return head->val;
  }

  int back(){
    if(size==0) return -1;
    return tail->val;
  }

  void pop(){
    if(size == 0){
      cout<<"List is empty";
      return;
    }
    Node* temp = head;
    head = head->next;
    delete(temp);
    size--;
  }

};
int main(){
  Queue q;
  q.push(12);
  q.push(22);
  q.push(42);
  q.push(52);
  q.push(72);
  q.display();
  q.pop();
  q.display();
}