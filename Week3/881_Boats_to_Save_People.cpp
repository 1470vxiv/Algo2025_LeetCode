#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
    public:
        int numRescueBoats(vector<int>& people, int limit) {
            sort(people.begin(), people.end()); //從小排到大
            int n = people.size();
            vector<bool> onboat(n, false);
            int result = 0;
            
            //one front traversal, one back traversal, 找在limit內又有選到最重的人的雙人組合
            for(int i=0; i<n; i++)
            {
                if(onboat[i] == false)
                {
                    
                    int small = people[i];
                    for(int j=n-1; j>i; j--)
                    {
                        int big = people[j];
                        
                        if(small + big > limit || onboat[j] == true) continue;
                        else
                        {
                            //cout<<i<<' '<<j<<endl;
                            onboat[i] = true;
                            onboat[j] = true;
                            result++;
                            break;

                        }
                }
                }
                else continue;
                
            }
            for(int i=0; i<n; i++)
            {
                
                if(onboat[i] == false)
                {
                    onboat[i] = true;
                    result++;
                }
            }
            
            return result;
                       
        }
    };

/*
int main()
{
    vector<int> people = {5,1,4,2};
    int limit = 6;
    Solution sol;
    int result = sol.numRescueBoats(people, limit);

    
    cout <<result << endl;

    return 0;

}
    */

