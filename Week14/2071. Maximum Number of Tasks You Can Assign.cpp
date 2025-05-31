#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    bool canAssign(vector<int>& tasks, vector<int>& workers, int pills, int pillStrength, int k) {
        multiset<int> ws(workers.end() - k, workers.end());  // Take k strongest workers
        for (int i = k - 1; i >= 0; i--) {  // Hardest k tasks
            auto it = ws.lower_bound(tasks[i]);  // Try assign without pill
            if (it != ws.end()) {
                ws.erase(it);
            } else {
                if (pills == 0) return false;
                auto it2 = ws.lower_bound(tasks[i] - pillStrength);
                if (it2 == ws.end()) return false;
                ws.erase(it2);
                pills--;
            }
        }
        return true;
    }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int pillStrength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int left = 0, right = min(tasks.size(), workers.size());
        int res = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canAssign(tasks, workers, pills, pillStrength, mid)) {
                res = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return res;
    }
};
