class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];
        int f = 0, m = -1;
        for(int i = 0; i < nums.size(); i ++){
            if(f == 0){
                m = nums[i];
                f = 1;
            }
            else if(m == nums[i]) f ++;
            else f --;
        }
        return m;
    }
};