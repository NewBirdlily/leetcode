class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def FindKthToTail(self , pHead: ListNode, k: int) -> ListNode:
        if pHead is None or k<=0:
            return None
        fast = pHead
        slow = pHead
        for i in range(k):
            if fast is None:
                return None
            fast = fast.next
        while fast:
            slow = slow.next
            fast = fast.next
        return slow

head = ListNode(1)
head.next = ListNode(2)
head.next.next = ListNode(3)
head.next.next.next = ListNode(4)
head.next.next.next.next = ListNode(5)
k=2
solution=Solution()
k_tail=solution.FindKthToTail(head,k)
if k_tail:
    print("The",k,"th node from the end is:",k_tail.val)
else:
    print("The list has less than",k,"nodes.")