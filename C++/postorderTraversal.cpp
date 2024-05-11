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
    std::vector<int> postorderTraversal(TreeNode* root) {
        if(root == nullptr){
            return std::vector<int>();
        }       
        std::vector<int> v;
        std::vector<int> left = postorderTraversal(root->left);
        v.insert(v.end(), left.begin(), left.end());
        std::vector<int> right = postorderTraversal(root->right);
        v.insert(v.end(), right.begin(), right.end());
        v.push_back(root->val);       
        return v;
    }
};

int main(){
    TreeNode* root=new TreeNode(1);
    root->right=new TreeNode(2);
    root->right->left=new TreeNode(3);
    Solution solution;

    std::vector<int>postorder=solution.postorderTraversal(root);
    for(int val:postorder){
        std::cout<<val<<" ";
    }
    std::cout<<std::endl;

    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}