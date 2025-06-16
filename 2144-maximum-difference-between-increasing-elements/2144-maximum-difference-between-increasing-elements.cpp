class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int min_val = nums[0];     // Store the minimum value so far
        int max_diff = -1;         // Default if no valid i < j and nums[i] < nums[j]

        for (int j = 1; j < nums.size(); ++j) {
            if (nums[j] > min_val) {
                max_diff = max(max_diff, nums[j] - min_val);  // Valid pair found
            } else {
                min_val = nums[j];  // Update min_val if current is smaller
            }
        }

        return max_diff;
    }
};
