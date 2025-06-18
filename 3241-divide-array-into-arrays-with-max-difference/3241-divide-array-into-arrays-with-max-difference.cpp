class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int n = nums.size();

        for (int i = 0; i < n; i += 3) {
            // Get the next 3 elements
            int a = nums[i];
            int b = nums[i + 1];
            int c = nums[i + 2];

            // Check if the max difference is <= k
            if (c - a > k) {
                return {};
            }

            result.push_back({a, b, c});
        }

        return result;
    }
};
