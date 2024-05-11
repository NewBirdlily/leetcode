#include<iostream>
#include<string>
#include<algorithm>

class Solution{
    public:
    std::string solve(std::string s, std::string t) {
        if (s.empty()) return t;
        if (t.empty()) return s;

        reverse(s.begin(), s.end());
        reverse(t.begin(), t.end());

        int m = s.size();
        int n = t.size();
        std::string res;
        int carry = 0;

        for (int i = 0; i < std::max(m, n); i++) {
            int digitSum = carry;
            if (i < m) digitSum += s[i] - '0';
            if (i < n) digitSum += t[i] - '0';
            if (digitSum >= 10) {
                res.push_back((digitSum - 10) + '0');
                carry = 1;
            } else {
                res.push_back(digitSum + '0');
                carry = 0;
            }
        }
        if (carry) {
            res.push_back('1');
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main(){
    std::string s="148263528";
    std::string t="862573299";
    Solution solution;
    std::cout<<solution.solve(s,t)<<std::endl;
    return 0;
}