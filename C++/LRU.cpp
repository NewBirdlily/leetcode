#include<iostream>
#include<unordered_map>
#include <cstddef>
#include <unordered_map>

struct Node{
    int key;
    int val;
    Node* pre;
    Node* next;
    Node(int k,int v):key(k),val(v),pre(NULL),next(NULL){};
};

class Solution {
public:
    Node* head;
    Node*tail;
    std::unordered_map<int, Node*>map;
    int capacity;
    Solution(int capacity){
        this->capacity =capacity;
        this->head=new Node(0,0);
        this->tail=new Node(0,0);
        this->head->next=this->tail;
        this->tail->pre=this->head;
    }
    
    int get(int key) {
        if(map.find(key) == map.end()){
            return -1;
        }
        else{
            Node* res =map[key];
            this->move_node_head(res);
            return res->val;
        }
    }
    
    void set(int key, int value){
        if(map.find(key) !=map.end()){
            Node* target =map[key];
            this->move_node_head(target);
        }
        if(map.size()>=this->capacity){
            Node* need_remove_node =tail->pre;

            map.erase(need_remove_node->key);
            map[key]=need_remove_node;
            need_remove_node->key=key;
            need_remove_node->val=value;

            this->move_node_head(need_remove_node);
            return;
        }
        else{
            Node* new_node =new Node(key,value);
            map[key]=new_node;
            
            Node* head_nn =this->head->next;
            this->head->next=new_node;
            new_node->pre=this->head;

            new_node->next=head_nn;
            head_nn->pre=new_node;
        }

    }

    void move_node_head(Node* target){
        Node* pre =target->pre;
        Node* next =target->next;
        pre->next=next;
        next->pre=pre;

        Node* head_next=this->head->next;
        this->head->next=target;
        target->pre=this->head;
        target->next=head_next;
        head_next->pre=target;
    }
};

int main() {
    Solution s(2);
    s.set(1, 1);
    std::cout << "get(1) = " << s.get(1) << std::endl;
    s.set(2, 2);
    std::cout << "get(2) = " << s.get(2) << std::endl;
    s.set(3, 3);
    std::cout << "get(1) = " << s.get(1) << std::endl;
    std::cout << "get(3) = " << s.get(3) << std::endl;
    s.set(4,4);
    std::cout << "get(6) = " << s.get(6) << std::endl;
    return 0;
}