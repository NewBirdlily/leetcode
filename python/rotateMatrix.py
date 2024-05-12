class Solution:
    def rotateMatrix(self , mat: list[list[int]], n: int) -> list[list[int]]:
        for i in range(n):
            for j in range(i,n):
                mat[i][j],mat[j][i] = mat[j][i],mat[i][j]
        for i in range(n):
            for j in range (n//2):
                mat[i][j],mat[i][n-1-j]= mat[i][n-1-j],mat[i][j]
        return mat
    
mat=[[1,2,3],[4,5,6],[7,8,9]]
n=3
s=Solution()
print(s.rotateMatrix(mat,n))