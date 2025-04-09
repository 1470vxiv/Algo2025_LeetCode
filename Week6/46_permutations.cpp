#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<vector<int>> permute(vector<int>& nums) {
            vector<vector<int>> result;
            vector<int> path;
            vector<bool> used(nums.size(), false);
            backtrack(nums, path, used, result);
            return result;
        }
    
        void backtrack(vector<int>& nums, vector<int>& path, vector<bool>& used, vector<vector<int>>& result) {
            if (path.size() == nums.size()) {
                result.push_back(path);
                return;
            }
            
            for (int i = 0; i < nums.size(); ++i) {
                if (used[i]) continue;
    
                used[i] = true;
                path.push_back(nums[i]);
    
                backtrack(nums, path, used, result); // when path.size() == nums.size() only return
    
                path.pop_back();
                used[i] = false;
            }
        }
        
    };

/*
int main()
{
    vector<int> nums = {1,2,3,4};
    Solution sol;
    vector<vector<int>> ans = sol.permute(nums);

    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<ans[0].size(); j++)
        {
            cout<<ans[i][j]<<' ';
        }
        cout<<'\n';
    }
}*/
