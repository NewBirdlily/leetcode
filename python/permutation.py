class Solution:
    def Permutation(self, str: str) -> list[str]:
        result = []
        if not str:
            return result

        str = sorted(str)  
        visited = [False] * len(str)  
        self.dfs(str, visited, "", result)
        return result

    def dfs(self, str: str, visited: list[bool], path: str, result: list[str]):
        if len(path) == len(str):
            result.append(path)
            return
        for i in range(len(str)):
            if visited[i] or (i > 0 and str[i] == str[i - 1] and not visited[i - 1]):
                continue
            visited[i] = True
            self.dfs(str, visited, path + str[i], result)
            visited[i] = False

s1="aab"
s2="abc"
s=Solution()
print(s.Permutation(s1))
print(s.Permutation(s2))