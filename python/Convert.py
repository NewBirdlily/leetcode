class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def Convert(self , pRootOfTree ):
        if not pRootOfTree:
            return None
        left=self.Convert(pRootOfTree.left)
        pre=left
        right=self.Convert(pRootOfTree.right)
        next=right
        if left:
            while pre.right:
                pre=pre.right
            pre.right=pRootOfTree
            pRootOfTree.left=pre
        if right:
            while next.left:
                next=next.left
            next.left=pRootOfTree
            pRootOfTree.right=next
        return left if left else pRootOfTree

def print_left_to_right_list(node):
    print("From left to right: ", end='')
    while node:
        print(node.val, end='')
        if node.right:
            print(',',end='')
        node = node.right
    print()

def print_right_to_left_list(node):
    print("From right to left: ", end='')
    while node:
        print(node.val, end='')
        if node.left:
            print(',',end='')
        node = node.left
    print()

root=TreeNode(10)
root.left=TreeNode(6)
root.right=TreeNode(14)
root.left.left=TreeNode(4)
root.left.right=TreeNode(8)
root.right.left=TreeNode(12)
root.right.right=TreeNode(16)
solution=Solution()
head=solution.Convert(root)
print_left_to_right_list(head)
tail=head
while tail.right:
    tail=tail.right
print_right_to_left_list(tail)