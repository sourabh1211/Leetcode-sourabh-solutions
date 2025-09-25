int solve(vector<int>& nums,int k){
    int n = nums.size();
    int i=0;
    int j=0;
    int sum=0;
    int ans = 0;
    while(i<n){
        sum += nums[i] % 2;
        while(j<i && sum > k){
            sum -= nums[j] % 2;
            j++;
        }
        if(sum <= k){ans+=i-j+1;}
        i++;
    }
    return ans;
}
int numberOfSubarrays(vector<int>& nums, int k){
    int n = nums.size();
    return solve(nums,k)-solve(nums,k-1);
}