class Solution:
    def GetLeastNumbers_Solution(self , input: list[int], k: int) -> list[int]:
        sorted_input = sorted(input) 
        return sorted_input[:k] 

input=[4,5,1,6,2,7,3,8]
k=4
s=Solution()
print(s.GetLeastNumbers_Solution(input,k))