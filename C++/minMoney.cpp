#include<iostream>
#include<vector>
#include<algorithm>

class Solution{
    public:
    int minMoney(std::vector<int>& arr, int aim) {
        if (aim == 0) return 0;
        std::vector<int> dp(aim + 1, aim + 1);
        dp[0] = 0; 
        for (int j = 1; j <= aim; j++) {
            for (int i = 0; i < arr.size(); i++) {
                if (arr[i] <= j) {
                    dp[j] = std::min(dp[j], dp[j - arr[i]] + 1);
                }
            }
        }
        return dp[aim] == aim + 1 ? -1 : dp[aim];
    }
};

int main(){
    std::vector<int>arr={5,2,3};
    int aim=20;
    Solution solution;
    std::cout<<solution.minMoney(arr,aim)<<std::endl;
    return 0;
}
