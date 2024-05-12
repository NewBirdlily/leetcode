class Solution:
    def solve(self, matrix: list[list[int]]) -> int:
        if not matrix:
            return 0
        m = len(matrix)
        n = len(matrix[0])
        dp = [[0] * n for _ in range(m)]
        maxLength = 1
        for i in range(m):
            for j in range(n):
                self.dfs(matrix, dp, i, j)
                maxLength = max(maxLength, dp[i][j])
        return maxLength

    def dfs(self, matrix: list[list[int]], dp: list[list[int]], i: int, j: int):
        if dp[i][j] != 0:
            return
        dirs = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        maxLength = 1
        for dir in dirs:
            x = i + dir[0]
            y = j + dir[1]
            if  0 <= x < len(matrix) and 0 <= y < len(matrix[0]) and matrix[x][y] > matrix[i][j]:
                self.dfs(matrix, dp, x, y)
                maxLength = max(maxLength, dp[x][y] + 1)
        dp[i][j] = maxLength
        
mat=[[1,2,3],[4,5,6],[7,8,9]]
s=Solution()
print(s.solve(mat))
