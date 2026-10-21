class Solution {
public:
    bool isvalid(vector<int> &nums, int k, int maxi){
        int stu = 1, pages = 0;
        for(int i = 0; i < nums.size(); i ++){
            if(nums[i] > maxi) return false;
            if(pages + nums[i] <= maxi){
                pages += nums[i];
            }
            else{
                pages = nums[i];
                stu ++;
            }
        }
        return stu <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int sum = 0, ans = -1;
        int n = nums.size();
        for(int i = 0; i < n; i ++){
            sum += nums[i];
        }
        int low = *max_element(nums.begin(), nums.end()), high = sum;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(isvalid(nums, k, mid)){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};