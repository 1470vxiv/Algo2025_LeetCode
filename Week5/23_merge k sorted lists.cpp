#include <iostream>
#include <vector>
using namespace std;

//Definition of single-ended link list
struct ListNode {
         int val;
         ListNode* next;
         ListNode() : val(0), next(nullptr) {}
         ListNode(int x) : val(x), next(nullptr) {}
         ListNode(int x, ListNode* next) : val(x), next(next) {}
     };

class Solution {

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Remove all nullptr lists before processing
        lists.erase(remove(lists.begin(), lists.end(), nullptr), lists.end());
        if(lists.empty()) return nullptr;

        int minVal = 10000;
        int minIndex = 0;
        for(int i=0; i<lists.size(); i++)
        {
            if(lists[i] == nullptr){
                lists.erase(lists.begin()+i);   
            }
            else if(lists[i]->val < minVal){
                minVal = lists[i]->val;
                minIndex = i;
            }
        }
        if(lists.empty()) return nullptr;
        
        ListNode* head = lists[minIndex];
        lists[minIndex] = lists[minIndex]->next;
        if(lists[minIndex] == nullptr) lists.erase(lists.begin()+minIndex);
        head->next = mergeKLists(lists);
        return head;
    
        
    }
};
