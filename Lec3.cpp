// question link : https://www.geeksforgeeks.org/problems/range-minimum-query/1

int *  SegTree;
void buildTree(int arr[],int i,int l,int r){
    if(l==r){
        SegTree[i]=arr[l];return ;
    }
    int mid=(l+r)/2;
    buildTree(arr,2*i+1,l,mid);
    buildTree(arr,2*i+2,mid+1,r);
    SegTree[i]=min(SegTree[2*i+1],SegTree[2*i+2]);
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
int querySum(int left,int right,int arr[],int i,int l,int r){
    // base case
    if(r<left || l>right){
        return INT_MAX;
    }
    if(l>=left && r<=right){
        return SegTree[i];
    }
    int mid=(l+r)/2;
    int ans=min(querySum(left,right,arr,2*i+1,l,mid),querySum(left,right,arr,2*i+2,mid+1,r));
    return ans;

}

int *constructST(int arr[],int n)
{
  //Your code here
  SegTree=new int[4*n];
  buildTree(arr,0,0,n-1);
  return   SegTree;
  
}


/* The functions returns the
 min element in the range
 from a and b */
int RMQ(int st[] , int n, int a, int b)
{
//Your code here
    return querySum(a,b,st,0,0,n-1);
}