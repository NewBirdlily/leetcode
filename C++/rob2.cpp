#include<iostream>
#include<vector>
#include<algorithm>

class Solution{
    public:
    int rob(std::vector<int>& nums) {
        int n = nums.size();
        int a = 0, b = nums[0];
        for (int i = 2; i < n; i++) {
            int c = std::max(b, a + nums[i - 1]);
            a = b;
            b = c;
        }
        int res = b;
        
        a = 0, b = 0;
        for (int i = 2; i <= n; i++) {
            int c = std::max(b, a + nums[i - 1]);
            a = b;
            b = c;
        }      
        return std::max(res, b);
    }
};

int main(){
    std::vector<int>nums={1,2,3,4};
    Solution solution;
    std::cout<<solution.rob(nums)<<std::endl;
    return 0;
}