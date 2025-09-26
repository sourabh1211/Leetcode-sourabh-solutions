int solve(vector<int>nums,int k){
    int n = nums.size();
    int i=0;
    int j=0;
    map<int,int>mp;
    int ans = 0;
    while(i<n){
        mp[nums[i]]++;
        while(mp.size()>k){
            mp[nums[j]]--;
            if(mp[nums[j]]==0)mp.erase(nums[j]);
            j++;
        }
        ans += i-j+1;
        i++;
    }
    return ans;
}
int goodarray(vector<int>nums,int k){
    return solve(nums,k)-solve(nums,k-1);
}
