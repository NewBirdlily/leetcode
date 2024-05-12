class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def mergeTrees(self, t1: TreeNode, t2: TreeNode) -> TreeNode:
        if not t1 and not t2:
            return None
        root = TreeNode(0)
        if t1 and t2:
            root.val = t1.val + t2.val
            root.left = self.mergeTrees(t1.left, t2.left)
            root.right = self.mergeTrees(t1.right, t2.right)
        elif t1:
            root = t1
            root.left = self.mergeTrees(t1.left, None)
            root.right = self.mergeTrees(t1.right, None)
        else:
            root = t2
            root.left = self.mergeTrees(None, t2.left)
            root.right = self.mergeTrees(None, t2.right)
        return root

    def printTree(self, root: TreeNode):
        if root is None:
            return
        print(root.val, end=' ')
        self.printTree(root.left)
        self.printTree(root.right)
        
t1 = TreeNode(1)
t1.left = TreeNode(3)
t1.right = TreeNode(2)
t1.left.left = TreeNode(5)

t2 = TreeNode(2)
t2.left = TreeNode(1)
t2.right = TreeNode(3)
t2.left.right = TreeNode(4)
t2.right.right = TreeNode(7)

solution = Solution()
merged_tree_root = solution.mergeTrees(t1, t2)

solution.printTree(merged_tree_root)