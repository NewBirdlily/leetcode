#include<iostream>
#include<stack>

class Solution {
  public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if(stack1.empty() && stack2.empty()){
            return -1;
        }
        if(stack2.empty()){
            while(!stack1.empty()){
                int s1 =stack1.top();
                stack1.pop();
                stack2.push(s1);
            }
        }
        int s2 =stack2.top();
        stack2.pop();
        return s2;
    }

  private:
    std::stack<int> stack1;
    std::stack<int> stack2;
};

int main(){
    Solution solution;
    solution.push(1);
    solution.push(2);

    std::cout<<"Pop from queue:";
    std::cout<<solution.pop()<<" ";
    std::cout<<solution.pop()<<std::endl;

    return 0;
}