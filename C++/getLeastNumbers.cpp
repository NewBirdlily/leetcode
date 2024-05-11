#include<iostream>
#include<vector>
#include<algorithm>

class Solution {
public:
    std::vector<int> GetLeastNumbers_Solution(std::vector<int>& input, int k) {
        int n =input.size();
        if (k<1 || k>n) return {};
        std::vector<int> Mink;
        for(int i=0;i<k;i++){
            Mink.push_back(input[i]);
        }
        make_heap(Mink.begin(), Mink.end());
        for(int i = k; i < n; i++){
            if(input[i] < Mink[0]){
                pop_heap(Mink.begin(), Mink.end());
                Mink.pop_back();
                Mink.push_back(input[i]);
                push_heap(Mink.begin(), Mink.end());
            }
        }
        return Mink; 
    }
};
int main(){
    std::vector<int>input={4,5,1,6,2,7,3,8};
    int k=4;
    Solution solution;
    std::vector<int>Mink=solution.GetLeastNumbers_Solution(input,k);
    if(!Mink.empty()){
        std::cout<<"The least "<<k<<"number are:";
        for(int num: Mink){
            std::cout<<' '<<num;
        }
        std::cout<<std::endl;
    }
    else{
        std::cout<<"Invalid input or empty result."<<std::endl;
    }
    return 0;
}