class Solution:
    def LCS(self , s1: str, s2: str) -> str:
        m= len(s1)
        n= len(s2)
        dp= [[0] * (n + 1) for _ in range(m + 1)]
        for i in range(1,m+1):
            for j in range(1,n+1):
                if s1[i-1]==s2[j-1]:
                    dp[i][j]=dp[i-1][j-1]+1
                else:
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1])
        i=m
        j=n
        result=""
        while i>0 and j>0:
            if s1[i-1]==s2[j-1]:
                result =s1[i-1]+result
                i -=1
                j -=1
            else:
                if dp[i][j-1]>dp[i-1][j]:
                    j -=1
                else:
                    i -=1
        if not result:
            return "-1"
        return result
    
s1="1A2C3D4B56"
s2="B1D23A456A"
s=Solution()
print(s.LCS(s1,s2))
