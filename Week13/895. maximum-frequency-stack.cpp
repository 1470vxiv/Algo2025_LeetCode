#include <unordered_map>
#include <stack>
#include <vector>

class FreqStack {
private:
    std::unordered_map<int, int> freq; // element -> frequency
    std::unordered_map<int, std::stack<int>> group; // frequency -> elements stack
    int maxFreq = 0;

public:
    FreqStack() {}

    void push(int val) {
        int f = ++freq[val];  // update frequency
        if (f > maxFreq) maxFreq = f;
        group[f].push(val);   // push to the corresponding frequency stack
    }

    int pop() {
        int val = group[maxFreq].top();
        group[maxFreq].pop();
        freq[val]--;
        if (group[maxFreq].empty()) {
            maxFreq--;
        }
        return val;
    }
};
