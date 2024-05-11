#include<iostream>
#include<algorithm>
#include<cmath>

struct TreeNode {
 	int val;
 	struct TreeNode *left;
 	struct TreeNode *right;
 	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root ==nullptr){return 0;}
        return std::max(maxDepth(root->left),maxDepth(root->right))+1;
    }
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->right->right=new TreeNode(5);
    Solution solution;

    int maxdepth =solution.maxDepth(root);
    std::cout<<maxdepth<<std::endl;
    return 0;
}