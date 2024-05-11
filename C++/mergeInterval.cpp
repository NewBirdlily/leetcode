#include<iostream>
#include<vector>
#include<algorithm>

struct Interval{
    int start;
    int end;
    Interval(int s, int e): start(s),end(e){}
};

class Solution{
    public:
    std::vector<Interval> merge(std::vector<Interval>& intervals) {
        int n = intervals.size();
        if (n <= 1) {
            return intervals;
        }
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){return a.start<b.start;});
        std::vector<Interval> merge;
        merge.push_back(intervals[0]);
        for (int i = 1; i < n; i++) {
            if (merge.back().end >= intervals[i].start) {
                merge.back().end = std::max(merge.back().end, intervals[i].end);
            } else {
                merge.push_back(intervals[i]);
            }
        }
        return merge;
    }
};

std::ostream& operator<<(std::ostream& os, const Interval& interval) {
    os << "[" << interval.start << ", " << interval.end << "]";
    return os;
}

std::ostream& operator<<(std::ostream& os, const std::vector<Interval>& intervals) {
    os << "[";
    for (size_t i = 0; i < intervals.size(); ++i) {
        os << intervals[i];
        if (i < intervals.size() - 1) os << ", ";
    }
    os << "]";
    return os;
}

int main() {
    std::vector<Interval> intervals = {{10, 30}, {20, 60}, {80, 100}, {150, 180}};
    Solution solution;
    std::vector<Interval> merge = solution.merge(intervals);
    std::cout<<"[";
    for (const auto& interval : merge) {
        std::cout << interval;
        if (&interval != &merge.back()) {
            std::cout << ",";
        }
    }
    std::cout<<"]"<<std::endl;
    return 0;
}