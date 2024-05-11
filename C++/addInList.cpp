#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addInList(ListNode* head1, ListNode* head2) {
        ListNode *reversed_head1 = reverse(head1);
        ListNode *reversed_head2 = reverse(head2);
        ListNode *dummy = new ListNode(0);
        ListNode *pre = dummy;
        int carry = 0;
        while (reversed_head1 || reversed_head2 || carry) {
            int sum = carry;
            if (reversed_head1) {
                sum += reversed_head1->val;
                reversed_head1 = reversed_head1->next;
            }
            if (reversed_head2) {
                sum += reversed_head2->val;
                reversed_head2 = reversed_head2->next;
            }
            carry = sum / 10;
            pre->next = new ListNode(sum % 10);
            pre = pre->next;
        }
        return reverse(dummy->next);
    }

private:
    ListNode *reverse(ListNode* head) {
        ListNode *prev = nullptr;
        ListNode *current = head;
        while (current) {
            ListNode *next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
};

void deleteList(ListNode* &head) {
    while (head) {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    ListNode* head1 = new ListNode(9);
    head1->next = new ListNode(3);
    head1->next->next = new ListNode(7);
    ListNode* head2 = new ListNode(6);
    head2->next = new ListNode(3);
    Solution solution;

    ListNode* addHead = solution.addInList(head1, head2);
    ListNode* current = addHead; 
    while (current) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;

    deleteList(addHead); 

    return 0;
}
