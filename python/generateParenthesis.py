class Solution:
    def generateParenthesis(self , n: int) -> list[str]:
        if n==0:
            return []
        result=[]
        self.generate("",n,n,result)
        return result
    def generate(self,s:str,left:int,right:int,result:list[str]):
        if left==0 and right ==0:
            result.append(s)
            return
        if left>0:
            self.generate(s + "(",left-1,right,result)
        if right>left:
            self.generate(s +")",left,right-1,result)
    
n1=2
n2=4
s=Solution()
print(s.generateParenthesis(n1))
print(s.generateParenthesis(n2))