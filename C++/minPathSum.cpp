#include<iostream>
#include<vector>
#include<algorithm>

class Solution{
    public:
    int minPathSum(std::vector<std::vector<int> >& matrix) {
        int m =matrix.size();
        int n =matrix[0].size();

        std::vector<std::vector<int>>dp(m,std::vector<int>(n,0));
        dp[0][0]=matrix[0][0];
        for(int i =1;i<m;i++){
            dp[i][0]=dp[i-1][0]+matrix[i][0];
        }
        for(int j=1;j<n;j++){
            dp[0][j]=dp[0][j-1]+matrix[0][j];
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=std::min(dp[i-1][j],dp[i][j-1])+matrix[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};

int main(){
    std::vector<std::vector<int>>matrix={{1,3,5,9},{8,1,3,4},{5,0,6,1},{8,8,4,0}};
    Solution solution;
    std::cout<<solution.minPathSum(matrix)<<std::endl;
    return 0;
}