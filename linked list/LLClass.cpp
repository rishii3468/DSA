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

class LinkedList{ // User defined data structure
public:
  Node* head;
  Node* tail;
  int size;
  LinkedList(){
    head = tail = NULL;
    size = 0;
  }
  void insertAtEnd(int val){
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
  void insertAtHead(int val){
    Node* temp = new Node(val);
    temp->next = head;
    head = temp;
    size++;
  }
  void insertAt(int idx, int val){
    if(idx<0 || idx>size) cout<<"Invalid input";
    else if(idx == 0) insertAtHead(val);
    else if(idx == size) insertAtEnd(val);
    else{   
      Node* temp = head;
      Node* t = new Node(val);
      //int count = 0;
      // while(true){
      //   if(count == idx-1){
      //     Node* t = new Node(val);
      //     t->next = temp->next;
      //     temp->next = t;
      //     break;
      //   }
      //   temp = temp->next;
      //   count++;
      // }
      for(int i=1;i<=idx-1;i++){
        temp = temp->next;
      }
      t->next = temp->next;
      temp->next = t;
      size++;
    }
  }
  void displaySize(){
    cout<<this->size<<endl;
  }
  int getAtIdx(int idx){
    if(idx<0 || idx>size){
      cout<<"Invalid input"<<endl;
      return -1;
    } 
    Node *temp = head;
    for(int i=0;i<idx;i++){
      temp = temp->next;
    }
    return temp->val;
  }

  void deleteAtHead(){
    if(size == 0){
      cout<<"List is empty";
      return;
    }
    head = head->next;
    size--;
  }

  void deleteAtTail(){
    if(size == 0){
      cout<<"List is empty";
      return;
    }
    Node* temp = head;
    for(int i=1;i<size-1;i++){
      temp = temp->next;
    }
    temp->next = NULL;
    tail = temp;
    size--;
  }

  void deleteAtIdx(int idx){
    if(idx<0 || idx>size){
      cout<<"Invalid index";
      return;
    }
    else if(idx == 0) return deleteAtHead();
    else if(idx == size-1) return deleteAtTail();
    else{
      Node* temp = head;
      for(int i=1;i<idx;i++){
        temp = temp->next;
      }
      temp->next = temp->next->next;
      size--;
    }
  }
};
int main(){
  LinkedList ll;
  ll.insertAtEnd(10);
  ll.display();
  ll.insertAtEnd(20); //{10,20}
  ll.display();
  ll.insertAtEnd(40);
  ll.display();
  ll.insertAtHead(60);
  ll.display();

  ll.insertAt(2,40);
  
  ll.display();

  ll.insertAt(1,90);
  
  ll.display();


  ll.insertAt(0,10);
  
  ll.display();

 
  ll.deleteAtHead();
  ll.display();
  ll.deleteAtTail();
  ll.display();
  ll.deleteAtIdx(3);
  ll.display();
}