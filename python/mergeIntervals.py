class Interval:
    def __init__(self, a=0, b=0):
        self.start = a
        self.end = b

    def __repr__(self): 
        return f"[{self.start},{self.end}]"

class Solution:
    def merge(self, intervals: list[Interval]) -> list[Interval]:
        n = len(intervals)
        if n <= 1:
            return intervals
        intervals.sort(key=lambda x: x.start)
        merged = []
        merged.append(intervals[0])
        for i in range(1, n):
            if merged[-1].end >= intervals[i].start:
                merged[-1].end = max(merged[-1].end, intervals[i].end)
            else:
                merged.append(intervals[i])
        return merged

intervals = [Interval(10, 30), Interval(20, 60), Interval(80, 100), Interval(150, 180)]

s = Solution()
merged_intervals = s.merge(intervals)

print(merged_intervals)