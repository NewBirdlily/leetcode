#include<iostream>
#include<vector>
#include<algorithm>

class Solution{
    public:
    std::vector<std::vector<int> > rotateMatrix(std::vector<std::vector<int> >& mat, int n) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                std::swap(mat[i][j], mat[j][i]);
            }
        }
        for(int i =0;i<n;i++){
            reverse(mat[i].begin(),mat[i].end());
        }
        return mat;
    }
};

std::ostream& operator<<(std::ostream& os, const std::vector<int>& vec) {
    os << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        os << vec[i];
        if (i < vec.size() - 1) os << ", ";
    }
    os << "]";
    return os;
}

std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<int>>& matrix) {
    os << "[";
    for (size_t i = 0; i < matrix.size(); ++i) {
        os << matrix[i];
        if (i < matrix.size() - 1) os << ", ";
    }
    os << "]";
    return os;
}


int main(){
    std::vector<std::vector<int>>mat={{1,2,3},{4,5,6},{7,8,9}};
    int n=3;
    Solution solution;
    std::vector<std::vector<int>>matrix=solution.rotateMatrix(mat,n);
    std::cout<<"[";
    for(const auto& vec: matrix){
        std::cout<<vec;
        if(vec !=matrix.back()){
            std::cout<<",";
        }
    }
    std::cout<<"]"<<std::endl;
    return 0;
}