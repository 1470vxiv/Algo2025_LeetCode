#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
    public:
        int minSwapsCouples(vector<int>& row) {
            int n = row.size();
            unordered_map<int, int> position; // Maps value to its index, 找到partner的時間O(1)
    
            // Build the index mapping
            for (int i = 0; i < n; i++) {
                position[row[i]] = i;
            }
    
            int swaps = 0;
            
            // Process each couple in the row
            for (int i = 0; i < n; i += 2) { //一次處理一對couple
                int first = row[i];
                int second;
                //找對應的partner
                if(first%2 == 0){
                    second = first + 1;
                }else{
                    second = first - 1;
                }
    
                if (row[i + 1] == second) {
                    continue; // Already in correct position
                }
    
                // Swap required
                int partnerIndex = position[second];
    
                // Update position mapping
                position[row[i + 1]] = partnerIndex;
                position[second] = i + 1;
    
                // Swap elements in the row
                swap(row[i + 1], row[partnerIndex]);
    
                swaps++;
            }
    
            return swaps;
        }
    };


int main()
{
    vector<int> nums = {0,2,1,3};
    Solution sol;
    int result = sol.minSwapsCouples(nums);

    
    cout <<result << endl;

    return 0;

}
