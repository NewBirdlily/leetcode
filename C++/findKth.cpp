#include<iostream>
#include<vector>
#include<algorithm>

class Solution {
  public:
    int partition(std::vector<int>& a, int startIndex, int endIndex) {
        int pivot = a[startIndex];
        int left = startIndex;
        int right = endIndex;
        while (left < right) {
            while (left < right && a[right] <= pivot) {
                right--;
            }
            while (left < right && a[left] >= pivot) {
                left++;
            }
            if (left < right) {
                std::swap(a[left], a[right]);
            }
        }
        a[startIndex] = a[left];
        a[left] = pivot;
        return left;
    }

    int findKth(std::vector<int>& a, int n, int K) {
        if (K > n || K <= 0) {
            return -1;
        }
        for (int startIndex = 0, endIndex = n - 1; startIndex <= endIndex;) {
            int pivotIndex = partition(a, startIndex, endIndex); 
            if (pivotIndex == K - 1) {
                return a[pivotIndex];
            } else if (pivotIndex < K - 1) {
                startIndex = pivotIndex + 1;
            } else {
                endIndex = pivotIndex - 1;
            }
        }
        return -1; 
    }
};
int main(){
    std::vector<int>a={1,3,5,2,2};
    int n=5;
    int K=3;
    Solution solution;
    int Kth=solution.findKth(a,n,K);
    std::cout<<"The Kth largest number is: "<<Kth<<std::endl;
    return 0;
}