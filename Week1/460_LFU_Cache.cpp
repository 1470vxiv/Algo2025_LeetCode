#include <unordered_map>
#include <list>
#include <iostream>

using namespace std;

class LFUCache {
private:
    int capacity, minFreq; //紀錄當前min. freq.
    unordered_map<int, pair<int, int>> keyToVal; // key -> {value, frequency}
    unordered_map<int, list<int>> freqToKeys; // frequency -> list of keys (order of insertion matters), most recently used排最後面
    unordered_map<int, list<int>::iterator> keyToIter; // key -> iterator in freqToKeys list

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->minFreq = 0;
    }

    int get(int key) {
        if (keyToVal.find(key) == keyToVal.end()) return -1; // Key not found

        updateFrequency(key);
        return keyToVal[key].first; // Return the value
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        if (keyToVal.find(key) != keyToVal.end()) {
            // Key exists, update value and frequency
            keyToVal[key].first = value;
            updateFrequency(key);
        } else {
            // If at full capacity, remove LFU item
            if (keyToVal.size() >= capacity) {
                evictLFU();
            }
            // Insert new key with frequency 1
            keyToVal[key] = {value, 1};
            freqToKeys[1].push_back(key);
            keyToIter[key] = --freqToKeys[1].end();
            minFreq = 1; // Reset minFreq
        }
    }

private:
    void updateFrequency(int key) {
        int freq = keyToVal[key].second; // Get current frequency
        keyToVal[key].second++; // Increase frequency

        // Remove key from current frequency list
        freqToKeys[freq].erase(keyToIter[key]);
        if (freqToKeys[freq].empty()) {
            freqToKeys.erase(freq);
            if (minFreq == freq) minFreq++; // Update minFreq if needed
        }

        // Add key to the next frequency list
        freqToKeys[freq + 1].push_back(key);
        keyToIter[key] = --freqToKeys[freq + 1].end();
    }

    void evictLFU() {
        // Get the LFU key (first inserted one in minFreq list)
        int keyToRemove = freqToKeys[minFreq].front();

        // Remove it from all mappings
        freqToKeys[minFreq].pop_front();
        if (freqToKeys[minFreq].empty()) {
            freqToKeys.erase(minFreq); // Clean up
        }
        keyToVal.erase(keyToRemove);
        keyToIter.erase(keyToRemove);
    }
};

/*
int main()
{
    // cnt(x) = the use counter for key x
// cache=[] will show the last used order for tiebreakers (leftmost element is  most recent)
LFUCache* lfu = new LFUCache(2);
lfu->put(1, 1);   // cache=[1,_], cnt(1)=1
lfu->put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
cout<< lfu->get(1) <<endl;      // return 1
                 // cache=[1,2], cnt(2)=1, cnt(1)=2
lfu->put(3, 3);   // 2 is the LFU key because cnt(2)=1 is the smallest, invalidate 2.
                 // cache=[3,1], cnt(3)=1, cnt(1)=2
cout<< lfu->get(2) <<endl;      // return -1 (not found)
cout<< lfu->get(3) <<endl;      // return 3
                 // cache=[3,1], cnt(3)=2, cnt(1)=2
lfu->put(4, 4);   // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1.
                 // cache=[4,3], cnt(4)=1, cnt(3)=2
cout<< lfu->get(1) <<endl;      // return -1 (not found)
cout<< lfu->get(3) <<endl;      // return 3
                 // cache=[3,4], cnt(4)=1, cnt(3)=3
cout<< lfu->get(4) <<endl;      // return 4
                 // cache=[4,3], cnt(4)=2, cnt(3)=3
}
*/
