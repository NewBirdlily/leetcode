#include<iostream>

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
  public:
  ListNode* deleteDuplicates(ListNode* head) {
       ListNode *dummy = new ListNode(-1), *cur = dummy;
        dummy->next = head;
        while (cur->next && cur->next->next) {
            if (cur->next->val == cur->next->next->val) {
                int tmp = cur->next->val;
                while (cur->next && cur->next->val == tmp) {
                    cur->next = cur->next->next;
                }
            }
            else cur = cur->next;
        }
        return dummy->next;
    }
};

int main(){
    ListNode* head=new ListNode(1);
    head->next=new ListNode(2);
    head->next->next=new ListNode(3);
    head->next->next->next=new ListNode(3);
    head->next->next->next->next=new ListNode(4);
    head->next->next->next->next->next=new ListNode(4);
    head->next->next->next->next->next->next=new ListNode(5);
    Solution solution;

    std::cout<<"Original list:";
    for(ListNode* node=head;node !=nullptr;node=node->next){
        std::cout<<node->val<<" ";
    }
    std::cout<<std::endl;

    ListNode* deleteHead=solution.deleteDuplicates(head);
    while(deleteHead){
        std::cout<<deleteHead->val<<" ";
        deleteHead=deleteHead->next;
    }
    std::cout<<std::endl;

    while(head){
        ListNode* next=head->next;
        delete head;
        head=next;
    }
    return 0;
}