class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int i=0;
        int j=0;
        int ans = 0;
        int count = 0;
        map<char,int>mp;
        while(i < n){
            mp[s[i]]++;
            count = max(count,mp[s[i]]);
            while((i-j+1)-count > k){
                mp[s[j]]--;
                j++;
            }
            ans = max(ans , i-j+1);
            i++;
        }
        return ans;
    }
};