class ListNode:
     def __init__(self, x):
        self.val = x
        self.next = None
        
class Solution:
    def ReverseList(self , head: ListNode) -> ListNode:
        while head ==None:
            return None
        pre =None
        next = None
        while head != None:
            next =head.next
            head.next =pre
            pre = head
            head = next
        return pre

def print_list(node):
    while node:
        print(node.val, end=" -> ")
        node = node.next
    print("None")

head = ListNode(1)
head.next = ListNode(2)
head.next.next = ListNode(3)

print("Original List:")
print_list(head)

solution = Solution()
reversed_head = solution.ReverseList(head)

print("Reversed List:")
print_list(reversed_head)