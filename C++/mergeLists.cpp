#include<iostream>
#include<vector>
#include<queue>

struct ListNode{
    int val;
    struct ListNode* next;
    ListNode(int x): val(x),next(nullptr){}
};
struct Compare{
    bool operator()(ListNode* a,ListNode* b){
        return a->val > b->val;
    }
};

class Solution{
    public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists){
        std:: priority_queue<ListNode*,std::vector<ListNode*>,Compare>minHeap;
        for(ListNode* list: lists){
            if(list){
                minHeap.push(list);
            }
        }
        ListNode dummy(0);
        ListNode* tail =&dummy;
        while(!minHeap.empty()){
            ListNode* minNode =minHeap.top();
            minHeap.pop();
            tail->next=minNode;
            tail=minNode;

            if(minNode->next){
                minHeap.push(minNode->next);
            }
        }
        return dummy.next;
    }
};

void deleteList(ListNode* &list) {
    while (list) {
        ListNode* next = list->next;
        delete list;
        list = next;
    }
}

int main(){
    ListNode* list1=new ListNode(1);
    list1->next=new ListNode(2);
    ListNode* list2=new ListNode(1);
    list2->next=new ListNode(4);
    list2->next->next=new ListNode(5);
    ListNode* list3=new ListNode(6);
    std::vector<ListNode*>lists ={list1,list2,list3};
    Solution solution;

    std::cout<<"Original list1:";
    for(ListNode* node=list1;node!=nullptr;node=node->next){
        std::cout<<node->val<<" ";
    }
    std::cout<<std::endl;

    std::cout<<"Original list2:";
    for(ListNode* node=list2;node!=nullptr;node=node->next){
        std::cout<<node->val<<" ";
    }
    std::cout<<std::endl;

    std::cout<<"Original list3:";
    for(ListNode* node=list3;node!=nullptr;node=node->next){
        std::cout<<node->val<<" ";
    }
    std::cout<<std::endl;

    ListNode* mergedList = solution.mergeKLists(lists);
    std::cout<<"Merged list:";
    for(ListNode* node=mergedList;node !=nullptr;node = node->next){
        std::cout<<node->val<<" ";
    }
    std::cout<<std::endl;


    deleteList(mergedList);

    return 0;
}
