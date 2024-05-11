#include<iostream>
#include<vector>
#include<algorithm>

class Solution{
    public:
    int LIS(std::vector<int>& arr) {
        int n =arr.size();
        if(n==0){return 0;}
        std::vector<int>dp(n,1);
        int maxLength =1;
        for(int i =1;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[j]<arr[i]){
                    dp[i]=std::max(dp[j]+1,dp[i]);
                }
            }
            maxLength = std::max(maxLength, dp[i]);
        }
        return maxLength;
    }
};

int main(){
    std::vector<int>arr={6,3,1,5,2,3,7};
    Solution solution;
    std::cout<<solution.LIS(arr)<<std::endl;
    return 0;
}