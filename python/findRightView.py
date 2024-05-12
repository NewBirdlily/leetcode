class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def solve(self , preOrder: list[int], inOrder: list[int]) -> list[int]:
        res=[]
        root =self.reConstructBinaryTree(preOrder,inOrder)
        self.findRightView(root,res,0)
        return res

    def findRightView(self,root,res,depth):
        if not root:
            return None
        if depth>=len(res):
            res.append(root.val)
        self.findRightView(root.right,res,depth+1)
        self.findRightView(root.left,res,depth+1)
        
    def reConstructBinaryTree(self , preOrder: list[int], inOrder: list[int]) -> TreeNode:
        if len(preOrder)==0 or len(inOrder)==0:
            return None
        pre_start=0
        pre_end=len(preOrder)-1
        vin_start=0
        vin_end=len(inOrder)-1
        root=TreeNode(preOrder[pre_start])
        root_index=0
        for i in range(0,vin_end+1):
            if root.val==inOrder[i]:
                root_index=i
                break
        left_subtree_length=root_index-vin_start
        right_subtree_length=vin_end-root_index
        if left_subtree_length>0:
            pre_left=preOrder[1:left_subtree_length+1]
            vin_left=inOrder[0:left_subtree_length]
            root.left=self.reConstructBinaryTree(pre_left,vin_left)
        else:
            root.left=None
        if right_subtree_length>0:
            pre_right=preOrder[left_subtree_length+1:]
            vin_right=inOrder[left_subtree_length+1:]
            root.right=self.reConstructBinaryTree(pre_right,vin_right)
        else:
            root.right=None
        return root
    
preorder=[1,2,4,5,3]
inorder=[4,2,5,1,3]
solution=Solution()
right_view=solution.solve(preorder,inorder)
print(right_view)