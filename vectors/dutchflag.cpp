#include <iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> v1,v2;
    v1.push_back(2);
    v1.push_back(4);
    v1.push_back(6);
    v1.push_back(7);
    v1.push_back(9);
    v1.push_back(10);
    v2.push_back(1);
    v2.push_back(3);
    v2.push_back(5);
    v2.push_back(8);
    int n1 = v1.size(), n2 = v2.size();
    vector<int> v3[n1+n2];
    int i=0,j=0,k=0;
    while(k<n1+n2-1){
        if (v1[i]>v2[j]){
            v3[k] = v1[i];
            i++;
            k++;
        }
        else if (v1[i]<v2[j]){
            v3[k] = v2[j];
            j++;
            k++;
        }
        else{
            v3[k] = v1[i];
            i++;
            k++;
        }
    }
    for(int i=0;i<n1+n2;i++){
        cout<<v3[i]<<" ";
    }
}