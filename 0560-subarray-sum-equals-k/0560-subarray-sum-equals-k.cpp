class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       unordered_map<long long, int> mp;
       long long sum = 0, count = 0, n = nums.size();
       mp[0] = 1;
       for(int i = 0; i < n; i ++){
        sum += nums[i];
        if(mp.find(sum - k) != mp.end()) count += mp[sum - k];
        mp[sum] ++;
       } 
       return count;
    }
};