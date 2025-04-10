#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
    public:
        int coinChange(vector<int>& coins, int amount) {
            if (amount == 0) return 0;
    
            vector<set<int>> tree(1);
            tree[0] = {0};
            int stepNum = 0;
    
            set<int> visited;
            visited.insert(0);
    
            while (true) {
                set<int> currentNodes;
    
                for (int coin : coins) {
                    for (const auto& val : tree[stepNum]) {
                        int newVal = val + coin;
                        if (newVal == amount) return stepNum + 1;
    
                        if (newVal > amount || visited.count(newVal)) continue;
    
                        currentNodes.insert(newVal);
                        visited.insert(newVal);
                    }
                }
    
                if (currentNodes.empty()) return -1;
    
                tree.push_back(currentNodes);
                stepNum++;
            }
        }
    };

    
/*
int main() {
    vector<int> coins = {1};
    int amount = 10000;
    Solution sol;
    int result = sol.coinChange(coins, amount);
    cout<<result<<endl;
}*/