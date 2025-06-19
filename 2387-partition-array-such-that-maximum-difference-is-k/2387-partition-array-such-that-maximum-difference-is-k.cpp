class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()); // Step 1: Sort the array
        int count = 0;                  // Step 2: Initialize group counter
        int i = 0;
        int n = nums.size();
        
        while (i < n) {
            int start = nums[i];       // Start of new group
            count++;                   // New group formed
            
            // Step 3: Keep adding elements to current group if within range
            while (i < n && nums[i] - start <= k) {
                i++;
            }
        }
        
        return count; // Return total number of groups
    }
};
