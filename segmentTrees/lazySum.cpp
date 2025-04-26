#include<iostream>
#include<vector>
using namespace std;
vector<int> st;
vector<int> lazy;

void buildTree(int arr[], int i,int lo,int hi){
	if(lo == hi){
		st[i] = arr[lo];
		return;
	 }
	int mid = lo + (hi-lo)/2;
	buildTree(arr,2*i+1,lo,mid);
	buildTree(arr,2*i+2,mid+1,hi);
	st[i] = st[2*i+1]+st[2*i+2];
	
}

int getSum(int i, int lo, int hi, int l, int r){
    //check for pending lazy updates
    if(lazy[i]!=0){
        int rangeSize = hi-lo+1;
        st[i] += rangeSize*lazy[i];
        if(lo!=hi){// send lazy to left and right child
            lazy[2*i+1] += lazy[i];
            lazy[2*i+2] += lazy[i];
        }
        lazy[i] = 0;
    }
	if(l>hi || r<lo) return 0;
	if(l<=lo && r>=hi) return st[i];
	int mid = lo + (hi-lo)/2;
	int leftMax = getSum(2*i + 1,lo,mid,l,r);
	int rightMax = getSum(2*i + 2,mid+1,hi,l,r);
	return leftMax + rightMax;
}

void updateRange(int i, int lo, int hi, int l, int r, int val){
    if(lazy[i]!=0){
        int rangeSize = hi - lo + 1;
        st[i] += rangeSize*lazy[i];
        if(lo!=hi){// send lazy to left and right child
            lazy[2*i+1] += lazy[i];
            lazy[2*i+2] += lazy[i];
        }
        lazy[i] = 0;
    }  
    if(l>hi || r<lo) return;
    if(lo>=l && hi<=r){
        int rangeSize = hi-lo+1;
        st[i] += rangeSize*val;
        if(lo!=hi){// send lazy to left and right child
            lazy[2*i+1] += val;
            lazy[2*i+2] += val;
        }
        return ;
    }
    int mid = lo + (hi-lo)/2;
    updateRange(2*i+1,lo,mid,l,r,10);
    updateRange(2*i+2,mid+1,hi,l,r,10);
    st[i] = st[2*i+1]+st[2*i+2];
}

int main(){
    int arr[] = {1,4,2,8,6,4,9,3};
    int n = sizeof(arr)/4;
    st.resize(4*n);
    lazy.resize(4*n,0);
    buildTree(arr,0,0,n-1);
 
    cout<<getSum(0,0,n-1,1,3)<<endl;
    updateRange(0,0,n-1,2,3,10);
    cout<<getSum(0,0,n-1,1,3)<<endl;
}