class Solution:
    def compare(self , version1: str, version2: str) -> int:
        v1 = len(version1)
        v2 = len(version2)
        i = 0
        j = 0
        while i < v1 or j < v2:
            num1 = 0
            num2 = 0
            while i < v1 and version1[i] != '.':
                num1 = num1 * 10 + int(version1[i])
                i += 1
            while j < v2 and version2[j] != '.':
                num2 = num2 * 10 + int(version2[j])
                j += 1
            if num1 < num2:
                return -1
            if num1 > num2:
                return 1
            if i < v1:
                i += 1
            if j < v2:
                j += 1
        return 0
    
version1="1.1"
version2="1.01"
solution=Solution()
print(solution.compare(version1,version2))