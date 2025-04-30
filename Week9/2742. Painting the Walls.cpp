class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<int> dp(n + 1, INT_MAX / 2); // dp[i]: min total cost (time) to paint i walls
        dp[0] = 0; // no walls painted → 0 time

        for (int i = 0; i < n; ++i) { // for each wall
            vector<int> new_dp = dp; // create a new_dp for the current round
            for (int j = 0; j <= n; ++j) { // try all possible number of walls already painted
                int next = min(n, j + time[i] + 1); 
                // after painting wall i yourself, you can hire (time[i]) people for free
                // so total painted walls = current walls (j) + time[i] + 1 (yourself)
                new_dp[next] = min(new_dp[next], dp[j] + cost[i]);
                // choose the better (smaller cost) between:
                //   - existing new_dp[next]
                //   - new cost (current dp[j] + cost[i] for painting wall i yourself)
            }
            dp = new_dp; // update dp for the next wall
        }
        return dp[n]; // answer is minimum cost to paint all n walls
    }
};
