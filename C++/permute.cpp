#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> path;
        std::vector<bool> used(nums.size(), false); 
        backtrack(nums, used, path, result);
        return result;
    }

    void backtrack(std::vector<int>& nums, std::vector<bool>& used, std::vector<int>& path,
                   std::vector<std::vector<int>>& result) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!used[i]) {
                path.push_back(nums[i]);
                used[i] = true;
                backtrack(nums, used, path, result);
                path.pop_back();
                used[i] = false;
            }
        }
    }
};

std::ostream& operator<<(std::ostream& os, const std::vector<int>& vec) {
    os << "(";
    for (size_t i = 0; i < vec.size(); ++i) {
        os << vec[i];
        if (i < vec.size() - 1) os << ", ";
    }
    os << ")";
    return os;
}

int main() {
    std::vector<int> nums = {1, 2, 3};
    Solution solution;
    std::vector<std::vector<int>> result = solution.permute(nums);
    for (const auto& res : result) {
        std::cout << res << " ";
    }
    std::cout << std::endl;

    return 0;
}