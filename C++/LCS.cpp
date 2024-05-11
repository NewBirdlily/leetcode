#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

class Solution{
    public:
    std::string LCS(std::string s1, std::string s2) {
        int m = s1.size();
        int n = s2.size();
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        std::string result = "";
        int i = m, j = n;
        while (i > 0 && j > 0) {
            if (s1[i - 1] == s2[j - 1]) {
                result = s1[i - 1] + result;
                i--;
                j--;
            } else {
                if (dp[i - 1][j] > dp[i][j - 1]) {
                    i--;
                } else {
                    j--;
                }
            }
        }
        if(result.empty()) {return "-1";}
        return result;
    }
};

int main(){
    std::string str1="1A2C3D4B56";
    std::string str2="B1D23A456A";
    Solution solution;
    std::cout<<"\""<<solution.LCS(str1,str2)<<"\""<<std::endl;
    return 0;
}
