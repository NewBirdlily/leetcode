#include<iostream>
#include<string>
#include<vector>

class Solution{
    public:
    std::string LCS(std::string str1, std::string str2) {
        int m = str1.size();
        int n = str2.size();
        std::vector<std::vector<int>>dp(m + 1, std::vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        int max_length = 0;
        int end_index = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (dp[i][j] > max_length) {
                    max_length = dp[i][j];
                    end_index = i - 1;
                }
            }
        }
        return str1.substr(end_index - max_length + 1, max_length);
    }
};

int main(){
    std::string str1="1AB2345CD";
    std::string str2="12345EF";
    Solution solution;
    std::cout<<"\""<<solution.LCS(str1,str2)<<"\""<<std::endl;
    return 0;
}