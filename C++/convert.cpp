#include<iostream>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(nullptr), right(nullptr) {
    }
};

class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree) {
        if (pRootOfTree == nullptr) {
            return nullptr;
        }

        TreeNode* left = Convert(pRootOfTree->left);
        TreeNode* pre = left;

        if (left) {
            while (pre->right) {
                pre = pre->right;
            }
            pre->right = pRootOfTree;
            pRootOfTree->left = pre;
        }

        TreeNode* right = Convert(pRootOfTree->right);
        TreeNode* next = right;

        if (right) {
            while (next->left) {
                next = next->left;
            }
            next->left = pRootOfTree;
            pRootOfTree->right = next;
        }

        return left ? left : pRootOfTree;
    }
};

void printleftTorightList(TreeNode* head) {
    std::cout << "From left to right: ";
    TreeNode* current = head;
    while (current) {
        std::cout << current->val << " ";
        current = current->right;
    }
    std::cout << std::endl;
}

void printrightToleftList(TreeNode* tail) {
    std::cout<<"From right to left: ";
    TreeNode* current= tail;
    while(current){
        std::cout<< current->val<<" ";
        current = current->left;
    }
    std::cout<<std::endl;
}

void deleteList(TreeNode* head) {
    while (head) {
        TreeNode* temp = head;
        head = head->right;
        delete temp;
    }
}

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(6);
    root->right = new TreeNode(14);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(8);
    root->right->left = new TreeNode(12);
    root->right->right = new TreeNode(16);

    Solution solution;
    TreeNode* head = solution.Convert(root);

    printleftTorightList(head);

    TreeNode* tail = head;
    while (tail->right) {
        tail = tail->right;
    }
    printrightToleftList(tail);

    deleteList(head); 

    return 0;
}
