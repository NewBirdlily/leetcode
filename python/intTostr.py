class Solution:
    def solve(self , nums: str) -> int:
        n = len(nums)
        if n == 0 or nums[0] == "0":
            return 0
        dp = [0] * (n + 1)
        dp[0] = 1
        dp[1] = 1
        for i in range(2, n+1):
            if nums[i - 1] != "0":
                dp[i] += dp[i - 1]
            if nums[i - 2] == "1" or (nums[i - 2] == "2" and nums[i - 1] <= "6"):
                dp[i] += dp[i - 2]
        return dp[n]

nums="31717126241541717"
s=Solution()
print(s.solve(nums))