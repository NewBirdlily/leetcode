#include<iostream>
#include<vector>

class Solution{
    public:
    int minNumberDisappeared(std::vector<int>& nums) {
        int n =nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<=0||nums[i]>n){
                nums[i] =n+1;
            }
        }
        for(int i=0;i<n;i++){
            int num =abs(nums[i]);
            if(num>n)continue;
            int idx =num-1;
            if(nums[idx]>0){
                nums[idx]=-nums[idx];
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                return i+1;
            }
        }
        return n+1;
    }
};

int main(){
    std::vector<int>nums={-2,3,4,1,5};
    Solution solution;
    std::cout<<solution.minNumberDisappeared(nums)<<std::endl;
    return 0;
}
