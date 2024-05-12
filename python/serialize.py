import sys

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def serialize(self, root: TreeNode) -> str:
        self.s = ""
        self.SerializeFunction(root)
        return self.s

    def SerializeFunction(self, root: TreeNode):
        if not root:
            self.s += "#!"
            return
        self.s += str(root.val) + "!"
        self.SerializeFunction(root.left)
        self.SerializeFunction(root.right)

    def deserialize(self, s: str) -> TreeNode:
        self.s = s
        self.index = 0
        return self.DeserializeFunction()

    def DeserializeFunction(self) -> TreeNode:
        if self.index >= len(self.s) or self.s[self.index] == "#":
            self.index += 1
            return None
        val = 0
        while self.index < len(self.s) and self.s[self.index] != "!":
            val = val * 10 + int(self.s[self.index])
            self.index += 1
        node = TreeNode(val)
        node.left = self.DeserializeFunction()
        node.right = self.DeserializeFunction()
        return node

root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)
root.right.left = TreeNode(6)
root.right.right = TreeNode(7)

solution = Solution()
s1 = solution.serialize(root)
print(s1)

deserialized_root = solution.deserialize(s1)
print(deserialized_root.val)