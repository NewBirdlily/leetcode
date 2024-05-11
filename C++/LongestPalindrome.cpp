#include<iostream>
#include<string>
#include<vector>

class Solution{
    public:
    int getLongestPalindrome(std::string A) {
        int n = A.size();
        if(n==0){return 0;}
        std::vector<std::vector<bool>>dp(n,std::vector<bool>(n,false));
        for(int i =0;i<n;i++){
            dp[i][i]=true;
        }
        int maxLength =1;
        for(int i =0;i<n-1;i++){
            if(A[i]==A[i+1]){
                dp[i][i+1]=true;
                maxLength=2;
            }
        }
        for(int length =3;length<=n;length++){
            for(int i =0;i<=n-length;i++){
                int j=i+length-1;
                if(A[i]==A[j] && dp[i+1][j-1]){
                    dp[i][j]=true;
                    maxLength=length;
                }
            }
        }
        return maxLength;
    }
};

int main(){
    std::string A="abbba";
    Solution solution;
    std::cout<<solution.getLongestPalindrome(A)<<std::endl;
    return 0;
}