class ListNode:
    def __init__(self, x):
            self.val = x
            self.next = None
            
class Solution:
    def sortInList(self, head: ListNode) -> ListNode:
        if head is None:
            return None
        s = []
        while head :
                s.append(head.val)
                head = head.next
        s = sorted(s)
        res = ListNode(0)
        temp = res
        for i in s :
            temp.next = ListNode(i)
            temp = temp.next
        return res.next

head=ListNode(1)
head.next=ListNode(3)
head.next.next=ListNode(2)
head.next.next.next=ListNode(4)
head.next.next.next.next=ListNode(5)
solution=Solution()
sort_head=solution.sortInList(head)
while sort_head:
    print(sort_head.val,end='')
    sort_head=sort_head.next
print()