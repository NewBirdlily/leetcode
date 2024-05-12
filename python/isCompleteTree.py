class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
        
class Solution:
    def isCompleteTree(self , root: TreeNode) -> bool:
        if not root:
            return True
    
        q = [root]
        reached_end = False
        
        while q:
            node = q.pop(0)
            
            if not node:
                reached_end = True
                continue
            
            if reached_end:
                return False
            
            q.append(node.left)
            q.append(node.right)
        
        return True
    
root=TreeNode(1)
root.left=TreeNode(2)
root.right=TreeNode(3)
root.left.left=TreeNode(4)
root.left.right=TreeNode(5)
root.right.right=TreeNode(6)

solution=Solution()
print(solution.isCompleteTree(root))