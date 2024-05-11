#include<iostream>
#include<algorithm>
#include<vector>

class Solution{
    public:
    std::vector<int> solve(int n, int m, std::vector<int>& a) {
        m=m%n;
        reverse(a.begin(),a.end());
        reverse(a.begin(),a.begin()+m);
        reverse(a.begin()+m,a.end());
        return a;
    }
};

int main(){
    int n=6;
    int m=2;
    std::vector<int> a ={1,2,3,4,5,6};
    Solution solution;
    std::vector<int>rotate=solution.solve(n,m,a);
    std::cout<<"[";
    for(int num:rotate){
        std::cout<<num;
        if(num != rotate.back()){
            std::cout<<",";
        }
    }
    std::cout<<"]"<<std::endl;
    return 0;
}