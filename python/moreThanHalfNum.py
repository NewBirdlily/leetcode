class Solution:
    def MoreThanHalfNum_Solution(self , numbers: list[int]) -> int:
        numbers.sort()
        return(numbers[len(numbers)//2])
    
nums=[1,2,3,2,2,2,5,4,2]
s=Solution()
print(s.MoreThanHalfNum_Solution(nums))