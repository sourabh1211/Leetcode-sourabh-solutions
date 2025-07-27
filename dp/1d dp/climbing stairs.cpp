class Solution {
public:
    int solve(int i,vector<int>&dp,int n){
        if(i == n)return 1;
        if(i > n)return 0;
        if (dp[i] != -1) return dp[i];
        int left = solve(i+1,dp,n);
        int right = solve(i+2,dp,n);
        return dp[i] = left + right;
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return solve(0,dp,n);
    }
};