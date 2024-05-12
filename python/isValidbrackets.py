class Solution:
    def isValid(self , s: str) -> bool:
        st =[]
        mapping={')':'(','}':'{',']':'['}
        for c in s :
            if c in mapping:
                if not st or st[-1] !=mapping[c]:
                    return False
                st.pop()
            else:
                st.append(c)
        return  not st

s1="["
s2="[]"
s=Solution()
print(s.isValid(s1))
print(s.isValid(s2))