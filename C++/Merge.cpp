#include<iostream>

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution{
    public:
        ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
            if(pHead1 == nullptr){
                return pHead2;
            }
            if(pHead2 == nullptr){
                return pHead1;
            }

            ListNode* p = new ListNode(0);
            ListNode* current =p;
            while(pHead1 !=nullptr && pHead2 != nullptr){
                if(pHead1->val <= pHead2->val){
                    current->next = pHead1;
                    pHead1 = pHead1->next;
                }
                else{
                    current->next = pHead2;
                    pHead2 = pHead2->next;
                }
                current =current->next;
            }
            if(pHead1 !=nullptr){
                current->next =pHead1;
            }
            if(pHead2 !=nullptr){
                current->next =pHead2;
            }
            return p->next;
        }
};

int main(){
    ListNode *pHead1=new ListNode(1);
    pHead1->next=new ListNode(3);
    pHead1->next->next=new ListNode(5);
    ListNode *pHead2 =new ListNode(2);
    pHead2->next=new ListNode(4);
    pHead2->next->next=new ListNode(6);
    Solution solution;

    std::cout<<"Original list1:";
    for(ListNode* node=pHead1;node!=nullptr;node=node->next){
        std::cout<<node->val<<" ";
    }
    std::cout<<std::endl;

    std::cout<<"Original list2:";
    for(ListNode* node=pHead2;node !=nullptr;node=node->next){
        std::cout<<node->val<<" ";
    }
    std::cout<<std::endl;

    ListNode* mergedHead = solution.Merge(pHead1, pHead2);
    std::cout<<"Merged list:";
    for(ListNode* node=mergedHead;node !=nullptr;node = node->next){
        std::cout<<node->val<<" ";
    }
    std::cout<<std::endl;

    while(pHead1){
        ListNode* next =pHead1->next;
        delete pHead1;
        pHead1=next;
    }
    while(pHead2){
        ListNode* next=pHead2->next;
        delete pHead2;
        pHead2=next;
    }

    return 0;
}