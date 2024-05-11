#include<iostream>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };

class Solution {
public:
    TreeNode* Mirror(TreeNode* pRoot) {
        if (!pRoot) {
            return nullptr; 
        }
        TreeNode* tmp = new TreeNode(0); 
        tmp=pRoot->left;
        pRoot->left=pRoot->right;
        pRoot->right=tmp;
        Mirror(pRoot->right);
        Mirror(pRoot->left);    
        return pRoot;
    }
};

void printTree(TreeNode* root) {
    if (root) {
        std::cout << root->val << " ";
        printTree(root->left);
        printTree(root->right);
    }
}

void deleteTree(TreeNode* root) {
    if (root) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

int main(){
    TreeNode* pRoot=new TreeNode(8);
    pRoot->left=new TreeNode(6);
    pRoot->right=new TreeNode(10);
    pRoot->left->left=new TreeNode(5);
    pRoot->left->right=new TreeNode(7);
    pRoot->right->left=new TreeNode(9);
    pRoot->right->right=new TreeNode(11);
    Solution solution;
    TreeNode* root=solution.Mirror(pRoot);

    std::cout<<"Mirror tree: ";
    printTree(root);
    std::cout << std::endl;

    deleteTree(root);

    return 0;
}