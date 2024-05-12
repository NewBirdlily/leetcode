class Solution:
    def solve(self, str: str) -> str:
        str_list = list(str)
        n = len(str_list)
        left = 0
        right = n - 1
        while left < right:
            str_list[left], str_list[right] = str_list[right], str_list[left]
            left += 1
            right -= 1
        return "".join(str_list)

s1="abcd"
s=Solution()
print(s.solve(s1))