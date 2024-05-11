#include<iostream>
#include<vector>

struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution{
    public:
    std::vector<int> solve(std::vector<int>& preOrder, std::vector<int>& inOrder) {
        std::vector<int> res;
        TreeNode* root = reConstructBinaryTree(preOrder, inOrder);
        findRightView(root, res, 0);
        return res;
    }

    void findRightView(TreeNode* root, std::vector<int>& res, int depth) {
        if (root == nullptr) {
            return;
        }
        if (depth >= res.size()) {
            res.push_back(root->val);
        }
        findRightView(root->right, res, depth + 1);
        findRightView(root->left, res, depth + 1);
    }

    TreeNode* reConstructBinaryTree(std::vector<int>& preOrder, std::vector<int>& inOrder) {
        int preStart = 0, preEnd = preOrder.size() - 1;
        int vinStart = 0, vinEnd = inOrder.size() - 1;
        if (preOrder.size() == 0 || inOrder.size() == 0) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preOrder[preStart]);
        int root_index = 0;
        for (int i = vinStart; i <= vinEnd; i++) {
            if (inOrder[i] == root->val) {
                root_index = i;
                break;
            }
        }
        int left_subtree_size = root_index - vinStart;
        int right_subtree_size = vinEnd - root_index;
        if (left_subtree_size > 0) {
            std::vector<int>preLeft(preOrder.begin() + 1,
                            preOrder.begin() + left_subtree_size + 1);
            std::vector<int>vinLeft(inOrder.begin(), inOrder.begin() + left_subtree_size);
            root->left = reConstructBinaryTree(preLeft, vinLeft);
        } else {
            root->left = nullptr;
        }
        if (right_subtree_size > 0) {
            std::vector<int>preRight(preOrder.begin() + left_subtree_size + 1, preOrder.end());
            std::vector<int>vinRight(inOrder.begin() + left_subtree_size + 1, inOrder.end());
            root->right = reConstructBinaryTree(preRight, vinRight);
        } else {
            root->right = nullptr;
        }
        return root;
    }
};

int main(){
    std::vector<int>preOrder = {1,2,4,5,3};
    std::vector<int>inOrder = {4,2,5,1,3};
    Solution solution;
    TreeNode* reConstructBinaryTree=solution.reConstructBinaryTree(preOrder,inOrder);
    std::vector<int>rightView=solution.solve(preOrder,inOrder);
    std::cout<<"Find right view:";
    for(int val: rightView){
        std::cout<<" "<<val;
    }
    std::cout<<std::endl;
    return 0;
}
