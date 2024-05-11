#include<iostream>

struct ListNode {
   int val;
   struct ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};
class Solution{
    public:
    ListNode* ReverseList(ListNode* head) {
        while (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        while (head != nullptr) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};

int main(){
    ListNode* head = new ListNode(1);
    head->next=new ListNode(2);
    head->next->next=new ListNode(3);
    Solution solution;
    
    std::cout << "Original list: ";
    for (ListNode* node = head; node != nullptr; node = node->next) {
        std::cout << node->val << " ";
    }
    std::cout << std::endl;
    
    ListNode* reversedHead = solution.ReverseList(head);
    std::cout<<"Reversed list:";
    for(ListNode* node = reversedHead;node!=nullptr;node=node->next){
        std::cout<<node->val<<" ";
    }
    std::cout<<std::endl;

    while(head !=nullptr){
        ListNode*next=head->next;
        delete head;
        head=next;
    }

    return 0;
}