#include<iostream>
#include<string>
#include<vector>

class Solution{
    public:
    int solve(std::string nums) {
        int n =nums.size();
        if(n==0 || nums[0]=='0'){return 0;}
        std::vector<int>dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            if(nums[i-1] !='0'){
                dp[i] +=dp[i-1];
            }
            if(nums[i-2]=='1'||(nums[i-2]=='2'&&nums[i-1]<='6')){
                dp[i] +=dp[i-2];
            }
        }
        return dp[n];
    }
};

int main(){
    std::string num1="31717126241541717";
    Solution solution;
    std::cout<<solution.solve(num1)<<std::endl;
    return 0;
}