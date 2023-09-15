#include <string>
#include <vector>
#include <map>
#include <iostream>

class SumOfDivided
{
public:
    static std::string sumOfDivided(const std::vector<int>& lst);
};

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

std::string SumOfDivided::sumOfDivided(const std::vector<int>& lst) {
    std::map<int, int> map;
    for (int i : lst) {
        int n = i > 0 ? i : i * -1;
        for (int j = 2; j <= n; j++) {
            if (!isPrime(j))
            {
                continue;
            }
            while (n % j == 0) {
                map[j] += i;
                int tmp = n;
                n /= j;
                if (n * j == tmp)
                    break;
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