#include<iostream>
#include<cmath>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(!pRoot){return true;}
        int left=depth(pRoot->left);
        int right=depth(pRoot->right);
        if(abs(left-right)>1){
            return false;
        }
         return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
    }
    int depth(TreeNode* root){
        if(!root){return 0;}
        return std::max(depth(root->left),depth(root->right))+1;
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
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    root->right->left=new TreeNode(6);
    root->right->right=new TreeNode(7);
    Solution solution;
    bool isBalancedTree=solution.IsBalanced_Solution(root);
    if(isBalancedTree){
        std::cout<<"The given binary tree is a balancedtree."<<std::endl;
    }
    else{
        std::cout<<"The given binary tree is not a blancedtree."<<std::endl;
    }
    deleteTree(root);
    return 0;
}