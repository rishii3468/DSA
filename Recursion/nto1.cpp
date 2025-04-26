#include<iostream>
using namespace std;
void printn(int n){
    
    if (n==0) return;
    printn(n-1);
    cout<<n<<endl;
}
int main(){
    int n;
    cin>>n;
    printn(n);
}