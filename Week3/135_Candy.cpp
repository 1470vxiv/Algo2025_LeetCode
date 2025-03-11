#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int candy(vector<int>& ratings) {
            
            int n = ratings.size();
            int result = 0;
            vector<int> distr(n,1);
            for(int i=1; i<n; i++)//左到右、右比左
            {
                if(ratings[i] > ratings[i-1])
                {    
                    distr[i] = distr[i-1] + 1;
                }
            }

            for(int i=n-1; i>0; i--)//右到左、左比右
            {
                if(ratings[i-1] > ratings[i])
                {
                    if(distr[i-1] <= distr[i])
                    {
                        distr[i-1] = distr[i] + 1;
                    }
                }
            }

            for(int i=0;i<n;i++) result += distr[i];

            //for(int i=0;i<n;i++) cout<<distr[i]<<' ';
            return result;
        }
    };


/*
int main()
{
    vector<int> ratings = {1,6,10,8,7,3,2};
    Solution sol;
    int result = sol.candy(ratings);
    cout<<result<<endl;

    
}
*/
