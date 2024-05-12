class ListNode:
    def __init__(self, val):
        self.val = val
        self.next = None
        self.pre = None


class Solution:
    def __init__(self, capacity: int):
        self.cap = capacity
        self.hash = dict()
        self.head = None
        self.tail = None

    def get(self, key: int) -> int:
        if key in self.hash:
            if self.hash[key].pre != None:
                self.freshListNode(self.hash[key])
            return self.hash[key].val[0]
        else:
            return -1

    def set(self, key: int, value: int) -> None:
        value = [value, key]
        if key in self.hash:
            self.hash[key].val = value
            if self.hash[key].pre != None:
                self.freshListNode(self.hash[key])
            return
        if self.cap > 0:
            ele = ListNode(value)
            self.hash[key] = ele
            self.addOneNode(ele)
            self.cap -= 1
        else:
            del self.hash[self.tail.val[1]]
            self.hash[key] = self.tail
            self.tail.val = value
            if self.tail.pre != None:
                self.freshListNode(self.tail)

    def freshListNode(self, ele):
        ele.pre.next = ele.next
        if self.tail == ele:
            self.tail = ele.pre
        else:
            ele.next.pre = ele.pre
        ele.pre = None
        self.head.pre = ele
        ele.next = self.head
        self.head = ele

    def addOneNode(self, ele):
        if self.head == None:
            self.head = ele
            self.tail = ele
        else:
            ele.pre = None
            ele.next = self.head
            self.head.pre = ele
            self.head = ele

s=Solution(2)
s.set(1,1)
s.set(2,2)
print(s.get(1))
s.set(3,3)
print(s.get(2))
s.set(4,4)
print(s.get(1))
print(s.get(3))
print(s.get(4))
