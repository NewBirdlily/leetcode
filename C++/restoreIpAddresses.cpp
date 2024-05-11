#include<iostream>
#include<string>
#include<vector>

class Solution{
    public:
    std::vector<std::string> restoreIpAddresses(std::string s) {
        int n =s.size();
        std::vector<std::string>res;
        if(n<4||n>12){return {};}
        for(int i=1;i<4 && i<n-2;i++){
            for(int j =i+1;j<i+4 && j<n-1;j++){
                for(int k=j+1;k<j+4 && k<n;k++){
                    std::string a =s.substr(0,i);
                    std::string b =s.substr(i,j-i);
                    std::string c =s.substr(j,k-j);
                    std::string d =s.substr(k,n-k);
                    if(d.size()>3){
                        continue;
                    }
                    if(stoi(a)>255 ||stoi(b)>255||stoi(c)>255 ||stoi(d)>255){
                        continue;
                    }
                    if((a.size()!=1 &&a[0]=='0')||(b.size()!=1 &&b[0]=='0') ||(c.size()!=1 &&c[0]=='0')||(d.size()!=1 &&d[0]=='0')){
                        continue;
                    }
                    std::string temp =a +"."+b+"."+c+"."+d;
                    res.push_back(temp);
                }
            }
        }
        return res;
    }
};

int main(){
    std::string s="25525522135";
    Solution solution;
    std::vector<std::string>result=solution.restoreIpAddresses(s);
    std::cout<<"[";
    for(const auto& res:result){
        std::cout<<"\""<<res<<"\"";
        if (&res != &result.back()) { 
            std::cout << ",";
        }
    }
    std::cout<<"]"<<std::endl;
    return 0; 
}