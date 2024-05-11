#include<iostream>

struct ListNode {
 	int val;
	struct ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution{
    public:
     ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr) {return nullptr;}
        ListNode *evenhead=head->next, *odd=head, *even=evenhead;
        while (even&&even->next) {
            odd->next = even->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        odd->next = evenhead;
        return head;
    }
};

int main(){
    ListNode* head=new ListNode(1);
    head->next=new ListNode(2);
    head->next->next=new ListNode(3);
    head->next->next->next=new ListNode(4);
    head->next->next->next->next=new ListNode(5);
    Solution solution;

    for(ListNode* node=head;node !=nullptr;node=node->next){
        std::cout<<node->val<<" ";
    }
    std::cout<<std::endl;

    ListNode* oddevenHead=solution.oddEvenList(head);
    for(ListNode* node=oddevenHead;node !=nullptr;node=node->next){
        std::cout<<node->val<<" ";
    }
    std::cout<<std::endl;

    while(head){
        ListNode* next=head->next;
        delete head;
        head=next;
    }

    return 0; 
}
