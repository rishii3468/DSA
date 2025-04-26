#include<iostream>
#include<vector>
using namespace std;

class MinHeap{
public:
  int* arr;
  int idx;
  MinHeap(int n){
    idx = 1;
    arr = new int[n];
  }
  int top(){
    return arr[1];
  }
  void push(int x){
    arr[idx] = x;
    int i = idx;
    while(i!=1){
      int parent = i/2;
      if(arr[i]<arr[parent]){
        swap(arr[i],arr[parent]);
      }
      else break;
      i /= 2;
    }
    idx++;          
  }
  int size(){
    return idx-1;
  }
  void pop(){
    if(idx == 1){
      printf("Empty hash map");
      return;
    }
    idx--;
    int i = 1;
    arr[1] = arr[idx];
    while(true){
      int left = 2*i, right = left+1;
      if(left>idx-1 ) break;
      if(right>idx-1){
        if(arr[left]< arr[i]){
          swap(arr[left],arr[i]);
        }
        break;
      }
      if(arr[left]<arr[right]){
        if(arr[left]<arr[i]){
          swap(arr[left],arr[i]);
          i = left;
        }
        else break;
      }
      else{
        if(arr[right]<arr[i]){
          swap(arr[right],arr[i]);
          i = right;
        }
        else break;
      }
    }
  }
  void display(){
    for(int i= 1; i<idx;i++){
      cout<<arr[i]<<" ";
    }
    cout<<endl;
  }
};


int main(){
  MinHeap pq(10);
  pq.push(10);
  pq.push(20);
  pq.push(11);
  pq.push(19);
  cout<<pq.top()<<endl;
  pq.display();
  pq.pop();
  pq.display();
}