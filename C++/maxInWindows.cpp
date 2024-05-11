#include<iostream>
#include<algorithm>
#include<vector>

class Solution {
public:
    std::vector<int> maxInWindows(std::vector<int>& num, int size) {
        if(size>num.size() || size == 0) return {};
        std::vector<int>result;
      
        for(int i=0;i<=num.size()-size;i++){
            std::vector<int>windows;
            for(int j =0;j<size;j++){
                windows.push_back(num[i+j]);
            }
            result.push_back(*std::max_element(windows.begin(),windows.end()));
        }
        return result;
    }
};

int main(){
    std::vector<int>nums={2,3,4,2,6,2,5,1};
    int size=3;
    Solution solution;
    std::vector<int>result=solution.maxInWindows(nums,size);
    std::cout<<"Max elements in windows :";
    for(int num:result){
        std::cout<<num<<" ";
    }
    std::cout<<std::endl;
    return 0;
}