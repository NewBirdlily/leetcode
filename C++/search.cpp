#include<iostream>
#include<vector>

class Solution{
    public:
    int search(std::vector<int>& nums, int target) {
        while(nums.empty()){return -1;}
        if (nums.size() == 1) {
            return nums[0] == target ? 0 : -1; 
        }
        size_t begin = 0;
        size_t end = nums.size() - 1;
        while (begin <= end) { 
            size_t med = begin + ((end - begin) >> 1);
            if (target == nums[med]) {
                return med;
            } else if (target < nums[med]) {
                end = med - 1;
            } else {
                begin = med + 1;
            }
        }
        return -1;
    }
};

int main(){
    std::vector<int>nums={-1,0,3,4,6,10,13,14};
    int target = 13;
    Solution solution;
    int search=solution.search(nums,target);
    std::cout<<search<<std::endl;
    return 0;
}
