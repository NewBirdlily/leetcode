class Solution:
    def editDistance(self , str1: str, str2: str) -> int:
        m =len(str1)
        n =len(str2)
        dp =[[0]*(n+1) for _ in range(m+1)]
        for i in range(m+1):
            dp[i][0]=i
        for j in range(n+1):
            dp[0][j]=j
        for i in range(1,m+1):
            for j in range(1,n+1):
                if str1[i-1]==str2[j-1]:
                    dp[i][j]=dp[i-1][j-1]
                else:
                    dp[i][j]=1+min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])
        return dp[m][n]

s1="intention"
s2="execution"
s=Solution()
print(s.editDistance(s1,s2))
