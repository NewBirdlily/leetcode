class Solution:
    def maxInWindows(self, num: list[int], size: int) -> list[int]:
        if size > len(num) or size == 0:
            return []

        result = []
        for i in range(len(num) - size + 1):
            windows = []
            for j in range(size):
                windows.append(num[i + j])
            result.append(max(windows))

        return result
    
num=[2,3,4,2,6,2,5,1]
size=3
s=Solution()
print(s.maxInWindows(num,size))