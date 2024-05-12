from os import pread

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def addInList(self, head1: ListNode, head2: ListNode) -> ListNode:
        if head1 is None or head2 is None:
            return head2 if head1 is None else head1

        reversed_head1 = self.reverse(head1)
        reversed_head2 = self.reverse(head2)

        flag = 0
        pre = None

        while reversed_head1 is not None or reversed_head2 is not None:
            num = flag

            if reversed_head1 is not None:
                num += reversed_head1.val
                reversed_head1 = reversed_head1.next

            if reversed_head2 is not None:
                num += reversed_head2.val
                reversed_head2 = reversed_head2.next

            flag = num // 10
            current = ListNode(num % 10)
            current.next = pre
            pre = current

        if flag:
            new_node = ListNode(flag)
            new_node.next = pre
            pre = new_node

        return pre

    def reverse(self, head: ListNode) -> ListNode:
        current = head
        pre = None

        while current is not None:
            next_node = current.next
            current.next = pre
            pre = current
            current = next_node

        return pre

head1=ListNode(9)
head1.next=ListNode(3)
head1.next.next=ListNode(7)
head2=ListNode(6)
head2.next=ListNode(3)
solution = Solution()
add_head=solution.addInList(head1,head2)
while add_head:
    print(add_head.val,end='')
    add_head=add_head.next
print()
    