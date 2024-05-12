class Solution:
    def maxLength(self , arr: list[int]) -> int:
        n = len(arr)
        maxLength = 0
        left = 0
        last_seen = {}

        for right in range(n):
            if arr[right] in last_seen and last_seen[arr[right]] >= left:
                left = last_seen[arr[right]] + 1
            last_seen[arr[right]] = right
            maxLength = max(maxLength, right - left + 1)

        return maxLength

arr=[2,2,3,4,3]
s=Solution()
print(s.maxLength(arr))
    