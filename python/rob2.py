class Solution:
    def rob(self , nums: list[int]) -> int:
        n=len(nums)
        a=0
        b=nums[0]
        for i in range(2,n):
            c=max(b,a+nums[i-1])
            a=b
            b=c
        res=b
        a=0
        b=0
        for i in range(2,n+1):
            c=max(b,a+nums[i-1])
            a=b
            b=c
        return max(res,b)

nums=[1,2,3,4]
s=Solution()
print(s.rob(nums))