#include<iostream>

struct TreeNode {
    int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int lowestCommonAncestor(TreeNode* root, int o1, int o2) {
        if (!root) {
            return -1;
        }
        if (root->val == o1 || root->val == o2) {
            return root->val;
        }
        int left = lowestCommonAncestor(root->left, o1, o2);
        int right = lowestCommonAncestor(root->right, o1, o2);
        if (left == -1) {
            return right;
        }
        if (right == -1) {
            return left;
        }
        return root->val;
    }
};

void deleteTree(TreeNode* root){
    if(root){
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

int main(){
    TreeNode* root = new TreeNode(3);
    root->left=new TreeNode(5);
    root->right=new TreeNode(1);
    root->left->left=new TreeNode(6);
    root->left->right=new TreeNode(2);
    root->right->left=new TreeNode(0);
    root->right->right=new TreeNode(8);
    root->left->right->left=new TreeNode(7);
    root->left->right->right=new TreeNode(4);
    Solution solution;
    int p=2,q=7;
    int commonancestor=solution.lowestCommonAncestor(root,p,q);
    std::cout<<commonancestor<<std::endl;
    deleteTree(root);
    return 0;
}