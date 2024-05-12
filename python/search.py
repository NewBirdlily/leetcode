class Solution:
    def search(self , nums:list[int], target: int) -> int:
        if len(nums) == 0:
            return -1
        if len(nums) == 1 and nums[0] != target:
            return -1
        begin = 0
        end = len(nums) - 1
        while begin <= end:
            med = begin + ((end - begin) >> 1)
            if nums[med] == target:
                return med
            elif nums[med] < target:
                begin = med + 1
            else:
                end = med - 1
        return -1

list=[-1,0,3,4,6,10,13,14]
target=13
solution=Solution()
print("The target is:",solution.search(list,target))