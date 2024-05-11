#include<iostream>
#include<vector>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  };

class Solution{
    public:
    std::vector<int> preorderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return std::vector<int>(); 
        }
        std::vector<int> v;
        v.push_back(root->val);
        std::vector<int> left = preorderTraversal(root->left);
        std::vector<int> right = preorderTraversal(root->right);
        v.insert(v.end(), left.begin(), left.end());
        v.insert(v.end(), right.begin(), right.end());
        return v;
    }
};

int main(){
    TreeNode* root =new TreeNode(1);
    root->right=new TreeNode(2);
    root->right->left=new TreeNode(3);
    Solution solution;

    std::vector<int>preorder=solution.preorderTraversal(root);
    for(int val: preorder){
        std::cout<<val<<" ";
    }
    std::cout<<std::endl;

    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}