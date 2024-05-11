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
    TreeNode* reConstructBinaryTree(std::vector<int>& preOrder, std::vector<int>& vinOrder) {
        int preStart = 0, preEnd = preOrder.size() - 1;
        int vinStart = 0, vinEnd = vinOrder.size() - 1;
        if (preOrder.size() == 0 || vinOrder.size() == 0) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preOrder[preStart]);
        int root_index = 0;
        for (int i = vinStart; i <= vinEnd; i++) {
            if (vinOrder[i] == root->val) {
                root_index = i;
                break;
            }
        }
        int left_subtree_size = root_index - vinStart;
        int right_subtree_size = vinEnd - root_index;
        if (left_subtree_size > 0) {
            std::vector<int>preLeft(preOrder.begin()+1,preOrder.begin()+left_subtree_size+1);
            std::vector<int>vinLeft(vinOrder.begin(),vinOrder.begin()+left_subtree_size);
            root->left=reConstructBinaryTree(preLeft, vinLeft);
        } else {
            root->left = nullptr;
        }
        if (right_subtree_size > 0) {
            std::vector<int>preRight(preOrder.begin()+left_subtree_size+1,preOrder.end());
            std::vector<int>vinRight(vinOrder.begin()+left_subtree_size+1,vinOrder.end());
            root->right=reConstructBinaryTree(preRight, vinRight);
        } else {
            root->right = nullptr;
        }
        return root;
    }
};

void printTree(TreeNode* root){
    if(root){
        std::cout<<root->val<<" ";
        printTree(root->left);
        printTree(root->right);
    }
}


int main(){
    std::vector<int>preOrder = {1,2,4,7,3,5,6,8};
    std::vector<int>vinOrder = {4,7,2,1,5,3,8,6};
    Solution solution;
    TreeNode* reconstructTree = solution.reConstructBinaryTree(preOrder,vinOrder);
    printTree(reconstructTree);
    std::cout<<std::endl;
    return 0;
}