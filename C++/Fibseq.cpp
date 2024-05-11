#include<iostream>
#include<vector>

class Solution{
    public:
    std::vector<std::vector<int>> multiply(const std::vector<std::vector<int>>& a,
    const std::vector<std::vector<int>>& b) {
        std::vector<std::vector<int>> result(2, std::vector<int>(2, 0));
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < 2; ++k) {
                    result[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        return result;
    }

    std::vector<std::vector<int>> matrixPower(std::vector<std::vector<int>> base, int n) {
        std::vector<std::vector<int>> result = {{1, 0}, {0, 1}};
        while (n > 0) {
            if (n % 2 == 1) {
                result = multiply(result, base);
            }
            base = multiply(base, base);
            n /= 2;
        }
        return result;
    }

    int Fibonacci(int n) {
        if (n == 0) return 0;
        std::vector<std::vector<int>> base = {{1, 1}, {1, 0}};
        std::vector<std::vector<int>> result = matrixPower(base, n);
        return result[1][0];
    }
};

int main(){
    int n=4;
    Solution solution;
    std::cout<<solution.Fibonacci(n)<<std::endl;
    return 0;
}