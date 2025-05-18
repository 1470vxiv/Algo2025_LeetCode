#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int superEggDrop(int k, int n) {
        // dp[k][m] = max floors we can check with k eggs and m moves
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));
        int m = 0;  // m is the number of moves

        // Try increasing m until we can check >= n floors
        while (dp[k][m] < n) {
            m++;  // try one more move

            // Compute for each egg count 1 to k
            for (int eggs = 1; eggs <= k; eggs++) {
                dp[eggs][m] = dp[eggs - 1][m - 1] + dp[eggs][m - 1] + 1;
                // Meaning: if we have `eggs` and `m` moves,
                // we can cover that many floors
            }
        }

        return m;  // this is the minimum number of moves required
    }
};
