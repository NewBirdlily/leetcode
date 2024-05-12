class Solution:
    mod = 1000000007
    def InversePairs(self, nums: list[int]) -> int:
        n=len(nums)
        res = [0 for i in range(n)]
        return self.MergeSort(0,n-1,nums,res)
    def MergeSort(self,left:int,right:int,nums:list[int],temp:list[int])-> int:
        if left >=right:
            return 0
        mid= (left+right)//2
        res = self.MergeSort(left,mid,nums,temp) + self.MergeSort(mid+1,right,nums,temp)
        res %=self.mod
        i=left
        j=mid+1
        for k in range(left,right+1):
            temp[k]=nums[k]
        for k in range (left,right+1):
            if i == mid+1:
                nums[k]=temp[j]
                j +=1
            elif j==right +1 or temp[i]<=temp[j]:
                nums[k]=temp[i]
                i +=1
            else:
                nums[k]=temp[j]
                j +=1
                res +=mid-i+1
        return res % self.mod

nums=[1,2,3,4,5,6,7,0]
solution=Solution()
print(solution.InversePairs(nums))