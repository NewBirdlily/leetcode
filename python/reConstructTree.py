class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def reConstructBinaryTree(self, preOrder: list[int], inOrder: list[int]) -> TreeNode:
        if not preOrder or not inOrder or len(preOrder) != len(inOrder):
            return None

        self.preIndex = 0
        return self._reConstructBinaryTree(preOrder, inOrder, 0, len(inOrder))

    def _reConstructBinaryTree(self, preOrder, inOrder, inOrder_start, inOrder_end):
        if inOrder_start >= inOrder_end:
            return None

        root_val = preOrder[self.preIndex]
        self.preIndex += 1
        root = TreeNode(root_val)
        root_index = inOrder.index(root_val)

        root.left = self._reConstructBinaryTree(preOrder, inOrder, inOrder_start, root_index)
        root.right = self._reConstructBinaryTree(preOrder, inOrder, root_index + 1, inOrder_end)

        return root

    def serialize(self, root: TreeNode) -> list[str]:
        serialized = self._serializeHelper(root)
        return serialized

    def _serializeHelper(self, root: TreeNode) -> list[str]:
        if not root:
            return ["#"]
        serialized = [str(root.val)]
        serialized += self._serializeHelper(root.left)
        serialized += ["#"]  
        serialized += self._serializeHelper(root.right)
        return serialized

preOrder = [1, 2, 4, 7, 3, 5, 6, 8]
inOrder = [4, 7, 2, 1, 5, 3, 8, 6]

solution = Solution()
root = solution.reConstructBinaryTree(preOrder, inOrder)

serialized_tree = solution.serialize(root)
print(serialized_tree)