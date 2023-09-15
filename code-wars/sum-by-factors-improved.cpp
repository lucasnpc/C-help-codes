#include <string>
#include <vector>
#include <map>
#include <iostream>

class SumOfDivided
{
public:
    static std::string sumOfDivided(const std::vector<int>& lst);
};

std::string SumOfDivided::sumOfDivided(const std::vector<int>& lst) {
    std::map<int, int> map;
    for (int i : lst) {
        int n = i > 0 ? i : i * -1;
        for (int j = 2; j <= n; j++) {
            if (n % j == 0) {
                map[j] += i;
            }
            while (n % j == 0) {
                n /= j;
            }
        }
    }
    std::string result = "";
    for (auto it = map.begin(); it != map.end(); ++it) {
        result += "(" + std::to_string(it->first) + " " + std::to_string(it->second) + ")";
    }
    return result;
}


int main() {
    SumOfDivided sum;
    std::cout << sum.sumOfDivided({ 12,15, 24 }) << "\n";
}