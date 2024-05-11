#include <iostream>
#include <vector>
#include <algorithm>

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution{
    public:
     bool isPail(ListNode* head) {
        // write code here
        std::vector<int>v;
        ListNode*current =head;
        while(current){
            v.push_back(current->val);
            current =current->next;
        }
        return std::equal(v.begin(),v.end(),v.rbegin());
    }
};

int main(){
    std::vector<int>v={1,2,2,1};
    Solution solution;

    ListNode* head=new ListNode(v[0]);
    ListNode* current =head;
    for(int i =1;i<v.size();i++){
        current->next=new ListNode(v[i]);
        current =current->next;
    }

    bool result =solution.isPail(head);
    if(result){
        std::cout<<"The linked list is palindrome."<<std::endl;
    }
    else{
        std::cout<<"The linked list is not a palindrome."<<std::endl;
    }

    current=head;
    while(current){
        ListNode* next=current->next;
        delete current;
        current=next;
    }
    return 0;
}