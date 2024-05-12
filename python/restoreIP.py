class Solution:
     def restoreIpAddresses(self , s: str) -> list[str]:
        def dfs(s, cur ,ret):
            if not s:
                if len(cur) == 4:
                    ret.append(cur)
                return
            dfs(s[1:],cur+[s[0]],ret)
            if 10<=int(s[:2])<=99:
                dfs(s[2:],cur+[s[:2]],ret)
            if 100<=int(s[:3])<=255:
                dfs(s[3:],cur+[s[:3]],ret)
        ret = []
        dfs(s,[],ret)
        for i in range(len(ret)):
            ret[i] = ".".join(ret[i])
        return ret
    
s1="25525522135"
s=Solution()
print(s.restoreIpAddresses(s1))