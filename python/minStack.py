class Solution:
    def __init__(self):
        self.stack1=[]
        self.Min=[]
    def push(self, node):
        self.stack1.append(node)
        if not self.Min or node <= self.Min[-1]:
            self.Min.append(node)

    def pop(self):
        if self.stack1.pop() == self.Min[-1]:
            self.Min.pop()

    def top(self):
        return self.stack1[-1]

    def min(self):
        return self.Min[-1]

s=Solution()
s.push(-1)
s.push(2)
print(s.min())
print(s.top())
print(s.pop())
s.push(1)
print(s.top())
print(s.min())