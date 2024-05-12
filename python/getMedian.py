class Solution:
    def __init__(self) -> None:
        self.nums=[]
    def Insert(self, num):
        self.nums.append(num)
    def GetMedian(self):
        n=len(self.nums)
        if n%2 !=0:
            self.nums.sort()
            return self.nums[n//2]
        else:
            self.nums.sort()
            return (self.nums[n//2]+self.nums[n//2-1])/2.0

nums=[5,2,3,4,1,6,7,0,8]
s=Solution()
for num in nums:
    s.Insert(num)
    print(s.GetMedian(),end=' ')
print()
