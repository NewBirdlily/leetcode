#include<iostream>
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x ):val(x),next(NULL){}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr ||head->next ==nullptr){
            return false;
        }
        ListNode *slow =head;
        ListNode *fast =head;
        while(slow !=nullptr && fast !=nullptr && fast->next !=nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                return true;
            }
        }
        return false;
    }
};

int main(){
    ListNode* head =new ListNode(3);
    ListNode* node1=new ListNode(2);
    ListNode* node2=new ListNode(0);
    ListNode* node3=new ListNode(-4);
    head->next=node1;
    node1->next=node2;
    node2->next=node3;
    node3->next=node1;
    Solution solution;

    bool hasCycle =solution.hasCycle(head);
    std::cout<<(hasCycle ?"true":"false")<<std::endl;

    delete head;
    delete node1;
    delete node2;
    delete node3;

    return 0;
}