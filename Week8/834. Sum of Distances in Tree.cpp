class Solution {
    private:
        void postOrder(int node, int parent) { //derive all count and result[node]
            for (int child : edgeByNodes[node]) {
                if (child == parent) continue;
                postOrder(child, node);
                count[node] += count[child];
                result[node] += result[child] + count[child]; //只有最初的node的result會對
            }
        }

        void preOrder(int node, int parent) {
            for (int child : edgeByNodes[node]) {
                if (child == parent) continue;
                result[child] = result[node] - count[child] + (n - count[child]); //與子樹所有node (count[child])距離-1，與其他node (n - count[child])距離+1
                preOrder(child, node);
            }
        }

    public:
        unordered_map<int, vector<int>> edgeByNodes;
        vector<int> result; //sum of distances from node i to all others
        vector<int> count; // number of nodes in the subtree rooted at i
        int n;
    
        vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
            this->n = n;
            this->result = vector<int>(n, 0);
            this->count = vector<int>(n, 1);  // each node itself counts as 1
    
            for (const auto& edge : edges) {
                edgeByNodes[edge[0]].push_back(edge[1]);
                edgeByNodes[edge[1]].push_back(edge[0]);
            }
    
            postOrder(0, -1); //derive all count and result[0]
            preOrder(0, -1);
    
            return result;
        }
    };
