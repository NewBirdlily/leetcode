class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def lowestCommonAncestor(self , root: TreeNode, p: int, q: int) -> int:
        while root:
            if p<root.val and q<root.val:
                root=root.left
            if p>root.val and q>root.val:
                root=root.right
            return root.val
        return 0
    
root=TreeNode(7)
root.left=TreeNode(1)
root.right=TreeNode(12)
root.left.left=TreeNode(0)
root.left.right=TreeNode(4)
root.right.left=TreeNode(11)
root.right.right=TreeNode(14)
root.left.right.left=TreeNode(3)
root.left.right.right=TreeNode(5)
p=3
q=11
solution=Solution()
common_ancestor=solution.lowestCommonAncestor(root,p,q)
print(common_ancestor)