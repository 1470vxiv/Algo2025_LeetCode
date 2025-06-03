class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        if (n == 1) return 0;

        queue<tuple<int, int, int>> q; // (node, mask, steps)
        //mask: which nodes we have visited so far, operated in 2-bit, 000101 -> node 0, 2 visited
        vector<vector<bool>> visited(n, vector<bool>(1 << n, false)); 
        //1<<n == 2^n, 全false: 000000

        // Start from every node
        for (int i = 0; i < n; ++i) {
            q.push({i, 1 << i, 0});
            visited[i][1 << i] = true; //Only i visited
        }

        while (!q.empty()) { // BFS
            auto [node, mask, steps] = q.front();
            q.pop();

            for (int neighbor : graph[node]) {
                int nextMask = mask | (1 << neighbor); 
                // Update nextMask to include neighbor into visited set, 把neighbor node加進nextMask
                
                if (nextMask == (1 << n) - 1) { //(1 << n) - 1 為全true
                    return steps + 1; // All nodes visited
                }

                if (!visited[neighbor][nextMask]) { //造訪過的visited node組合不必再加進queue
                    visited[neighbor][nextMask] = true;
                    q.push({neighbor, nextMask, steps + 1});
                }
            }
        }

        return -1; // Should not reach here
    }
};
