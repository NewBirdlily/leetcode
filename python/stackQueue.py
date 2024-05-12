class Solution:
    def __init__(self):
        self.stack1 = []
        self.stack2 = []
    def push(self, node):
        self.stack1.append(node)
    def pop(self):
        if not self.stack1 and not self.stack2:
            return -1        
        if not self.stack2:
            while self.stack1:
                s1 = self.stack1.pop()
                self.stack2.append(s1)
        s2 = self.stack2.pop()
        return s2
solution=Solution()
solution.push(1)
solution.push(2)
print(solution.pop())
print(solution.pop())