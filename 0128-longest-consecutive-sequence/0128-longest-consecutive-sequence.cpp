class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> s(nums.begin(), nums.end());
        for(auto it : s){
            if(it == INT_MIN || s.find(it - 1) == s.end()){
                int count = 1;
                int curr = it;
                while(curr != INT_MAX && s.find(curr + 1) != s.end()){
                    count ++;
                    curr ++;
                }
                ans = max(ans, count);
            }
        }
        return ans;
    }
};