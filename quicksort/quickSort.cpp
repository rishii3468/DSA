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
void quickSort(int arr[], int si, int ei){
    if(si>=ei) return;
    int pi = partition(arr,si,ei);
    quickSort(arr,si,pi-1);
    quickSort(arr,pi+1,ei);
}

int main(){
    int arr[] = {5,1,8,2,7,6,3,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    quickSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}