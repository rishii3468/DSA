#include<iostream>
using namespace std;
int main(){
    int n,m;
    cout<<"Enter number of rows of matrix: ";
    cin>>m;
    cout<<"Enter number of columns of  matrix: ";
    cin>>n;

    int matrix[m][n];
    cout<<"Enter the matrix : ";
    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            cin>>matrix[i][j];
        }
    }
    
    for(int i = 0;i<n;i++){
        if(i%2!=0){
            for(int j = m-1;j>=0;j--){
                cout<<matrix[j][i]<<" ";
            }
        } 
        else{
            for(int j = 0;j<m;j++){
                cout<<matrix[j][i]<<" ";
            }
        }
        
        cout<<endl;
    }
    
}