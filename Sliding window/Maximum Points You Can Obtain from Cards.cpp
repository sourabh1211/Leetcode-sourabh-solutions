int maxScore(vector<int>& a, int k){
    int n = a.size();
    int sum = 0;
    for(int i=0;i<k;i++)sum += a[i];
    int ans = sum;
    int i=k-1;
    int j=n-1;
    while(i>=0){
        sum -= a[i];
        sum += a[j];
        ans = max(sum,ans);
        i--;j--;
    }
    return ans;
}