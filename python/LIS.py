class Solution:
    def LIS(self , arr: list[int]) -> int:
        n=len(arr)
        if n==0:
            return 0
        dp=[1]* n
        max_length=1
        for i in range(1,n):
            for j in range(0,i):
                if arr[j]<arr[i]:
                    dp[i]=max(dp[i],dp[j]+1)
            max_length=max(max_length,dp[i])
        return max_length
    
arr=[6,3,1,5,2,3,7]
s=Solution()
print(s.LIS(arr))