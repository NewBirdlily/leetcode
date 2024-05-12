class Solution:
    def minNumberInRotateArray(self , nums: list[int]) -> int:
        if len(nums) == 0:
            return -1  
        
        begin = 0
        end = len(nums) - 1
        
        while begin < end:
            mid = begin + ((end - begin) >> 1)
            
            if nums[mid] < nums[end]: 
                end = mid
            elif nums[mid] > nums[end]:  
                begin = mid + 1
            else:  
                end -= 1
        
        return nums[begin]

nums=[3,4,5,1,2]
solution=Solution()
print("The min Number in the Rotate Array is:",solution.minNumberInRotateArray(nums))