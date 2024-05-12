class ListNode:
    def __init__(self, x):
            self.val = x
            self.next = None

class Solution:
    def deleteDuplicates(self , head: ListNode) -> ListNode:
        if head == None: 
            return None
        res = ListNode(0)
        res.next = head 
        cur = res
        while cur.next and cur.next.next: 
            if cur.next.val == cur.next.next.val: 
                temp = cur.next.val
                while cur.next != None and cur.next.val == temp: 
                    cur.next = cur.next.next
            else:
                cur = cur.next
        return res.next 

head=ListNode(1)
head.next=ListNode(2)
head.next.next=ListNode(3)
head.next.next.next=ListNode(3)
head.next.next.next.next=ListNode(4)
head.next.next.next.next.next=ListNode(4)
head.next.next.next.next.next.next=ListNode(5)
solution=Solution()
delete_duphead=solution.deleteDuplicates(head)
while delete_duphead:
    print(delete_duphead.val,end='')
    delete_duphead=delete_duphead.next
print()