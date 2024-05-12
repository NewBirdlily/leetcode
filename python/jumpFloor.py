class Solution:
    def jumpFloor(self , number: int) -> int:
        if number==1:
            return 1
        if number==2:
            return 2
        a=1
        b=2
        for i in range(3,number+1):
            c=a+b
            a=b
            b=c
        return b
n =40
s=Solution()
print(s.jumpFloor(n))