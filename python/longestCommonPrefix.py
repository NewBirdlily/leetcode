class Solution:
    def longestCommonPrefix(self , strs: list[str]) -> str:
        n=len(strs)
        if n==0:
            return ""
        common_prefix=strs[0]
        for i in range(1,n):
            size=0
            while size<len(common_prefix) and size<len(strs[i]) and common_prefix[size] == strs[i][size]:
                size +=1
            common_prefix=common_prefix[:size]
        return common_prefix
        
s1=["abca","abc","abca","abc","abcc"]
s=Solution()
print(s.longestCommonPrefix(s1))