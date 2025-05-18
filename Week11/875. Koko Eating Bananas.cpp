class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;  // minimum possible eating speed
        int right = *max_element(piles.begin(), piles.end());  // maximum possible eating speed
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canFinish(piles, h, mid)) {
                right = mid;  // try to find a smaller k
            } else {
                left = mid + 1;  // need a bigger k
            }
        }
        return left;
    }
    
private:
    bool canFinish(vector<int>& piles, int h, int k) {
        int time = 0;
        for (int bananas : piles) {
            time += (bananas + k - 1) / k;  // same as ceil(bananas/k)
        }
        return time <= h;
    }
};
