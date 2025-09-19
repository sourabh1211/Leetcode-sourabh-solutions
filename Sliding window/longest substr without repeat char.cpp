int solve(string s){
    int ans = 0;
    int n = s.length();
    unordered_map<char,int>mp;
    int i=0;
    int j=0;
    while(i<n){
        mp[s[i]]++;
        while(mp[s[i]] > 1){
            mp[s[j]]--;
            j++;
        }
        ans = max(ans,i-j+1);
        i++;
    }
    return ans;
}