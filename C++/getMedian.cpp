#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

class Solution {
  public:
    std::vector<int> v;

    void Insert(int num) {
        v.push_back(num);
        // 插入元素后，立即计算并打印当前中位数
        std::cout << GetMedian() << " ";
    }

    double GetMedian() {
        int n = v.size();
        if (n == 0) {
            return 0.0;
        }
        // 只有当数组大小为奇数时，才需要排序整个数组来找到中位数
        if (n % 2 != 0) {
            std::sort(v.begin(), v.end());
            return static_cast<double>(v[n / 2]);
        }
        // 否则，只需要找到中间两个数的平均值
        std::sort(v.begin(), v.end());
        return (static_cast<double>(v[(n - 1) / 2]) + static_cast<double>(v[n / 2])) / 2.0;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {5, 2, 3, 4, 1, 6, 7, 0, 8};
    for (int num : nums) {
        solution.Insert(num);
    }
    return 0;
}