#include<iostream>
#include<vector>

class Solution{
    public:
    int findPeakElement(std::vector<int>& nums) {
        size_t begin = 0;
        size_t end = nums.size()-1;
        while(begin<end){
            size_t med =begin+((end-begin)>>1);
            if(nums[med]>nums[med+1]){
                end=med;
            }
            else{
                begin=med+1;
            }
        }
        return begin;
    }
};

int main(){
    std::vector<int>nums={2,4,1,2,7,8,4};
    Solution solution;
    int PeakElement=solution.findPeakElement(nums);
    std::cout<<PeakElement<<std::endl;
    return 0;
}