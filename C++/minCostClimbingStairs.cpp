#include<iostream>
#include<vector>
#include<algorithm>

class Solution{
    public:
    int minCostClimbingStairs(std::vector<int>& cost) {
        int n = cost.size();
        std::vector<int> dp(n + 1);
        for (int i = 2; i <= n; ++i) {
            dp[i] = std::min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        return dp[n];
    }
};

int main(){
    std::vector<int>cost={1,100,1,1,1,90,1,1,80,1};
    Solution solution;
    std::cout<<solution.minCostClimbingStairs(cost)<<std::endl;
    return 0;
}