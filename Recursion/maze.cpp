#include<iostream>
using namespace std;
int maze(int sc,int sr, int ec, int er){
    if(sc==ec && sr==er) return 1;
    if(sc>ec || sr>er) return 0;
    int rightCount = maze(sc+1,sr,ec,er);
    int downCount = maze(sc,sr+1,ec,er);
    return rightCount + downCount;
}
void printPath(int sc,int sr, int ec, int er, string s){
    if(sc>ec || sr>er) return;
    if(sc==ec && sr==er) cout<<s<<endl;
    printPath(sc+1,sr,ec,er,s+'R');
    printPath(sc,sr+1,ec,er,s+'D');
}
int maze(int m,int n){
    if(m==1 && n==1) return 1;
    if(m<1 || n<1) return 0;
    int rightCount = maze(m-1,n);
    int downCount = maze(m,n-1);
    return rightCount + downCount;
}
int main(){
    cout<<maze(3,3);
}