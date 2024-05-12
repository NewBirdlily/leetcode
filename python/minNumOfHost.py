class Solution:
    def minmumNumberOfHost(self , n: int, startEnd: list[list[int]]) -> int:
        start=sorted([x[0] for x in startEnd])
        end=sorted([x[1] for x in startEnd])
        num=0
        j=0
        for i in range(n):
            if start[i]>=end[j]:
                j+=1
            else:
                num+=1
        return num
    
startEnd=[[1,3],[2,4]]
n=2
s=Solution()
print(s.minmumNumberOfHost(n,startEnd))