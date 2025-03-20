#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int jump(vector<int>& nums) {
            int result = 0;
            int m = nums.size();
            int nowIdx = 0;
            int farthest = 0; // 從index i出發，能抵達的最遠位置

            if(m == 1) return 0;
            
            for(int i=0; i<m-1; i++)
            {
                farthest = max(farthest, i+nums[i]); // 每個i都要更新farthest

                if(i == nowIdx){
                    result++;
                    nowIdx =  farthest; //i輪到nowIdx時才執行，一次就移動到farthest
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
