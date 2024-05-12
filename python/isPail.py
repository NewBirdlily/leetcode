class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def isPail(self , head: ListNode) -> bool:
        list1 = []
        while head:
            list1.append(head.val)
            head = head.next
        for i in range(len(list1)):
            if i>len(list1)-1-i:
                break
            if list1[i] != list1[len(list1)-1-i]:
                return False
        return True

head=ListNode(1)
head.next=ListNode(2)
head.next.next=ListNode(2)
head.next.next.next=ListNode(1)
solution=Solution()
while head:
    print(head.val,end='')
    head=head.next
pail_head=solution.isPail(head)
print(end=":")
if(pail_head):
    print("true")
else:
    print("false")