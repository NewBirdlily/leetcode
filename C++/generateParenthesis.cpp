#include<iostream>
#include<vector>
#include<string>

class Solution{
    public:
    std::vector<std::string> generateParenthesis(int n) {
        if (n == 0) { return {}; }
        std::vector<std::string> result;
        generate("", n, n, result);
        return result;
    }

    void generate(std::string s, int left, int right, std::vector<std::string>& result) {
        if (left == 0 && right == 0) {
            result.push_back(s);
            return;
        }
        if (left > 0) {
            generate(s + '(', left - 1, right, result);
        }
        if (right > left) {
            generate(s + ')', left, right - 1, result);
        }
    }
};

int main(){
    int n1=1;
    int n2=2;
    Solution solution;
    std::vector<std::string>result1=solution.generateParenthesis(n1);
    std::vector<std::string>result2=solution.generateParenthesis(n2);
    std::cout << "n=1:" << "[";
    for (const auto& res1 : result1) {
        std::cout << "\"" << res1 << "\"";
        if (&res1 != &result1.back()) {
            std::cout << ",";
        }
    }
    std::cout<<"]"<<std::endl;

    std::cout << "n=2:" << "[";
    for (const auto& res2 : result2) {
        std::cout << "\"" << res2 << "\"";
        if (&res2 != &result2.back()) {
            std::cout << ",";
        }
    }
    std::cout<<"]"<<std::endl;

    return 0;
}