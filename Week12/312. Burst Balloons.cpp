#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        
        // Add 1 at the beginning and end for easier calculations
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        // Create DP table
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        // Length of the subarray we are considering
        for (int len = 2; len <= n + 1; ++len) {
            for (int left = 0; left + len <= n + 1; ++left) {
                int right = left + len;
                for (int i = left + 1; i < right; ++i) {
                    dp[left][right] = max(dp[left][right],
                        nums[left] * nums[i] * nums[right] +
                        dp[left][i] + dp[i][right]);
                }
            }
        }

        return dp[0][n + 1];
    }
};
