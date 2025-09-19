int solve(vector<int>a,int n,int goal){
    int i=0;
    int j=0;
    int sum=0;
    int ans =0;
    while(i<n){
        if(a[i]==1)sum+=a[i];
        while(sum > goal && j<i){
            sum -= a[j];
            j++;
        }
        if(sum <= goal)ans += i-j+1;
        i++;
    }
    return ans;
}
int numSubarraysWithSum(vector<int>& a,int n, int goal) {
        return solve(a,n, goal) - solve(a,n, goal - 1);
    }