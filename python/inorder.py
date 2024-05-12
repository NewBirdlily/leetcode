class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def inorderTraversal(self , root: TreeNode) -> list[int]:
        v=[]
        def inorder(root):
            if not root:
                return None
            if root:
                inorder(root.left)
                v.append(root.val)
                inorder(root.right)
        inorder(root)
        return v
    
root=TreeNode(1)
root.left=TreeNode(2)
root.left.right=TreeNode(3)
solution=Solution()
inorder=solution.inorderTraversal(root)
print(inorder)