#include<iostream>
#include<queue>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
  public:
    bool isCompleteTree(TreeNode* root) {
        if (!root) return true;
        std::queue<TreeNode*> q;
        q.push(root);
        bool reachedEnd = false;
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (!node) {
                reachedEnd = true;
                continue;
            }
            if (reachedEnd) {
                return false;
            }
            q.push(node->left);
            q.push(node->right);
        }
        return true;
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
    root->right->right=new TreeNode(6);
    Solution solution;
    bool isCTree=solution.isCompleteTree(root);
    if(isCTree){
        std::cout<<"The given binary tree is Completetree."<<std::endl;
    }
    else{
        std::cout<<"The given binary tree is not Completetree."<<std::endl;
    }

    deleteTree(root);
    return 0;
}