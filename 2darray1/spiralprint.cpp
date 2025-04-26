#include<iostream>
using namespace std;
int main(){
    int n,m;
    cout<<"Enter number of rows of matrix: ";
    cin>>m;
    cout<<"Enter number of columns of  matrix: ";
    cin>>n;

    int matrix[m][n];
    cout<<"Enter the matrix :"<<endl;
    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            cin>>matrix[i][j];
        }
    }
    
    int maxr = m-1,maxc = n-1,minr = 0,minc = 0;
    while((maxr-minr)>=0 && (maxc-minc)>=0){
        //right
        for(int i=minc;i<=maxc;i++){
            cout<<matrix[minr][i]<<" ";
        }
        minr++;
        if(minr>maxr) break;
        //down
        for(int i=minr;i<=maxr;i++){
            cout<<matrix[i][maxc]<<" ";
        }
        maxc--;
        if(minc>maxc) break;
        //left
        for(int i=maxc;i>=minc;i--){
            cout<<matrix[maxr][i]<<" ";
        }
        maxr--;
        if(minr>maxr) break;
        //up
        for(int i=maxr;i>=minr;i--){
            cout<<matrix[i][minc]<<" ";
        }
        minc++;

    }
    
}