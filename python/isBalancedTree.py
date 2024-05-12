class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def IsBalanced_Solution(self , pRoot: TreeNode) -> bool:
        if not pRoot:
            return True
        left=self.depth(pRoot.left)
        right=self.depth(pRoot.right)
        if abs(left-right)>1:
            return False
        return self.IsBalanced_Solution(pRoot.left) and self.IsBalanced_Solution(pRoot.right)
    def depth(self,root:TreeNode) ->int:
        if not root:
            return 0
        return max(self.depth(root.left),self.depth(root.right))+1

root=TreeNode(1)
root.left=TreeNode(2)
root.right=TreeNode(5)
root.left.left=TreeNode(3)
root.left.right=TreeNode(4)
solution=Solution()
pRoot=solution.IsBalanced_Solution(root)
print(pRoot)