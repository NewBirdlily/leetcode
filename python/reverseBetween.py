class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        if m == n:
            return head

        pre = head
        current = None
        next_node = None

        for i in range(0, m - 1):
            pre = pre.next
        current = pre.next

        for i in range(m, n):
            next_node = current.next
            current.next = pre
            pre = current
            current = next_node

        if m == 1:
            head.next = current
            return pre
        else:
            p = head
            for i in range(0, m - 2):
                p = p.next
            p.next.next = current
            p.next = pre
            return head

def print_list(node):
    while node:
        print(node.val, end=" -> ")
        node = node.next
    print("None")

head = ListNode(1)
head.next = ListNode(2)
head.next.next = ListNode(3)
head.next.next.next = ListNode(4)
head.next.next.next.next = ListNode(5)

print("Original List:")
print_list(head)

solution = Solution()
reversed_head = solution.reverseBetween(head, 2, 4)

print("List after reversing between nodes 2 to 4:")
print_list(reversed_head)