#include<iostream>
#include<vector>

class Solution{
    public:
    int minNumberInRotateArray(std::vector<int>& nums) {
        if (nums.empty()) {
            return -1; 
        }
        
        int begin = 0;
        int end = nums.size() - 1;
        
        while (begin < end) {
            int mid = begin + ((end - begin) >> 1);
            
            if (nums[mid] > nums[end]) {
                begin = mid + 1;
            } 
            else if (nums[mid] < nums[end]) {
                end = mid;
            } 
            else { 
                end--;
            }
        }
        
        return nums[begin];
        }
};
int main(){
    std::vector<int>nums={3,4,5,1,2};
    Solution solution;
    int minNum=solution.minNumberInRotateArray(nums);
    std::cout<<"The min number in RotateArray is:"<<minNum<<std::endl;
    return 0;
}