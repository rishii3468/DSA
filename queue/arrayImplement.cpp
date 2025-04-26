#include <iostream>
#include<vector>
using namespace std;

class Queue{
public:
  int f;
  int b;
  int s;
  vector<int> arr;
  Queue(int val){
    f = 0;
    b=0;
    s=0;
    vector<int> v(val);
    arr = v;
  }
  void push(int val){
    if(s==5){
      cout<<"Queue is full";
      return;
    }
    arr[b] = val;
    b++;
    s++;
  }
  void pop(){
    if(s==0){
      cout<<"Queue is empty";
      return;
    }
    f++;
    s--;
  }
  int front(){
    if(s==0){
      cout<<"Queue is empty";
      return -1;
    }
    return arr[f];
  }
  int back(){
    if(s==0){
      cout<<"Queue is empty";
      return -1;
    }
    return arr[b-1];
  }
  int size(){
    return s;
  }
  bool empty(){

  }
  void display(){
    for(int i=0;i<b-f;i++){
      cout<<arr[i]<<" ";
    }
    cout<<endl;
  }
};

int main()
{
  Queue q(5);
  q.push(10);
  q.push(20);
  q.push(30);
  q.display();
  q.push(40);
  q.push(50);
  q.push(50);
  q.push(50);
  q.display();
  q.pop();
  q.display();
}