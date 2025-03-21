#include <iostream>
#include <unordered_map>
#include <list>

class LRUCache {
private:
    int capacity;
    std::list<std::pair<int, int>> cacheList;
//用list對頭尾操作為O(1)，方便most(最頭)/least(最尾) frequent used key操作
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cacheMap;
//用hash table(map)記住每個key對應的list iterator，這樣在erase任意位置的cache的時候才會O(1) (不用traversal whole list)

    void moveToFront(int key, int value) {
        cacheList.erase(cacheMap[key]);
        cacheList.push_front({key, value});
        cacheMap[key] = cacheList.begin();
    }

public:
    LRUCache(int c) : capacity(c) {}
    
    int get(int key) {
        if (cacheMap.find(key) == cacheMap.end()) {
            return -1;
        }
        auto value = cacheMap[key]->second; // *cacheMap[key] is a pair
        moveToFront(key, value);
        return value;
    }
    
    void put(int key, int value) {
        if (cacheMap.find(key) != cacheMap.end()) {
            moveToFront(key, value);
        } else {
            if (cacheList.size() == capacity) {
                int lruKey = cacheList.back().first;
                cacheList.pop_back();
                cacheMap.erase(lruKey);
            }
            cacheList.push_front({key, value});
            cacheMap[key] = cacheList.begin();
        }
    }
};

/*
int main() {
    LRUCache* obj = new LRUCache(2);
    obj->put(1, 1);
    obj->put(2, 2);
    std::cout << obj->get(1) << std::endl; // Output: 1
    obj->put(3, 3); // Removes key 2
    std::cout << obj->get(2) << std::endl; // Output: -1 (not found)
    obj->put(4, 4); // Removes key 1
    std::cout << obj->get(1) << std::endl; // Output: -1 (not found)
    std::cout << obj->get(3) << std::endl; // Output: 3
    std::cout << obj->get(4) << std::endl; // Output: 4
    delete obj;
    return 0;
}*/
