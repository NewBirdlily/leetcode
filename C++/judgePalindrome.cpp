#include<iostream>
#include<string>

class Solution{
    public:
    bool judge(std::string str) {
        int left = 0;
        int right = str.size() - 1;
        
        while (left < right) {
            if (str[left] != str[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};

int main(){
    std::string str1="absba";
    std::string str2="ranko";
    std::string str3="yamatomaya";
    std::string str4="a";
    Solution solution;
    std::cout<<solution.judge(str1)<<"\n"<<solution.judge(str2)<<"\n"<<solution.judge(str3)<<"\n"<<solution.judge(str4)<<"\n";
    return 0;
}