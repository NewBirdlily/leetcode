class Solution:
    def solve(self , grid: list[list[str]]) -> int:
        if not grid:
            return 0
        numIslands =0
        rows = len(grid)
        cols=len(grid[0])
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] ==1:
                    numIslands +=1
                    self.dfs(grid,i,j)
        return numIslands
    
    def dfs(self,grid:list[list[str]],i:int,j:int):
        rows = len(grid)
        cols=len(grid[0])
        if i<0 or i >= rows or j<0 or j>=cols or grid[i][j]==0:
            return
        grid[i][j]=0
        self.dfs(grid,i-1,j)
        self.dfs(grid,i+1,j)
        self.dfs(grid,i,j-1)
        self.dfs(grid,i,j+1)
        
grid=[[1,1,0,0,0],[0,1,0,1,1],[0,0,0,1,1],[0,0,0,0,0],[0,0,1,1,1]]
s=Solution()
print(s.solve(grid))