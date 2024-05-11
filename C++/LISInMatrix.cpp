#include<iostream>
#include<vector>
#include<algorithm>

class Solution{
    public:
    void dfs(std::vector<std::vector<int>>& matrix, std::vector<std::vector<int>>& dp, int i, int j) {
        if (dp[i][j] != 0) {return;}
        int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int maxLength = 1;
        for (auto& dir : dirs) { 
            int x = i + dir[0]; 
            int y = j + dir[1];
            if (x >= 0 && x < matrix.size() && y >= 0 && y < matrix[0].size() && matrix[x][y] > matrix[i][j]) {
                dfs(matrix, dp, x, y); 
                maxLength = std::max(maxLength,dp[x][y] + 1); 
            }
        }
        dp[i][j] = maxLength;
    }

    int solve(std::vector<std::vector<int>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
        int maxLength = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(matrix, dp, i, j); 
                maxLength = std::max(maxLength,dp[i][j]); 
            }
        }
        return maxLength;
    }
};

int main(){
    std::vector<std::vector<int>>matrix={{1,2,3},{4,5,6},{7,8,9}};
    Solution solution;
    std::cout<<solution.solve(matrix)<<std::endl;
    return 0;
}