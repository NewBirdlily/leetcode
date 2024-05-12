class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None
        
class Solution:
    def Merge(self , pHead1: ListNode, pHead2: ListNode) -> ListNode:
        if pHead1 is None:
            return pHead2
        if pHead2 is None:
            return pHead1
        p=ListNode(0)
        current =p
        while pHead1 is not None and pHead2 is not None:
            if pHead1.val <= pHead2.val:
                current.next =pHead1
                pHead1=pHead1.next
            else:
                current.next = pHead2
                pHead2=pHead2.next
            current =current.next
        if pHead1 is not None:
            current.next =pHead1
        if pHead2 is not None:
            current.next =pHead2
        return p.next
    
def print_list(node):
    while node:
        print(node.val, end=" -> ")
        node = node.next
    print("None")

list1 = ListNode(1)
list1.next = ListNode(3)
list1.next.next = ListNode(5)

list2 = ListNode(2)
list2.next = ListNode(4)
list2.next.next = ListNode(6)

print("List 1:")
print_list(list1)
print("List 2:")
print_list(list2)

solution = Solution()
merged_head = solution.Merge(list1, list2)

print("Merged List:")
print_list(merged_head)