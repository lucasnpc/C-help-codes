#include <vector>
#include <iostream>
#include <map>

int findOdd(const std::vector<int>& numbers) {
    std::map<int, int> vector;
    for (const int& n : numbers) {
        vector[n]++;
    }

    for (const int& n : numbers) {
        if (vector[n] % 2 > 0)
        {
            return n;
        }
    }
    return 0;
}

int main() {
    std::vector<int> v1 = { 20,1,-1,2,-2,3,3,5,5,1,2,4,20,4,-1,-2,5 };
    std::cout << findOdd(v1) << "\n";

    return 0;
}