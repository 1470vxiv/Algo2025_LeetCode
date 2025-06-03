class Solution {
    public:
        vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
            
            int n = edges.size();
            vector<vector<int>> graph(n+1); //紀錄有向圖
            vector<int> parentNum(n+1, 0); //紀錄每個點的parent數量

            for (auto& edge : edges) {
                graph[edge[0]].push_back(edge[1]);
                parentNum[edge[1]]++;
            }

            vector<int> result;
            for(auto& edge : edges) { //嘗試拔掉一個edge
                int count = 0; //for examine tree traversal
                queue<int> q;

                parentNum[edge[1]]--;
                for (int i = 1; i < n+1; i++) {
                    if (parentNum[i] == 0) { //找可能的根結點
                        q.push(i);
                        count++;
                    }   
                }

                if(q.size() != 1 || parentNum[edge[1]] < 0) {
                    parentNum[edge[1]]++;
                    continue; //不符合有根樹定義，前往下一個edge
                }

                //此時恰有一根結點，tree traversal
                while (!q.empty()) {
                    int now = q.front();
                    q.pop();

                    for (int neighbor : graph[now]) {
                        if(now == edge[0]&& neighbor == edge[1]) continue; //樹到末端
                        q.push(neighbor);
                        count++;
                    }
                }

                //成功遍歷所有節點
                if (count == n) result = edge;
                parentNum[edge[1]]++;
            }
            return result;
        }
    };
