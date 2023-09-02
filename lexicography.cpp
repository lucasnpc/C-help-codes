#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector<string> lexicalOrder(int n) {
    vector<string> nums = { };
    for (int i = 1; i <= n; ++i) {
        nums.emplace_back(to_string(i));
    }

    sort(nums.begin(), nums.end());

    return nums;
}

int main() {
    for (auto& i : lexicalOrder(13))
    {
        std::cout << i << "\n";
    }

    return 0;
}