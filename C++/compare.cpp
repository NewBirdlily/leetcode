#include<iostream>
#include<string>

class Solution {
  public:
    int compare(std::string version1, std::string version2) {
        int n1 = version1.size(), n2 = version2.size();
        int i = 0, j = 0;
        
        while (i < n1 || j < n2) {
            int num1 = 0, num2 = 0;
            while (i < n1 && version1[i] != '.') {
                num1 = num1 * 10 + (version1[i] - '0');
                i++;
            }
            while (j < n2 && version2[j] != '.') {
                num2 = num2 * 10 + (version2[j] - '0');
                j++;
            }      
            if (num1 > num2) {return 1;}
            else if (num1 < num2) {return -1;}
            if (i < n1) {i++;}
            if (j < n2) {j++;}
        }       
        return 0; 
    }
};
int main(){
    std::string v1="1.1";
    std::string v2="1.01";
    Solution solution;
    int compareresult=solution.compare(v1,v2);
    std::cout<<compareresult<<std::endl;
    return 0;
}