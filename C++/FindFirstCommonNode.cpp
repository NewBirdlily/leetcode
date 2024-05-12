#include<iostream>

struct ListNode{
    int val;
    struct ListNode *next;
    ListNode(int x):
        val(x),next(NULL){}
};

class Solution {
public:
    ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
    	if(pHead1 ==nullptr ||pHead2 ==nullptr){return nullptr;}
		ListNode *p1 =pHead1;
		ListNode *p2 =pHead2;
		int len1 =0;
		int len2 = 0;
		while(p1){
			p1 = p1->next;
			len1++;
		}
		while(p2){
			p2 = p2->next;
			len2++;
		}
		if(len2 >len1){
			ListNode *tmp =pHead1;
			pHead1 = pHead2;
			pHead2 =tmp;
		}
		int len = len1-len2;
		while(len--){
			pHead1 = pHead1->next;
		}
		while(pHead1 && pHead2){
			if(pHead1 ==pHead2){
				return pHead1;
			}
			pHead1 = pHead1->next;
			pHead2 = pHead2->next;
		}
		return nullptr;
    }
};
void deleteList(ListNode* &head){
    while(head){
        ListNode* next=head->next;
        delete head;
        head=next;
    }
}
int main(){
    ListNode* phead1 = new ListNode(1);
    phead1->next=new ListNode(2);
    phead1->next->next=new ListNode(6);
    phead1->next->next->next=new ListNode(7);

    ListNode* phead2 = new ListNode(4);
    phead2->next=new ListNode(5);
    phead2->next->next = phead1->next->next;
    Solution solution;
    ListNode* commonNode= solution.FindFirstCommonNode(phead1,phead2);

    if(commonNode){
        std::cout<<"The first common node is:"<<commonNode->val<<std::endl;
    }
    else{
        std::cout<<"There is not common node."<<std::endl;
    }
    
    deleteList(phead1);

    return 0;
}