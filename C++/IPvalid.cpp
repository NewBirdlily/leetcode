#include<iostream>
#include<string>

class Solution{
    public:
    std::string solve(std::string IP) {
        int n =IP.size();;
        if (IP.find('.') != std::string::npos) {
            int start = 0, sum = 0;
            for (int i = 0; i < n; i++) {
                if (IP[start] == '0'||IP[n-1]=='.') {
                    return "Neither";
                }
                if (IP[i] == '.') {
                    if (sum > 255)return"Neither";
                    start = i + 1;
                    sum = 0;
                } else {
                    sum = sum * 10 + IP[i] - '0';
                }
            }
            return "IPv4";
        }

        if (IP.find(':') != std::string::npos) {
            int start = 0, num = 0;
            for (int i = 0; i < n; i++) {
                if (IP[start] == ':' || IP[n - 1] == ':') return "Neither"; 
                if (IP[i] == ':') {
                    if (num > 4) return "Neither";                         
                    start = i + 1;
                    num = 0;
                } else if (!((IP[i] >= '0' && IP[i] <= '9') || (IP[i] >= 'a' && IP[i] <= 'f') || (IP[i] >= 'A' && IP[i] <= 'F') )) {
                    return "Neither";                                       
                } else {
                    num++;                                         
                }
            }
            return "IPv6";
        }
        return "Neither";
    }
};

int main(){
    std::string IP1="172.16.254.1";
    std::string IP2="2001:0db8:85a3:0:0:8A2E:0370:7334";
    std::string IP3="256.256.256.256";
    Solution solution;
    std::cout<<"\""<<solution.solve(IP1)<<"\""<<std::endl;
    std::cout<<"\""<<solution.solve(IP2)<<"\""<<std::endl;
    std::cout<<"\""<<solution.solve(IP3)<<"\""<<std::endl;
    return 0;
}