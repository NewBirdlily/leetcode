from typing import List

class Solution:
    def permuteUnique(self, num: List[int]) -> List[List[int]]:
        result = []
        path = []
        used = [False] * len(num)
        num.sort()
        self.backtrack(num, used, path, result)
        return result
    
    def backtrack(self, num: List[int], used: List[bool], path: List[int], result: List[int]):
        if len(path) == len(num):
            result.append(path[:])
            return
        for i in range(len(num)):
            if used[i] or (i > 0 and num[i] == num[i - 1] and used[i - 1]):
                continue
            path.append(num[i])
            used[i] = True
            self.backtrack(num, used, path, result)
            path.pop()
            used[i] = False

num=[1,2,1]
s=Solution()
print(s.permuteUnique(num))