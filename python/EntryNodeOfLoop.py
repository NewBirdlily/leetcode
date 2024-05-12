class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None
        
class Solution:
    def EntryNodeOfLoop(self, pHead):
        if pHead is None and pHead.next is None:
            return False
        fast = pHead
        slow = pHead
        while fast and slow and fast.next:
            slow = slow.next
            fast = fast.next.next
            if fast == slow:
                fast = pHead
                while fast !=slow:
                    fast = fast.next
                    slow = slow.next
                return fast
        return None

head = ListNode(1)
node1 = ListNode(2)
node2 = ListNode(3)
node3 = ListNode(4)
node4=ListNode(5)
head.next = node1
node1.next = node2
node2.next = node3
node3.next=node4
node4.next = node1 

solution = Solution()
entryNode=solution.EntryNodeOfLoop(head)
if entryNode:
        print("The value of the entry node of the loop is: ") 
        print(entryNode.val) 
else:
        print("There is no loop in the list.") 
