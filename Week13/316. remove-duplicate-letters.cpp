class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> stk;

        vector<int> last(26, 0);
            for (int i = 0; i < s.size(); ++i) {
                last[s[i] - 'a'] = i; // record the last index of each character
            }

        vector<bool> inStack(26, false);

        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (inStack[c - 'a']) continue;

            while (!stk.empty() && c < stk.top() && i < last[stk.top() - 'a']) {
                inStack[stk.top() - 'a'] = false;
                stk.pop();
            }

            stk.push(c);
            inStack[c - 'a'] = true;
        }

        string result;
        while (!stk.empty()) {
            result = result + stk.top();
            stk.pop();
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
