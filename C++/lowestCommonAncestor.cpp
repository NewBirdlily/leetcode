#include<iostream>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int lowestCommonAncestor(TreeNode* root, int p, int q) {
        while(root){
            if(p<root->val&&q<root->val){
                root=root->left;
            }
            else if(p>root->val&&q>root->val){
                root =root->right;
            }
            return root->val;
        }
        return 0;
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
    TreeNode* root=new TreeNode(7);
    root->left=new TreeNode(1);
    root->right=new TreeNode(12);
    root->left->left=new TreeNode(0);
    root->left->right=new TreeNode(4);
    root->right->left=new TreeNode(11);
    root->right->right=new TreeNode(14);
    root->left->right->left=new TreeNode(3);
    root->left->right->right=new TreeNode(5);
    Solution solution;
    int p=1;
    int q=12;

    int commonancestor=solution.lowestCommonAncestor(root,p,q);
    std::cout<<commonancestor<<std::endl;
    deleteTree(root);
    return 0;
}