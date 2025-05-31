class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> window; // BST for maintaining the last k elements

        for (int i = 0; i < nums.size(); ++i) {
            // Find the first number ≥ nums[i] - t
            auto it = window.lower_bound((long)nums[i] - t);

            // Check if such number is within t range
            if (it != window.end() && abs(*it - nums[i]) <= t)
                return true;

            window.insert(nums[i]);

            // Keep the window size ≤ k
            if (i >= k)
                window.erase(nums[i - k]);
        }

        return false;
    }
};
