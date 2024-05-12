class Solution:
    def minMoney(self, arr: list[int], aim: int) -> int:
        if aim == 0:
            return 0
        dp = [aim + 1] * (aim + 1)
        dp[0] = 0  
        for j in range(1, aim + 1):
            for i in range(len(arr)):
                if arr[i] <= j:
                    dp[j] = min(dp[j], dp[j - arr[i]] + 1)
        return dp[aim] if dp[aim] != aim + 1 else -1

nums=[5,2,3]
aim=20
s=Solution()
print(s.minMoney(nums,aim))