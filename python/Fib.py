class Solution:
    def Fibonacci(self , n: int) -> int:
        if n==1 or n==2:
            return 1
        a=1
        b=1
        for i in range(3,n+1):
            c=a+b
            a=b
            b=c
        return b

n=40
s=Solution()
print(s.Fibonacci(n))