class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def oddEvenList(self , head: ListNode) -> ListNode:
        if head is None:
            return head
        evenhead =head.next
        odd = head
        even =evenhead
        while even and even.next:
            odd.next = even.next
            even.next = even.next.next
            odd = odd.next
            even = even.next
        odd.next = evenhead
        return head

head=ListNode(1)
head.next=ListNode(4)
head.next.next=ListNode(6)
head.next.next.next=ListNode(3)
head.next.next.next.next=ListNode(7)
solution=Solution()
odd_evenhead=solution.oddEvenList(head)
while odd_evenhead:
    print(odd_evenhead.val,end='')
    odd_evenhead=odd_evenhead.next
print()