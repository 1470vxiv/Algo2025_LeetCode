#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        long long minimumReplacement(vector<int>& nums) {
        long long operations = 0;
        int n = nums.size();
        int next = nums[n - 1];  // Start from the last element
    
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] > next) {  // Need to split
                int parts = (nums[i] + next - 1) / next; // ceil(nums[i] / next)
                operations += (parts - 1);
                next = nums[i] / parts; // Maximum possible value of each part
            } else {
                next = nums[i]; // Move to the next element
            }
        }
        return operations;
    }
    
};

/*
int main()
{
    vector<int> nums = {3,9,3};
    Solution sol;
    int result = sol.minimumReplacement(nums);

    
    cout <<result << endl;

    return 0;

}
    */