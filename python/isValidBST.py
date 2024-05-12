class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def isValidBST(self , root: TreeNode) -> bool:
        v = self.inorderTraversal(root)
        for i in range(1, len(v)):
            if v[i - 1] >= v[i]:
                return False
        return True

    def inorderTraversal(self, root: TreeNode) -> list[int]:
        v = []

        def inorder(node):
            if node is None:
                return
            inorder(node.left)
            v.append(node.val)
            inorder(node.right)

        inorder(root)
        return v

root1=TreeNode(1)
root1.left=TreeNode(2)
root1.right=TreeNode(3)

root2=TreeNode(2)
root2.left=TreeNode(1)
root2.right=TreeNode(3)

solution=Solution()
list1=solution.isValidBST(root1)
list2=solution.isValidBST(root2)

print(list1)
print(list2)