class Solution:
    def findPeakElement(self , nums: list[int]) -> int:
        begin = 0
        end = len(nums) - 1
        
        while begin < end:
            med = begin + (end - begin) // 2
            if nums[med] < nums[med + 1]:
                begin = med + 1
            else:
                end = med
        
        return begin
    
nums=[2,4,1,2,7,8,4]
solution=Solution()
print(solution.findPeakElement(nums))