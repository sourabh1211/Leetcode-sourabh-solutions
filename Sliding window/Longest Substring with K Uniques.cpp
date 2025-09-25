    int longestKSubstr(string &s, int k) {
        int n = s.length();
        int i = 0;
        int j = 0;
        int ans = -1;
        unordered_map<char,int>mp;
        while(i < n){
            mp[s[i]]++;
            while(mp.size()>k){
                mp[s[j]]--;
                if(mp[s[j]]==0)mp.erase(s[j]);
                j++;
            }
            if(mp.size()==k)ans = max(ans,i-j+1);
            i++;
        }
        return ans;
        
    }