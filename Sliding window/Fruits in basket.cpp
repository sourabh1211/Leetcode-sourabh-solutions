int solve(vector<int>a,int n){
    int i=0;
    int j=0;
    map<int,int>mp;
    while(i<n){
        mp[a[i]]++;
        while(mp.size()>2){
            mp[a[j]]--;
            if(mp[a[j]]==0)mp.erase(a[j]);
            j++;
        }
        ans = max(ans,i-j+1);
        i++;
    }
    return ans;
}