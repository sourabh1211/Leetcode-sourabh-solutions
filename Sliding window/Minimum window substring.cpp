class Solution {
public:
    string minWindow(string s, string t) {
        int j = 0;
        int i = 0;
        int n = s.length();
        int m = t.length();
        int minLen = INT_MAX;
        int count = 0;
        int startIndex = 0;
        int hash[256] = {0};
        for (int k = 0; k < m; k++) {
            hash[t[k]]++;
        }
        while (i < n) {
            if (hash[s[i]] > 0) count++;
            hash[s[i]]--;

            while (count == m) {
                if (i - j + 1 < minLen) {
                    minLen = i - j + 1;
                    startIndex = j;
                }
                hash[s[j]]++;
                if (hash[s[j]] > 0) count--;
                j++;
            }
            i++;
        }

        return minLen == INT_MAX ? "" : s.substr(startIndex, minLen);
    }
};
