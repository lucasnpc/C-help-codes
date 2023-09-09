#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
#include <numeric>

std::vector<std::pair<int, int>> mergeIntervals(std::vector<std::pair<int, int>>& intervals) {
    std::sort(intervals.begin(), intervals.end());
    std::vector<std::pair<int, int>> merged;
    for (auto interval : intervals) {
        if (merged.empty() || merged.back().second < interval.first) {
            merged.emplace_back(interval);
        }
        else {
            merged.back().second = std::max(merged.back().second, interval.second);
        }
    }
    return merged;
}

int sum_intervals(std::vector<std::pair<int, int>> intervals) {
    std::vector<std::pair<int, int>> merged = mergeIntervals(intervals);
    return std::accumulate(merged.begin(), merged.end(), 0, [](int acc, const auto& interval)
        {
            return acc + interval.second - interval.first;
        });
}

int main() {
    std::cout << sum_intervals({
        std::make_pair(1, 4) ,
            std::make_pair(7, 10),
            std::make_pair(3, 5)
        }) << "\n";
    std::cout << sum_intervals({
        std::make_pair(1, 5) ,
        std::make_pair(10, 20),
        std::make_pair(1, 6),
        std::make_pair(6, 19),
        std::make_pair(5, 11)
        }) << "\n";
    std::cout << sum_intervals({
        std::make_pair(0, 20) ,
        std::make_pair(-100000000, 10),
        std::make_pair(30, 40)
        }) << "\n";

    return 0;
}