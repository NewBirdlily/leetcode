#include<iostream>
#include<stack>
#include<string>

class Solution {
  public:
  int precedence(char op) {
        if (op == '+' || op == '-')
            return 1;
        else if (op == '*')
            return 2;
        return 0;
    }

    int compute(char op, int a, int b) {
        if (op == '+')
            return a + b;
        else if (op == '-')
            return a - b;
        else if (op == '*')
            return a * b;
        return 0; 
    }

    int solve(std::string s) {
        std::stack<int> operands;
        std::stack<char> operators;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ')
                continue;
            else if (isdigit(s[i])) {
                int num = 0;
                while (i < s.length() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                operands.push(num);
                i--;
            } 
            else if (s[i] == '(') {
                operators.push(s[i]);
            } 
            else if (s[i] == ')') {
                while (operators.top() != '(') {
                    char op = operators.top();
                    operators.pop();
                    int b = operands.top();
                    operands.pop();
                    int a = operands.top();
                    operands.pop();
                    operands.push(compute(op, a, b));
                }
                operators.pop(); 
            } 
            else {
                while (!operators.empty() && precedence(operators.top()) >= precedence(s[i])) {
                    char op = operators.top();
                    operators.pop();
                    int b = operands.top();
                    operands.pop();
                    int a = operands.top();
                    operands.pop();
                    operands.push(compute(op, a, b));
                }
                operators.push(s[i]);
            }
        }

        while (!operators.empty()) {
            char op = operators.top();
            operators.pop();
            int b = operands.top();
            operands.pop();
            int a = operands.top();
            operands.pop();
            operands.push(compute(op, a, b));
        }

        return operands.top();
    }
};

int main(){
    std::string s="(2*(3-4))*5";
    Solution solution;
    std::cout<<solution.solve(s)<<std::endl;
    return 0;
}