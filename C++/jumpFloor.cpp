#include <iostream>

class Solution {
public:
    int jumpFloor(int number) {
        if (number == 1) {
            return 1;
        }
        if (number == 2) {
            return 2;
        }
        int a = 1, b = 2;
        for (int i = 3; i <= number; i++) {
            int c = a + b;
            a = b;
            b = c;
        }
        return b; 
    }
};

int main() {
    int n = 15;
    Solution solution;
    std::cout << solution.jumpFloor(n) << std::endl;
    return 0;
}