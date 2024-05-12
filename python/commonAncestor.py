class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def lowestCommonAncestor(self , root: TreeNode, o1: int, o2: int) -> int:
        if not root:
            return -1
        if o1==root.val or o2 == root.val:
            return root.val
        left =self.lowestCommonAncestor(root.left,o1,o2)
        right =self.lowestCommonAncestor(root.right,o1,o2)
        if left ==-1:
            return right
        if right ==-1:
            return left
        return root.val
    
root=TreeNode(3)
root.left=TreeNode(5)
root.right=TreeNode(1)
root.left.left=TreeNode(6)
root.left.right=TreeNode(2)
root.right.left=TreeNode(0)
root.right.right=TreeNode(8)
root.left.right.left=TreeNode(7)
root.left.right.right=TreeNode(4)
o1=6
o2=7
solution=Solution()
common_ancestor=solution.lowestCommonAncestor(root,o1,o2)
print(common_ancestor)