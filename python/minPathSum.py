class Solution:
    def minPathSum(self , matrix: list[list[int]]) -> int:
        m=len(matrix)
        n=len(matrix[0])
        dp=[[0]*n for _ in range(m)]
        dp[0][0]=matrix[0][0]
        for i in range(1,m):
            dp[i][0]=dp[i-1][0]+matrix[i][0]
        for j in range(1,n):
            dp[0][j]=dp[0][j-1]+matrix[0][j]
        for i in range(1,m):
            for j in range(1,n):
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+matrix[i][j]
        return dp[m-1][n-1]

mat=[[1,3,5,9],[8,1,3,4],[5,0,6,1],[8,8,4,0]]
s=Solution()
print(s.minPathSum(mat))