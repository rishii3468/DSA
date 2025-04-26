#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter number: ";
    cin>>n;

    int matrix[n][n];
    cout<<"Enter the matrix : ";
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin>>matrix[i][j];
        }
    }
    for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
    for(int i=0;i<n;i++){
        for(int j=0,k=n-1;j<=k;j++,k--){
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][k];
            matrix[i][k] = temp;
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
 
 
 
