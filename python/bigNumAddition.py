class Solution:
    def solve(self , s: str, t: str) -> str:
        if not s:
            return t
        if not t:
            return s
        carry=0
        s=s[::-1]
        t=t[::-1]
        res=[]
        for i in range(max(len(s),len(t))):
            digit_num=carry
            if i<len(s):
                digit_num +=int(s[i])
            if i<len(t):
                digit_num +=int(t[i])
            if digit_num>=10:
                carry=1
                res.append(str(digit_num-10))
            else:
                carry=0
                res.append(str(digit_num))
        if carry:
            res.append('1')
        res=''.join(res[::-1])
        return res

s="1582037822"
t="8380289287"
solution=Solution()
print(solution.solve(s,t))