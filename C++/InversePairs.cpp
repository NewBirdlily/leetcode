#include<iostream>
#include<vector>

class Solution{
    public:
    int InversePairs(std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        std::vector<int> temp(nums.size());
        return mergeSortCount(nums, temp, 0, nums.size() - 1);
    }

    int mergeSortCount(std::vector<int>& nums, std::vector<int>& temp, int start, int end) {
        if (start >= end) {
            return 0;
        }
        int mid = start + (end - start) / 2;
        int countLeft = mergeSortCount(nums, temp, start, mid);
        int countRight = mergeSortCount(nums, temp, mid + 1, end);
        int mergeCountResult = mergeCount(nums, temp, start, mid, end);
        return countLeft + countRight + mergeCountResult;
    }

    int mergeCount(std::vector<int>& nums, std::vector<int>& temp, int start, int mid, int end) {
        int count = 0;
        int i = mid, j = end, k = end; 
        while (i >= start && j > mid) {
            if (nums[i] > nums[j]) {
                count += (j - mid);
                temp[k--] = nums[i--];
            } else {
                temp[k--] = nums[j--];
            }
        }
        while (i >= start) {
            temp[k--] = nums[i--];
        }
        while (j > mid) {
            temp[k--] = nums[j--];
        }
        for (int m = start; m <= end; ++m) {
            nums[m] = temp[m];
        }
        return count;
    }
};

int main(){
    std::vector<int>nums={1,2,3,4,5,6,7,0};
    Solution solution;
    int Inversecount=solution.InversePairs(nums);
    std::cout<<Inversecount<<std::endl;
    return 0;
}
