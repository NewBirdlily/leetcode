#include<iostream>
#include<vector>
#include<algorithm>

class Solution{
    public:
    std::vector<int> FindNumsAppearOnce(std::vector<int>& nums) {
        std::vector<int> result(2, 0);
        int xorResult = 0;
        for (int i = 0; i < nums.size(); i++) {
            xorResult ^= nums[i];
        }
        if (xorResult == 0) {
            return {};
        }
        int separator = 1;
        while (0 == (xorResult & separator)) {
            separator <<= 1;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (0 == (nums[i] & separator)) {
                result[0] ^= nums[i];
            } else {
                result[1] ^= nums[i];
            }
        }
        if (result[0] > result[1]) {
            std::swap(result[0], result[1]);
        }
        return result;
    }
};

int main(){
    std::vector<int>nums={1,2,3,3,2,9};
    Solution solution;
    std::vector<int>result=solution.FindNumsAppearOnce(nums);
    for(int num:result){
        std::cout<<num<<" ";
    }
    std::cout<<std::endl;

    return 0;
}