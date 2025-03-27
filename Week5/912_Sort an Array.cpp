#include<iostream>
#include<vector>
using namespace std;

class Solution {
    private:
    void sortPrivate(vector<int>& nums, int left, int right){

        if(left >= right) return; //base case
        
        int mid = (left + right)/2;

        sortPrivate(nums, left, mid);
        sortPrivate(nums, mid+1, right);
        merge(nums, left, mid, right);
        
    }
    void merge(vector<int>& nums, int left, int mid, int right){
        int nl = mid - left + 1;
        int nr = right - mid;

        vector<int> leftArray(nl,0);
        for(int i=0;i<nl;i++) leftArray[i] = nums[left+i];
        vector<int> rightArray(nr,0);  
        for(int j=0;j<nr;j++) rightArray[j] = nums[mid+1+j];

        int i=0, j=0, k=left;
        while(i<nl && j<nr){
            if(leftArray[i] < rightArray[j]){
                nums[k] = leftArray[i];
                i++;
            }
            else{
                nums[k] = rightArray[j];
                j++;
            }
            k++;
        }
        while(i<nl){
            nums[k] = leftArray[i];
            i++;
            k++;
        }
        while(j<nr){
            nums[k] = rightArray[j];
            j++;
            k++;
        }
    }

    public:
        vector<int> sortArray(vector<int>& nums) {
            sortPrivate(nums, 0, nums.size()-1);
            return nums;
        }
        
    };

/*
int main()
{
    vector<int> array = {5,1,1,2,0,0};
    Solution sol;
    vector<int> result = sol.sortArray(array);
    for(int i=0; i<result.size(); i++) cout<<result[i]<<" ";
    cout<<endl;
}
*/
