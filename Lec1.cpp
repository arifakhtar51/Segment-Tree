#include<bits/stdc++.h>
using namespace std;
vector<int>SegTree;
// time comple:(2*n) visiting each node 2 times up and down 
// space is simply 0(2*n+2)
void buildTree(vector<int>&arr,int i,int l,int r){
    if(l==r){
        SegTree[i]=arr[l];return ;
    }
    int mid=(l+r)/2;
    buildTree(arr,2*i+1,l,mid);
    buildTree(arr,2*i+2,mid+1,r);
    SegTree[i]=SegTree[2*i+1]+SegTree[2*i+2];
}

// Time complexity of  UpdateSegTree is just log(n)
// which is efficient you can't do with prefix sum 
void UpdateSegTree(int idx,int val,vector<int>&arr,int i,int l,int r){
    if(l==r){
        SegTree[i]=val;return ;
    }
    int mid=(l+r)/2;
    if(idx<=mid){
        UpdateSegTree(idx,val,arr,2*i+1,l,mid);
    }
    else{
        UpdateSegTree(idx,val,arr,2*i+2,mid+1,r);
    }
    
    SegTree[i]=SegTree[2*i+1]+SegTree[2*i+2];
}
// 0(2*log(n)) Time complexity of querySum
int querySum(int left,int right,vector<int>&arr,int i,int l,int r){
    // base case
    if(r<left || l>right){
        return 0;
    }
    if(l>=left && r<=right){
        return SegTree[i];
    }
    int mid=(l+r)/2;
    int ans=querySum(left,right,arr,2*i+1,l,mid)+querySum(left,right,arr,2*i+2,mid+1,r);
    return ans;

}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    SegTree.resize(2*n+2,0);
    buildTree(arr,0,0,n-1);
    // for(int i=0;i<2*n+2;i++){
    //     cout<<SegTree[i]<<" ";
    // }
    // cout<<endl;
    // UpdateSegTree(1,2,arr,0,0,3);
    // for(int i=0;i<2*n+2;i++){
    //     cout<<SegTree[i]<<" ";
    // }
    cout<<querySum(1,n-2,arr,0,0,n-1);
    return 0;
}