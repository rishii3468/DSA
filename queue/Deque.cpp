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

class Deque{ // User defined data structure
public:
  Node* head;
  Node* tail;
  int size;
  Deque(){
    head = tail = NULL;
    size = 0;
  }
  void push_back(int val){
    Node* temp = new Node(val);
    if(size == 0) head = tail = temp;
    else{
      tail->next = temp;
      temp->prev = tail;
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
  void push_front(int val){
    Node* temp = new Node(val);
    temp->next = head;
    head->prev = temp;
    head = temp;
    size++;
  }
 
  void displaySize(){
    cout<<this->size<<endl;
  }


  void pop_front(){
    if(size == 0){
      cout<<"List is empty";
      return;
    }
    head = head->next;
    size--;
  }

  void pop_back(){
    if(size == 0){
      cout<<"List is empty";
      return;
    }
    Node* temp = tail;
    temp = temp->prev;
    temp->next = NULL;
    
  }
  int front(){
    if(size==0) return -1;
    return head->val;
  }

  int back(){
    if(size==0) return -1;
    return tail->val;
  }
};

int main(){
   Deque q;
   q.push_back(12);
   q.push_back(13);
   q.push_front(14);
   q.push_front(15);
   q.display();
   q.pop_back();
   q.pop_front();
   q.push_back(12);
   q.push_back(12);
   q.display();
}