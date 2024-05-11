#include<iostream>
#include<vector>
#include<algorithm>

class Solution{
    public:
    int minmumNumberOfHost(int n, std::vector<std::vector<int> >& startEnd) {
        if (n <= 1) {return n;}
        std::vector<int>startTimes;
        std::vector<int>endTimes;
        for(int i =0;i<n;i++){
            startTimes.push_back(startEnd[i][0]);
            endTimes.push_back(startEnd[i][1]);
        }
        sort(startTimes.begin(),startTimes.end());
        sort(endTimes.begin(),endTimes.end());
        int result=1, j=0;
        for(int i=1;i<n;i++){
            while(startTimes[i]<endTimes[j] && i<n){
                result++;
                i++;
            }
            j++;
        }
        return result;
    }
};

int main(){
    int n =2;
    std::vector<std::vector<int>>startEnd1={{1,2},{2,3}};
    std::vector<std::vector<int>>startEnd2={{1,3},{2,3}};
    Solution solution;
    std::cout<<solution.minmumNumberOfHost(n,startEnd1)<<std::endl;
    std::cout<<solution.minmumNumberOfHost(n,startEnd2)<<std::endl;
    return 0;
}