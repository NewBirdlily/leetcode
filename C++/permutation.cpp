#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

class Solution{
    public:
    std::vector<std::string> Permutation(std::string str) {
        std::vector<std::string> result;
        if (str.empty()) {
            return {};
        }
        std::sort(str.begin(), str.end()); 
        std::vector<bool> visited(str.size(),false);
        std::string path;
        dfs(str,visited,path,result);
        return result;
    }

    void dfs(std::string &str, std::vector<bool> visited,std::string &path,std::vector<std::string> &result) {
        if (path.size() == str.size()) {
            result.push_back(path);
            return;
        }
        for (int i = 0; i < str.size(); i++) {
            if (visited[i] ||(i>0 && str[i]==str[i-1] && !visited[i-1])) {
                continue;
            }
            visited[i]=true;
            path.push_back(str[i]);
            dfs(str,visited,path, result);
            path.pop_back();
            visited[i]=false;
        }
    }
};

int main(){
    std::string str1="aab";
    std::string str2="abc";
    Solution solution;
    std::vector<std::string>result1=solution.Permutation(str1);
    std::vector<std::string>result2=solution.Permutation(str2);
    std::cout<<"The result of str1 is :"<<"[";
    for(const auto& res1:result1){
        std::cout<<res1<<" ";
    }
    std::cout<<"]"<<std::endl;
    std::cout<<"The result of str2 is :"<<"[";
    for(const auto& res2:result2){
        std::cout<<res2<<" ";
    }
    std::cout<<"]"<<std::endl;
    return 0;
}