#include <iostream>
using namespace std;

class Stack { // user-defined data structure
    int arr[5];
    int idx = -1;
public:
    void push(int val) {
        if (idx < 4) { // To prevent overflow
            idx++;
            arr[idx] = val;
        } else {
            cout << "Stack Overflow" << endl;
        }
    }

    void pop() {
        if(idx==-1){
          cout<<"Stack Underflow"<<endl;
        }
        else{
          idx--;
        }
        
    }

    int top() {
        if (idx >= 0) {
            return arr[idx];
        } else {
            cout << "Stack is empty" << endl;
            return -1; // Return an invalid value for an empty stack
        }
    }

    int size() {
        return idx + 1;
    }

    void display() {
        if (idx == -1) {
            cout << "Stack is empty" << endl;
        } else {
            for (int i = 0; i <= idx; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
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
