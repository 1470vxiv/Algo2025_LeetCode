class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int numsSum = 0;
        for(int i : nums) numsSum += i;
        if(numsSum % 2 == 1) return false;
        else {
            int subSum = numsSum/2;

            vector<bool> dp(subSum + 1, false);
            dp[0] = true;  // Sum 0 is always achievable (empty subset)

            for (int num : nums) {
                for (int i = subSum; i >= num; --i) {
                dp[i] =  dp[i] || dp[i - num];
                }
            }

            return dp[subSum];
        }
        
    }
};
