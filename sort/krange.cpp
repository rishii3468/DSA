#include<iostream>
#include<climits>
using namespace std;
float max1(float a,float b){
    if(a>=b) return a;
    else return b;
}
float min1(float a,float b){
    if(a<=b) return a;
    else return b;
}
int main(){
    int arr[] = {5,3,10,3};
    int n=4;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    float kmin = (float)INT_MIN;
    float kmax = (float)INT_MAX;
    bool flag = true;
    for(int i=0;i<n-1;i++){
        if(arr[i]>=arr[i+1]){
            kmin = max1(kmin,(arr[i]+arr[i+1])/2.0);
        }
        else{
            kmax = min1(kmax,(arr[i]+arr[i+1])/2.0);
        }
        if(kmin>kmax){
            flag = false;
            break;
        }
    }
    int kmin1 = (int)kmin;
    if(kmin>kmin1) kmin1++;
    if(flag==false || kmin1>kmax){
        cout<<-1;
    }
    else{
        if(kmin1==(int)kmax) cout<<"k is "<<kmin1;
        else cout<<"Range of k is : ["<<kmin1<<","<<(int)kmax<<"]";
    }
}