// question link : https://www.geeksforgeeks.org/problems/sum-of-query-ii5310/1
class Solution{
    public:
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
        vector<int> querySum(int n, int arr[], int q, int queries[])
        {
            // code here
            SegTree.resize(4*n,0);
            vector<int>a(n,0),ans(q,0);
            for(int i=0;i<n;i++){
                a[i]=arr[i];
            }
            buildTree(a,0,0,n-1);
            int j=0;
            for(int i=0;i<q*2;i+=2){
                int start=queries[i]-1;
                int end=queries[i+1]-1;
                ans[j++]=querySum(start,end,a,0,0,n-1);
            
            }        
            return ans;
        }
    };