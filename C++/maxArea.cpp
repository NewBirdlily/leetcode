#include<iostream>
#include<vector>

class Solution{
    public:
    int maxArea(std::vector<int>& height) {
        int n =height.size();
        int maxArea =0;
        if(n<2){return 0;}
        int left=0;
        int right=n-1;
        while(left<right){
            int current= std::min(height[left],height[right])*(right-left);
            maxArea=std::max(maxArea,current);
            if(height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxArea;
    }
};

int main(){
    std::vector<int>height1={1,7,3,2,4,5,8,2,7};
    std::vector<int>height2={5,4,3,2,1,5};
    Solution solution;
    std::cout<<solution.maxArea(height1)<<"\n"<<solution.maxArea(height2)<<"\n";
    return 0;
}