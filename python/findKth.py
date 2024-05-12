from numpy import pi

class Solution:
    def findKth(self , a: list[int], n: int, K: int) -> int:
         return self.quickSort(a, 0, n-1, K)

    def quickSort(self, a, start, end, k):
        if start>end:
            return -1
        pivot = a[start]
        left,right = start,end
        while left<right: 
            while left<right and a[right]<=pivot: 
                right -= 1
            while left<right and a[left]>=pivot:
                left += 1
            if left!=right:
                a[left],a[right] = a[right],a[left]
        a[left],a[start] = a[start],a[left]
        if left==k-1:
            return a[left]
        elif left<k-1:
            return self.quickSort(a, left+1, end, k)
        else:
            return self.quickSort(a, start, left-1, k)

a=[1,3,5,2,2]
n1=5
K1=3
b=[10,10,9,9,8,7,5,6,4,3,4,2]
n2=12
K2=3
s=Solution()
print(s.findKth(a,n1,K1))
print(s.findKth(b,n2,K2))
