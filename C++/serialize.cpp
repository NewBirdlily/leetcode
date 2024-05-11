#include <iostream>
#include <string>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    std::string Serialize(TreeNode* root) {
        std::string serialized;
        serialize(root, serialized);
        return serialized;
    }

    TreeNode* Deserialize(const std::string& str) {
        int index = 0;
        return deserialize(str, index);
    }

private:
    void serialize(TreeNode* node, std::string& result) {
        if (!node) {
            result += "#,";
            return;
        }
        result += std::to_string(node->val) + ",";
        serialize(node->left, result);
        serialize(node->right, result);
    }

    TreeNode* deserialize(const std::string& str, int& index) {
        if (index >= str.length() || str[index] == ',' || str[index] == '#') {
            index++;
            return nullptr;
        }
        TreeNode* node = new TreeNode(std::stoi(str.substr(index, str.find(',', index) - index)));
        index = str.find(',', index) + 1; 
        node->left = deserialize(str, index);
        node->right = deserialize(str, index);
        return node;
    }
};

void deleteTree(TreeNode* root) {
    if (root) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution solution;
    std::string serializeroot = solution.Serialize(root);
    std::cout << serializeroot << std::endl;

    TreeNode* deserializedRoot = solution.Deserialize(serializeroot);

    deleteTree(root);
    deleteTree(deserializedRoot);

    return 0;
}