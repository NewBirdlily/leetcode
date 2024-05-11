#include<iostream>
#include<vector>
#include<unordered_map>

class Solution{
    public:
    int maxLength(std::vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) {
            return n;
        }
        std::unordered_map<int, int>last_seen; 
        int maxLength = 0;
        int left = 0;

        for (int right = 0; right < n; right++) {
            if (last_seen.find(arr[right]) != last_seen.end() && last_seen[arr[right]] >= left) {
                left = last_seen[arr[right]] + 1;
            }
            last_seen[arr[right]] = right;
            maxLength = std::max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};

int main(){
    std::vector<int>arr1={2,3,4,5};
    std::vector<int>arr2={2,2,3,4,3};
    Solution solution;
    std::cout<<solution.maxLength(arr1)<<"\n"<<solution.maxLength(arr2)<<"\n";
    return 0;
}