int numberOfSubstrings(string s){
    int n = s.length();
    int ans =0;
    int i=0;
    int j=0;
    map<char,int>mp;
    while(i<n){
        mp[s[i]]++;
        while(mp.size()==3){
            ans += n-i;
            mp[s[j]]--;
            if(mp[s[j]]==0)mp.remove(s[j]);
            j++;
        }
        i++;
    }
    return ans;
}