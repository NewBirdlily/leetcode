class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None
class Solution:
    def hasCycle(self , head: ListNode) -> bool:
        if head is None or head.next is None:
            return False
        slow = head
        fast = head
        while slow is not None and fast is not None and fast.next is not None:
            slow =slow.next
            fast =fast.next.next
            if slow ==fast:
                return True
        return False

head = ListNode(3)
node1 = ListNode(2)
node2 = ListNode(0)
node3 = ListNode(4)
head.next = node1
node1.next = node2
node2.next = node3
node3.next = node1  

solution = Solution()
hasCycle = solution.hasCycle(head)
print(hasCycle)