#include<iostream>
#include<vector>
#include<algorithm>

class Solution{
    public:
    int rob(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int>dp(n,0);
        dp[0]=0;
        dp[1]=nums[0];
        for(int i =2;i<=n;i++){
            dp[i]=std::max(dp[i-1],dp[i-2]+nums[i-1]);
        }
        return dp[n];
    }
};

int main(){
    std::vector<int> nums={1,2,3,4};
    Solution solution;
    std::cout<<solution.rob(nums)<<std::endl;
    return 0;
}