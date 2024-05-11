#include<iostream>
#include<stack>

class Solution {
public:
    std::stack<int>stack1;
    std::stack<int>Min;
    void push(int value) {
        stack1.push(value);
        if(Min.empty() || value <= Min.top()){
            Min.push(value);
        }
    }
    
    void pop() {
        if (stack1.top() == Min.top()) {
            stack1.pop();
            Min.pop();
        } else {
            stack1.pop();
        }
    }
    
    int top() {
        return stack1.top();
    }
    
    int min() {
        return Min.top();
    }
};

int main(){
    Solution solution;
    solution.push(-1);
    solution.push(2);
    std::cout<<solution.min()<<" ";
    std::cout<<solution.top()<<" ";
    solution.pop();
    solution.push(1);
    std::cout<<solution.top()<<" ";
    std::cout<<solution.min()<<std::endl;

    return 0;
}