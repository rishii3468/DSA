#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int c = 41;
    int near = sqrt(c);
    int flag = false;
    while(near<c){
        int i = 1;
        int j = near;
        if( flag == true) break;
        if(near/2*near/2 >c){
            cout<<"not found";
            break;
        }
        while(i<=j){
            if(i*i+j*j == c){
                cout<<i<<" "<<j;
                flag = true;
                break;
            }
            else{
                i++;
                j--;
            }
            
        }
        near++;
    }
}