#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool compare(int a, int b) {
    string s1 = to_string(a);
    string s2 = to_string(b);
    return s1 + s2 < s2 + s1;
}

int main() {
    vector<int> nums{ 102, 95, 114, 1421, 50 };
    sort(nums.begin(), nums.end(), compare);
    for (auto& n : nums) {
        cout << n << "\n";
    }
    return 0;
}