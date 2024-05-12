class Solution:
    def judge(self , str: str) -> bool:
        left=0
        right=len(str)-1
        while left<right:
            if str[left] !=str[right]:
                return False
            left +=1
            right -=1
        return True
    
s1="yamatomaya"
s=Solution()
print(s.judge(s1))