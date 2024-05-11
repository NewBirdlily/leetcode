#include<iostream>

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        if(pHead ==nullptr || pHead->next ==nullptr){
            return nullptr;
        }
        ListNode *slow = pHead;
        ListNode *fast = pHead;
        while(slow !=nullptr && fast !=nullptr && fast->next !=nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                fast =pHead;
                while(fast !=slow){
                    fast = fast->next;
                    slow = slow->next;
                }
                return fast;
            }
        }
        return nullptr;
    }
};

int main(){
    ListNode* phead=new ListNode(1);
    ListNode* node1 = new ListNode(2);
    ListNode* node2 = new ListNode(3);
    ListNode* node3 = new ListNode(4);
    ListNode* node4 = new ListNode(5);
    phead->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4; 
    node4->next = node2;

    Solution solution;
    ListNode* entryNode = solution.EntryNodeOfLoop(phead);

    if (entryNode != nullptr) {
        std::cout << "The value of the entry node of the loop is: " << entryNode->val << std::endl;
    } else {
        std::cout << "There is no loop in the list." << std::endl;
    }

    delete phead;
    delete node1;
    delete node2;
    delete node3;
    delete node4;

    return 0;
}