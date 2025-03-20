#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {

public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> dq; //存index of nums, 從小到大排, 用deque才能pop_front又pop_back
        int m = nums.size();
        int max_idx = 0;

        for(int i=0; i < m; i++){
            
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }

            // Remove elements from the back that are smaller than the current element
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }


            // Add current element index
            dq.push_back(i);     
            

            if(i >= k-1) result.push_back(nums[dq.front()]); //first element of dq must be the maximum
        }

    return result;   
        
    }
};

/*
int main()
{
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    Solution sol;
    vector<int> result = sol.maxSlidingWindow(nums, k);

    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;

}
*/
