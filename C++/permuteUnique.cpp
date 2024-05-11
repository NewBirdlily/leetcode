#include<iostream>
#include<vector>
#include<algorithm>

class Solution{
    public:
    std::vector<std::vector<int> > permuteUnique(std::vector<int>& num) {
        std::vector<std::vector<int>>result;
        std::vector<int>path;
        std::vector<bool>used(num.size(),false);
        std::sort(num.begin(),num.end());
        backtrack(num,used,path,result);
        return result;
    }
    
    void backtrack(std::vector<int>& num, std::vector<bool>& used,std::vector<int>& path,std::vector<std::vector<int>>& result){
        if(path.size()==num.size()){
            result.push_back(path);
            return;
        }
        for(int i=0;i<num.size();i++){
            if(used[i]||(i>0&& num[i] ==num[i-1]&&!used[i-1])){
                continue;
            }
            path.push_back(num[i]);
            used[i]=true;
            backtrack(num,used,path,result);
            path.pop_back();
            used[i]=false;
        }
    }
};
std::ostream& operator<<(std::ostream& os, const std::vector<int>& vec) {
    os << "(";
    for (size_t i = 0; i < vec.size(); ++i) {
        os << vec[i];
        if (i < vec.size() - 1) os << ", ";
    }
    os << ")";
    return os;
}

int main(){
    std::vector<int>nums={1,2,1};
    Solution solution;
    std::vector<std::vector<int>>result=solution.permuteUnique(nums);
    for( const auto&res:result){
        std::cout<<res<<" ";
    }
    std::cout<<std::endl;
    return 0;
}