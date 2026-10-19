class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Insert all elements into a hash set for O(1) lookups
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longestStreak = 0;

        for (int num : numSet) {
            // Check if 'num' is the start of a sequence
            if (numSet.find(num - 1) == numSet.end()) {
                int currentNum = num;
                int currentStreak = 1;

                // Count how long the consecutive sequence goes
                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum += 1;
                    currentStreak += 1;
                }

                // Update the maximum sequence found so far
                longestStreak = max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }
};
