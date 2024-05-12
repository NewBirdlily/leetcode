class Solution:
    def solve(self , n: int, m: int, a: list[int]) -> list[int]:
        m=m%n
        a.reverse()
        a[:m]=reversed(a[:m])
        a[m:]=reversed(a[m:])
        return a

a=[1,2,3,4,5,6]
n=6
m=2
s=Solution()
print(s.solve(n,m,a))