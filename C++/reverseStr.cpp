#include<iostream>
#include<string>

class Solution{
    public:
    std::string solve(std::string str) {
        int n = str.size();
        if(n<=1){return str;}
        int left=0;
        int right=n-1;
        while(left<right){
            int tmp=str[left];
            str[left]=str[right];
            str[right]=tmp;
            right--;
            left++;
        }
        return str;
    }
};

int main(){
    std::string str="abcd";
    Solution solution;
    std::cout<<"\""<<solution.solve(str)<<"\""<<std::endl;
    return 0;
}