class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def deleteDuplicates(self , head: ListNode) -> ListNode:
        cur = head
        while cur and cur.next:
            if cur.val == cur.next.val:
                cur.next = cur.next.next
            else:
                cur = cur.next
        return head
    
head=ListNode(1)
head.next=ListNode(1)
head.next.next=ListNode(2)
head.next.next.next=ListNode(3)
head.next.next.next.next=ListNode(3)
solution=Solution()
delete_duplicatehead=solution.deleteDuplicates(head)
while delete_duplicatehead:
    print(delete_duplicatehead.val,end='')
    delete_duplicatehead=delete_duplicatehead.next
print()