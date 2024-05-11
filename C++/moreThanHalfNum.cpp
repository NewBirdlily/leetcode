#include<iostream>
#include<vector>
#include<algorithm>

class Solution{
    public:
    int MoreThanHalfNum_Solution(std::vector<int>& numbers) {
        std::sort(numbers.begin(),numbers.end());
        return numbers[numbers.size()/2];
    }
};

int main(){
    std::vector<int> nums={1,2,3,2,2,2,5,4,2};
    Solution solution;
    std::cout<<solution.MoreThanHalfNum_Solution(nums)<<std::endl;
    return 0;
}