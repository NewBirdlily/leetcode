#include<iostream>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(0);
        if (t1 && t2) {
            root->val = t1->val + t2->val;
            root->left = mergeTrees(t1->left, t2->left);
            root->right = mergeTrees(t1->right, t2->right);
        } 
        else if (t1) {
            root->val = t1->val;
            root->left = mergeTrees(t1->left, nullptr); 
            root->right = mergeTrees(t1->right, nullptr);
        } 
        else {
            root->val = t2->val;
            root->left = mergeTrees(nullptr, t2->left); 
            root->right = mergeTrees(nullptr, t2->right);
        }
        return root;
    }
};

void deleteTree(TreeNode* root) {
    if (root) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

void printTree(TreeNode* root) {
    if (root) {
        std::cout << root->val << " ";
        printTree(root->left);
        printTree(root->right);
    }
}

int main(){
    TreeNode* root1=new TreeNode(1);
    root1->left=new TreeNode(3);
    root1->right=new TreeNode(2);
    root1->left->left=new TreeNode(5);

    TreeNode* root2=new TreeNode(2);
    root2->left=new TreeNode(1);
    root2->right=new TreeNode(3);
    root2->left->right=new TreeNode(4);
    root2->right->right=new TreeNode(7);

    Solution solution;
    TreeNode* root=solution.mergeTrees(root1,root2);

    std::cout << "Merged Tree: ";
    printTree(root);
    std::cout << std::endl;

    deleteTree(root);

    return 0;
}
