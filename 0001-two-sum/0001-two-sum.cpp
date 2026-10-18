class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i ++){
            int first = nums[i];
            int second = target - first;
            if(mp.find(second) == mp.end()) mp.insert({first, i});
            else return {mp[second], i};
        }
        return {-1, -1};
    }
};
