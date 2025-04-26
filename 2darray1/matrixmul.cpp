#include<iostream>
using namespace std;
int main(){
    int n1,m1,n2,m2;
    cout<<"Enter number of rows of 1st matrix: ";
    cin>>m1;
    cout<<"Enter number of columns of 1st matrix: ";
    cin>>n1;
    cout<<"Enter number of rows of 2nd matrix: ";
    cin>>m2;
    cout<<"Enter number of columns of 2nd matrix: ";
    cin>>n2;
    int matrix1[m1][n1], matrix2[n2][m2];
    cout<<"Enter the matrix 1 : ";
    for(int i = 0;i<m1;i++){
        for(int j = 0;j<n1;j++){
            cin>>matrix1[i][j];
        }
    }
    cout<<"Enter the matrix 2 : ";
    for(int i = 0;i<m2;i++){
        for(int j = 0;j<n2;j++){
            cin>>matrix2[i][j];
        }
    }
    if(n1!=m2){
        cout<<"Invalid input";
        exit(0);
    }
    else{
        int res[m1][n2];
        for(int i=0;i<m1;i++){
            for(int j=0;j<n2;j++){
                res[i][j] = 0;
                for(int k=0;k<m2;k++){
                    res[i][j] += matrix1[i][k]*matrix2[k][j];
                }
            }
        }
        for(int i = 0;i<m1;i++){
            for(int j = 0;j<n2;j++){
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }

    }
    
}
 
 