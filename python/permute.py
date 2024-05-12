class Solution:
    def permute(self , num: list[int]) -> list[list[int]]:
        result=[]
        path=[]
        used=[False] * len(num)
        self.backtrack(num,used,path,result)
        return result
    def backtrack(self,num:list[int],used:list[int],path:list[int],result:list[int]):
        if len(path)==len(num):
            result.append(path[:])
            return
        for i in range(len(num)):
            if not used[i]:
                path.append(num[i])
                used[i]=True
                self.backtrack(num,used,path,result)
                path.pop()
                used[i]=False

num=[1,2,3]
s=Solution()
print(s.permute(num))