#include <iostream>
#include <vector>
#include <algorithm> 

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* sortInList(ListNode* head) {
        std::vector<int> v;
        while (head) {
            v.push_back(head->val);
            head = head->next;
        }
        std::sort(v.begin(), v.end());
        ListNode* dummy = new ListNode(-1); 
        ListNode* current = dummy;
        for (int i = 0; i < v.size(); i++) {
            current->next = new ListNode(v[i]);
            current = current->next;
        }
        return dummy->next; 
    }
};

int main() {
    std::vector<int> v = {1, 3, 2, 4, 5}; 
    Solution solution;
    ListNode* head = new ListNode(v[0]); 
    ListNode* current = head;
    for (int i = 1; i < v.size(); i++) { 
        current->next = new ListNode(v[i]);
        current = current->next;
    }

    ListNode* sortHead = solution.sortInList(head); 
    while (sortHead) { 
        std::cout << sortHead->val << " ";
        sortHead = sortHead->next;
    }
    std::cout << std::endl;

    while(current){
        ListNode* next=current->next;
        delete current;
        current=next;
    }

    return 0;
}