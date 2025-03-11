#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
        int intersectionSizeTwo(vector<vector<int>>& intervals) {
            int n = intervals.size();
            int result = 0;
            
            //sorting according to tails
            sort(intervals.begin(), intervals.end(), \
                [](const vector<int>& a, const vector<int>& b) {
                if (a[1] == b[1]) // If second values are equal, sort by first value
                    return a[0] > b[0];
                return a[1] < b[1];
            });

            
            /*for (const auto& p : intervals) {
                cout << "(" << p[0] << ", " << p[1]<< ") ";
            }
            cout<<endl;*/

            int maxChosen;
            int secChosen;

            for(int i=0;i<n;i++)
            {
                int count = 0;

                if(i>0)
                {
                    if(maxChosen >= intervals[i][0] && maxChosen <= intervals[i][1])
                    {
                        if(secChosen >= intervals[i][0] && secChosen <= intervals[i][1]){
                            count = 2;
                        }
                        else count = 1;
                    }
                }

                if(count == 0 || i==0)
                {
                    maxChosen = intervals[i][1];
                    //cout<<intervals[i][1]<<' ';
                    secChosen = intervals[i][1]-1;
                    //cout<<intervals[i][1]-1<<' ';
                    result += 2;
                }
                else if(count == 1)
                {
                    secChosen = maxChosen;
                    maxChosen = intervals[i][1];
                    //cout<<intervals[i][1]<<' ';
                    result ++;
                }

            }
            return result;
            
        }
    };

int main()
{
        vector<vector<int>> intervals = { 
            {3, 10}, {3, 15}, {12, 16}, {1, 6}, {3, 4}, {0, 20}, {0, 13}, 
            {12, 16}, {11, 15}, {14, 20}, {6, 9}, {11, 20}, {4, 9}, {13, 20}, 
            {5, 16}, {4, 14}, {1, 15}, {10, 20}, {6, 19}, {1, 17} 
        };
        Solution sol;
        int result = sol.intersectionSizeTwo(intervals);
        cout<<result<<endl;
    
        
}