#include<iostream>
#include <unordered_map>
#include<string>
#include<stack>

class Solution {
  public:
    bool isValid(std::string s){
        std::stack<char>st;
        std::unordered_map<char, char> mapping ={{')','('},{']','['},{'}','{'}};
        for(char &c:s){
            if(mapping.find(c) !=mapping.end()){
                if(st.empty() ||st.top() != mapping[c]){
                    return false;
                }
                st.pop();
            }
            else{
                st.push(c);
            }  
        }
        return st.empty();
    }             
};

int main(){
    Solution solution;
    std::string str = "[";
    if(solution.isValid(str)){
        std::cout << "The string is valid." << std::endl;
    }
    else{
        std::cout << "The string is not valid." << std::endl;
    }
    return 0;
}