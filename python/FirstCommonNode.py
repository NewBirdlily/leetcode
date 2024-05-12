class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def FindFirstCommonNode(self , pHead1 , pHead2 ):
        if pHead1 is None or pHead2 is None :
            return None
        p1 = pHead1
        p2 = pHead2
        len1 = 0
        len2 = 0
        while p1:
            p1 = p1.next
            len1 +=1
        while p2:
            p2 = p2.next
            len2 +=1
        len_diff = abs(len1-len2)
        if len1 >len2:
            for i in range(len_diff):
                pHead1 = pHead1.next
        else:
            for i in range(len_diff):
                pHead2 = pHead2.next
        while pHead1 and pHead2:
            if pHead1 == pHead2:
                return pHead1
            pHead1 = pHead1.next
            pHead2 = pHead2.next
        return None  

list1 = ListNode(1)
list1.next = ListNode(2)
list1.next.next = ListNode(3)
list1.next.next.next=ListNode(6)
list1.next.next.next.next=ListNode(7)
list2 = ListNode(4)
list2.next = ListNode(5)
list2.next.next=list1.next.next.next
solution=Solution()
common_node=solution.FindFirstCommonNode(list1,list2)
if common_node:
    print("The first common node is: ",common_node.val)
else:
    print("There is not common node.")