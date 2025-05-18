class Solution {
    public:
        vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
            
            int n = edges.size();
            vector<vector<int>> graph(n+1);
            vector<int> parentNum(n+1, 0);

            for (auto& edge : edges) {
                graph[edge[0]].push_back(edge[1]);
                parentNum[edge[1]]++;
            }

            vector<int> result;
            for(auto& edge : edges) {
                int count = 0;
                queue<int> q;

                parentNum[edge[1]]--;
                for (int i = 1; i < n+1; i++) {
                    if (parentNum[i] == 0) {
                        q.push(i);
                        count++;
                    }   
                }

                if(q.size() != 1 || parentNum[edge[1]] < 0) {
                    parentNum[edge[1]]++;
                    continue; //不符合有根樹定義
                }

                while (!q.empty()) {
                    int now = q.front();
                    q.pop();

                    for (int neighbor : graph[now]) {
                        if(now == edge[0]&& neighbor == edge[1]) continue;
                        q.push(neighbor);
                        count++;
                    }
                }

                if (count == n) result = edge;
                parentNum[edge[1]]++;
            }
            return result;
        }
    };
