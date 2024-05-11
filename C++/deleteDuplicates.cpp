#include<iostream>
#include<vector>
#include<algorithm>

struct ListNode {
   int val;
   struct ListNode* next;
   ListNode(int x) : val(x), next(nullptr) {}
};

class Solution{
    public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head; // 如果链表为空或只有一个节点，则直接返回
        }

        std::vector<int> v; // 用于存储链表中的元素值
        while (head) {
            v.push_back(head->val); // 将链表中的元素值存储到向量中
            head = head->next; // 移动到下一个节点
        }

        auto newend = std::unique(v.begin(), v.end()); // 去除向量中的重复元素,将这些重复的元素移动到向量的开始位置，并返回一个指向“新”向量末尾的迭代器
        v.erase(newend,v.end()); // 删除多余的元素，使得向量中只包含不重复的元素

        ListNode* dummy = new ListNode(0); // 创建一个虚拟头节点
        ListNode* newhead = dummy; // 新链表的头指针指向虚拟头节点

        // 根据向量中的元素值构建新的链表
        for (int val : v) {
            dummy->next = new ListNode(val); // 创建新节点
            dummy = dummy->next; // 移动到下一个节点
        }

        return newhead->next; // 返回新链表的头指针（跳过虚拟头节点）
    }
};

int main(){
    std::vector<int>v={1,1,2};
    Solution solution;
    ListNode* head = new ListNode(v[0]); 
    ListNode* current = head;
    for (int i = 1; i < v.size(); i++) { 
        current->next = new ListNode(v[i]);
        current = current->next;
    }
    
    ListNode* deleteDuplicateHead = solution.deleteDuplicates(head);
    while(deleteDuplicateHead){
        std::cout<<deleteDuplicateHead->val<<" ";
        deleteDuplicateHead=deleteDuplicateHead->next;
    }
    std::cout<<std::endl;

    while(head){
        ListNode* next=head->next;
        delete head;
        head=next;
    }

    return 0;
}