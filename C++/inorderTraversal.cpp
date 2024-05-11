#include<iostream>
#include<vector>

struct TreeNode {
  	int val;
  	struct TreeNode* left;
  	struct TreeNode* right;
  	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    std::vector<int> inorderTraversal(TreeNode* root) {
        if(root == nullptr) {
            return std::vector<int>();
        }
        std::vector<int> v;
        std::vector<int> left = inorderTraversal(root->left);
        v.insert(v.end(), left.begin(), left.end()); 
        v.push_back(root->val);  
        std::vector<int> right = inorderTraversal(root->right);
        v.insert(v.end(), right.begin(), right.end()); 
        return v;
    }
};

int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->left->right=new TreeNode(3);
    Solution solution;

    std::vector<int>inorder=solution.inorderTraversal(root);
    for(int val:inorder){
        std::cout<<val<<" ";
    }
    std::cout<<std::endl;

    delete root->left->right;
    delete root->left;
    delete root;

    return 0;
}