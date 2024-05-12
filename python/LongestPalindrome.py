class Solution:
    def getLongestPalindrome(self , A: str) -> int:
        n=len(A)
        if n==0:
            return 0
        dp=[[False]*n for _ in range(n)]
        
        for i in range(n):
            dp[i][i]=True
        max_length=1

        for i in range(n-1):
            if A[i]==A[i+1]:
                dp[i][i+1]=True
                max_length=2
        
        for length in range(3,n+1):
            for i in range(0,n-length+1):
                j=i+length-1
                if A[i]==A[j] and dp[i+1][j-1]:
                    dp[i][j]=True
                    max_length=length
        return max_length

A="ababc"
s=Solution()
print(s.getLongestPalindrome(A))