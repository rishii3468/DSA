#include<iostream>
using namespace std;
int partition(int arr[], int si, int ei){
    int pivot = arr[(si+ei)/2];
    int count = 0;
    for(int i=si;i<=ei;i++){
        if(arr[i]==pivot) continue;
        if(arr[i]<=pivot) count++;
    }
    int pivotIndex = count + si;
    swap(arr[(si+ei)/2],arr[pivotIndex]);
    int i = si, j=ei;
    while(i<pivotIndex && j> pivotIndex){
        if(arr[i]<=pivot){
            i++;
        }
        else if(arr[j]>pivot){
            j--;
        }
        else if(arr[i] > pivot && arr[j]<=pivot){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }

    return pivotIndex;
}
int kthSmallest(int arr[], int si, int ei, int k){
    int pi = partition(arr,si,ei);
    if(pi+1==k) return arr[pi];
    else if(pi+1<k) return kthSmallest(arr,pi+1,ei,k);
    else return kthSmallest(arr,si,pi-1,k);
}

int main(){
    int arr[] = {5,1,8,2,7,6,3,4,-8};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int k = 2;
    cout<<kthSmallest(arr,0,n-1,n-k+1);
}