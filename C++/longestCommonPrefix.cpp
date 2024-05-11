#include<iostream>
#include<vector>
#include<string>

class Solution{
    public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        int n =strs.size();
        if(n==0){
            return "";
        }
        std::string commonPrefix=strs[0];
        for(int i =1;i<n;i++){
            int size = 0;
            while(size<commonPrefix.size() && size<strs[i].size() &&commonPrefix[size]==strs[i][size]){
                size++;
            }
            commonPrefix=commonPrefix.substr(0,size);
        }
        return commonPrefix;
    }
};

int main(){
    std::vector<std::string> str1={"abca","abc","abca","abc","abcc"};
    std::vector<std::string> str2={"dbcefg","admefg"};
    Solution solution;
    std::cout<<"\""<<solution.longestCommonPrefix(str1)<<"\""<<std::endl;
    std::cout<<"\""<<solution.longestCommonPrefix(str2)<<"\""<<std::endl;
    return 0;
}