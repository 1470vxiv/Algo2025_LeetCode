#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int jump(vector<int>& nums) {
            int result = 0;
            int m = nums.size();
            int nowIdx = 0;
            int farthest = 0;

            if(m == 1) return 0;
            
            for(int i=0; i<m-1; i++)
            {
                farthest = max(farthest, i+nums[i]);

                if(i == nowIdx){
                    result++;
                    nowIdx =  farthest;
                }
            }
        
        return result;
        }
        
    };

/*
int main()
{
    vector<int> nums = {10,9,8,7,6,5,4,3,2,1,1,0};
    Solution sol;
    int result = sol.jump(nums);

    
    cout <<result << endl;

    return 0;

}
*/
