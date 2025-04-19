#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
    public:
        int coinChange(vector<int>& coins, int amount) {
            if (amount == 0) return 0;
    
            vector<set<int>> tree(1);
            tree[0] = {0}; //tree記錄每一層包含的value, 不斷spand
            int stepNum = 0; //紀錄tree的層數
    
            set<int> visited; //記錄哪個value已經出現過
            visited.insert(0); 
    
            while (true) {
                set<int> currentNodes; //tree的最新一層包含的value
    
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
