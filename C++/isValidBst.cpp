#include<iostream>
#include<vector>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        std::vector<int>v=inorder(root);
        for(int i=1;i<v.size();i++){
            if(v[i-1]>v[i]){
                return false;
            }
        }
        return true;
    }
    std::vector<int>inorder(TreeNode* root){
        if(!root){return std::vector<int>();}
        std::vector<int>v;
        std::vector<int>left=inorder(root->left);
        v.insert(v.end(),left.begin(),left.end());
        v.push_back(root->val);
        std::vector<int>right=inorder(root->right);
        v.insert(v.end(),right.begin(),right.end());
        return v;
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
    Solution solution;
    bool isBST=solution.isValidBST(root);

    if(isBST){
        std::cout<<"The given binary tree is a valid binary search tree."<<std::endl;
    }
    else{
        std::cout<<"The given binary tree is not a valid binary search tree."<<std::endl;
    }

    deleteTree(root);

    return 0;
}