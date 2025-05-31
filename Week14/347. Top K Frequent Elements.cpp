class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        for (int num : nums) {
            freqMap[num]++;
        }

        vector<pair<int, int>> numToFreq;
        for (const auto& entry : freqMap) {
            numToFreq.emplace_back(entry.first, entry.second);
        }

        sort(numToFreq.begin(), numToFreq.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second; // Descending
        });

        vector<int> result;
        for(int i=0; i<k; i++){
            result.push_back(numToFreq[i].first);
        }

        return result;
    }
};
