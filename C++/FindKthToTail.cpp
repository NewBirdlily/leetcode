#include<iostream>

struct ListNode {
 	int val;
 	struct ListNode *next;
 	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution{
    public:
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        if(!pHead  || k<=0){
            return nullptr;
        }
        ListNode *fast = pHead;
        ListNode *slow = pHead;
        for(int i =0;i<k;i++){
            if(!fast){
                return nullptr;
            }
            fast = fast->next;
        }
        while(fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
void freeLists(ListNode* head){
    while(head){
        ListNode *next=head->next;
        delete head;
        head=next;
    }
}

int main(){
    ListNode *pHead = new ListNode(1);
    pHead->next= new ListNode(2);
    pHead->next->next=new ListNode(3);
    pHead->next->next->next=new ListNode(4);
    pHead->next->next->next->next=new ListNode(5);
    int k=2;
    Solution solution;

    ListNode* ktotailnode=solution.FindKthToTail(pHead,2);
    if(ktotailnode){
        std::cout<<"The "<<k<<"th node from the end is:"<<ktotailnode->val<<std::endl;
    }
    else{
        std::cout<<"The list has less than"<<k<<"nodes."<<std::endl;
    }
    freeLists(pHead);
    return 0;
}