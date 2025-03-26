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
        ListNode* swapPairs(ListNode* head) {
            if (!head || !head->next) return head;
    
            ListNode* newHead = (*head).next; //head->next 2
            head->next = swapPairs(newHead->next); // 1 -> (3 & 4)
            (*newHead).next = head;
    
            return newHead;
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

    Solution sol;
    ListNode* result = sol.swapPairs(head);

    printList(result);
    return 0;
}*/