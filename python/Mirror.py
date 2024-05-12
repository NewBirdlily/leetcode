class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
        
class Solution:
    def Mirror(self , pRoot: TreeNode) -> TreeNode:
        if not pRoot:
            return None 
        tmp=TreeNode(0)
        tmp = pRoot.left
        pRoot.left=pRoot.right
        pRoot.right=tmp  
        self.Mirror(pRoot.left)
        self.Mirror(pRoot.right)    
        return pRoot
 
    def printTree(self,root:TreeNode):
        if root is None:
            return 
        print(root.val,end=' ')
        self.printTree(root.left)
        self.printTree(root.right)
    
root=TreeNode(8)
root.left=TreeNode(6)
root.right=TreeNode(10)
root.left.left=TreeNode(5)
root.left.right=TreeNode(7)
root.right.left=TreeNode(9)
root.right.right=TreeNode(11)
solution=Solution()
mirror_root=solution.Mirror(root)
solution.printTree(mirror_root)
print()
