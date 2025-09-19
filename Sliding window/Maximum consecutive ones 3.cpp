int solve(vector<int>a,int n){
    int i=0;
    int j=0;
    int count = 0;
    int ans = 0;
    while(i<n){
        if(a[i]==0)count++;
        while(count > k){
            if(a[j]==0)count--;
            j++;
        }
        ans=max(ans,i-j+1);
        i++;
    }
    return ans;
}