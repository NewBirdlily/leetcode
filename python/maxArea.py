class Solution:
    def maxArea(self , height: list[int]) -> int:
        n=len(height)
        if n<2:
            return 0
        left=0
        right=n-1
        max_area=0
        while left<right:
            current=min(height[left],height[right])*(right-left)
            max_area=max(current,max_area)
            if height[left] <height[right]:
                left +=1
            else:
                right -=1
        return max_area
    
height=[1,7,3,2,4,5,8,2,7]
s=Solution()
print(s.maxArea(height))