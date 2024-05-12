class Solution:
    def minNumberDisappeared(self , nums: list[int]) -> int:
        n = len(nums)
        
        for i in range(n):
            if nums[i] <= 0 or nums[i] > n:
                nums[i] = n + 1

        for i in range(n):
            num = abs(nums[i])
            if num > n:
                continue
            idx = num - 1
            if nums[idx] > 0:
                nums[idx] = -nums[idx]

        for i in range(n):
            if nums[i] > 0:
                return i + 1

        return n + 1

nums=[-2,3,4,1,5]
s=Solution()
print(s.minNumberDisappeared(nums))
