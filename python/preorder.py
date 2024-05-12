class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def preorderTraversal(self , root: TreeNode) -> list[int]:
        v = []
        def preorder(root):
            if not root:
                return None
            v.append(root.val)
            preorder(root.left)
            preorder(root.right)
        preorder(root)
        return v
    
root=TreeNode(1)
root.right=TreeNode(2)
root.right.left=TreeNode(3)
solution = Solution()
preorder=solution.preorderTraversal(root)
print(preorder)
    