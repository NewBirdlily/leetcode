from queue import PriorityQueue
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None
        
class Solution:
    def mergeKLists(self , lists) -> ListNode:
        pq = PriorityQueue() 
        for i in range(len(lists)): 
            if lists[i] != None: 
                pq.put((lists[i].val, i))
                lists[i] = lists[i].next
        res = ListNode(-1) 
        head = res
        while not pq.empty():
            val, idx = pq.get() 
            head.next = ListNode(val) 
            head = head.next
            if lists[idx] != None: 
                pq.put((lists[idx].val, idx))
                lists[idx] = lists[idx].next
        return res.next
    
def print_list(node):
    while node:
        print(node.val, end=" -> ")
        node = node.next
    print("None")


list1 = ListNode(1)
list1.next = ListNode(4)
list1.next.next = ListNode(5)

list2 = ListNode(1)
list2.next = ListNode(3)
list2.next.next = ListNode(4)

list3 = ListNode(2)
list3.next = ListNode(6)

solution = Solution()
merged_head = solution.mergeKLists([list1, list2, list3])

print("Merged List:")
print_list(merged_head)