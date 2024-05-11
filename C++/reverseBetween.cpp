#include<iostream>

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution{
    public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n) {
            return head;
        }

        ListNode* pre = head;
        ListNode* current = nullptr;
        ListNode* next = nullptr;

        for (int i = 0; i < m - 1; i++) {
            pre = pre->next;
        }
        current = pre->next;

        for (int i = m; i < n; i++) {
            next = current->next;
            current->next = pre;
            pre = current;
            current = next;
        }

        if (m == 1) {
            head->next = current;
            return pre;
        } else {
            ListNode* temp = head;
            for (int i = 0; i < m - 2; i++) {
                temp = temp->next;
            }
            temp->next->next = current;
            temp->next = pre;
            return head;
        }
    }
};

int main(){
    ListNode* head = new ListNode(1);
    head->next=new ListNode(2);
    head->next->next=new ListNode(3);
    head->next->next->next=new ListNode(4);
    head->next->next->next->next =new ListNode(5);
    int m=2,n=4;
    Solution solution;

    std::cout<<"Original list:";
    for(ListNode* node=head;node!=nullptr;node=node->next){
        std::cout<<node->val<<" ";
    }
    std::cout<<std::endl;

    ListNode* reversedHead = solution.reverseBetween(head,2,4);
    std::cout<<"Reversed part of list:";
    for(ListNode* node =reversedHead;node !=nullptr;node=node->next){
        std::cout<<node->val<<" ";
    }
    std::cout<<std::endl;

    while(head!=nullptr){
        ListNode* next =head->next;
        delete head;
        head=next;
    }
    
    return 0;
}


