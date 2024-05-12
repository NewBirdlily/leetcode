class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def postorderTraversal(self , root: TreeNode) -> list[int]:
        # write code here
        v=[]
        def postorder(root):
            if not root:
                return None
            if root:
                postorder(root.left)
                postorder(root.right)
                v.append(root.val)
        postorder(root)
        return v

root=TreeNode(1)
root.right=TreeNode(2)
root.right.left=TreeNode(3)
solution=Solution()
postorder=solution.postorderTraversal(root)
print(postorder)