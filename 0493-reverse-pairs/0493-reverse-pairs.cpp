
class Solution {
public:
    int merge(vector<int>& nums, int p, int mid, int q) {
        int count = 0;
        int j = mid + 1;
        for (int i = p; i <= mid; i++) {
            while (j <= q && (long long)nums[i] > 2LL * nums[j]) {
                j++;
            }
            count += j - (mid + 1);
        }
        vector<int> temp;
        int i = p;
        j = mid + 1;

        while (i <= mid && j <= q) {
            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i++]);
            } else {
                temp.push_back(nums[j++]);
            }
        }

        while (i <= mid) temp.push_back(nums[i++]);
        while (j <= q) temp.push_back(nums[j++]);

        for (int k = p; k <= q; k++) {
            nums[k] = temp[k - p];
        }

        return count;
    }

    int merge_sort(vector<int>& nums, int p, int q) {
        if (p >= q) return 0;

        int mid = p + (q - p) / 2;

        int count = 0;
        count += merge_sort(nums, p, mid);
        count += merge_sort(nums, mid + 1, q);
        count += merge(nums, p, mid, q);

        return count;
    }

    int reversePairs(vector<int>& nums) {
        return merge_sort(nums, 0, (int)nums.size() - 1);
    }
};
