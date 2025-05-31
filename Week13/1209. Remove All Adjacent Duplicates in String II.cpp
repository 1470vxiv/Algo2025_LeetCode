class Solution {

public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> stk;

        for (char c : s) {
            if (!stk.empty() && stk.top().first == c) {
                stk.top().second++;
            } else {
                stk.push({c, 1});
            }

            if (stk.top().second == k) {
                stk.pop(); // remove k duplicates
            }
        }


        string result;
        while (!stk.empty()) {
            result.append(stk.top().second, stk.top().first);
            stk.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
