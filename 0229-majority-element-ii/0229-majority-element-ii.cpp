class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int f1 = 0, f2 = 0, m1 = -1, m2 = -1;
        for(auto it : nums){
            if(m1 == it){
                f1 ++;
            }
            else if(m2 == it){
                f2 ++;
            }
            else if(f1 == 0){
                m1 = it;
                f1 = 1;
            }
            else if(f2 == 0){
                m2 = it;
                f2 = 1;
            }
            else{
                f1 --;
                f2 --;
            }
        }
        f1 = 0, f2 = 0;
        for(auto it : nums){
            if(it == m1) f1 ++;
            else if(it == m2) f2 ++;
        }
        if(f1 > nums.size() / 3) ans.push_back(m1);
        if(f2 > nums.size() / 3) ans.push_back(m2);
        return ans;
    }
};