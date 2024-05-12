class Solution:
    def FindNumsAppearOnce(self, nums: list[int]) -> list[int]:
        result = [0, 0]
        xor_result = 0
        for num in nums:
            xor_result ^= num
        if xor_result == 0:
            return []
        separator = 1
        while xor_result & separator == 0:
            separator <<= 1
        for num in nums:
            if num & separator == 0:
                result[0] ^= num
            else:
                result[1] ^= num
        if result[0] > result[1]:
            result[0], result[1] = result[1], result[0]
        return result

nums=[1,2,3,3,2,9]
s=Solution()
print(s.FindNumsAppearOnce(nums))