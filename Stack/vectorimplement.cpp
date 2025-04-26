#include <iostream>
#include<vector>
using namespace std;

class Stack { // user-defined data structure
    vector<int> st;
public:
    void push(int val) {
        st.push_back(val);
    }

    void pop() {
        if(st.size()==0){
          cout<<"Stack Underflow"<<endl;
        }
        else{
          st.pop_back();
        }
        
    }

    int top() {
        if(st.size()==0){
          cout<<"Stack Underflow"<<endl;
          return -1;
        }
        
        return st[st.size()-1];
        
    }

    int size() {
        return st.size();
    }

    void display() {
      for(int i=0;i<st.size();i++){
        cout<<st[i]<<" ";
      }
    }
};

int main() {
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(3);
    st.display();
    return 0;
}
