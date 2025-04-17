#include <iostream>
using namespace std;

//Definition of single-ended link list
/*
struct ListNode {
         int val;
         ListNode* next;
         ListNode() : val(0), next(nullptr) {}
         ListNode(int x) : val(x), next(nullptr) {}
         ListNode(int x, ListNode* next) : val(x), next(next) {}
     };*/

class Solution {
    public:
        ListNode* reverseKGroup(ListNode* head, int k) {
            if (!head) return nullptr;

            //確保list長度>k
            ListNode* Ktail = head;
            for(int i=0; i<k-1; i++)
            {
                Ktail = Ktail->next;
                if(Ktail == nullptr)
                {
                    return head;
                    break;
                }
            }

            ListNode* par = nullptr;
            ListNode* curr = head;
            ListNode* son = curr->next;  
            for(int i=0;i<k;i++)
            {
                son = curr->next; //curr = 2, son = 3; curr = 3, son = 4
                curr->next = par; // curr->next = 1; curr -> next = 2;
                par = curr; //parr = 2; par = 3;
                curr = son; // curr = 3; curr = 4;
            }

            head->next = reverseKGroup(curr, k);
            return par;
       
        }
    };
/*
void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    int k=5;

    Solution sol;
    ListNode* result = sol.reverseKGroup(head,k);

    printList(result);
    return 0;
}*/
