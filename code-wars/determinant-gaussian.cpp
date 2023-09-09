#include <iostream>
#include <vector>
#include <cmath>

long long determinant(std::vector< std::vector<long long> > m) {

    std::vector<std::vector<double>> dm;

    for (auto v : m) {
        std::vector<double> temp;
        for (auto n : v) {
            temp.emplace_back(static_cast<double>(n));
        }
        dm.emplace_back(temp);
    }

    size_t pivotIndex = 0;
    double ans = 1;
    for (auto it = dm.begin(); it != dm.end(); ++it, ++pivotIndex) {
        auto minNotZero_it = dm.end();
        for (auto i = it; i != dm.end(); ++i) {
            if ((*i)[pivotIndex] != 0 && (minNotZero_it == dm.end() || abs((*i)[pivotIndex]) < abs((*minNotZero_it)[pivotIndex])))
            {
                minNotZero_it = i;
            }
        }
        if (minNotZero_it == dm.end())
            return 0;
        else if (minNotZero_it != it) {
            swap(*it, *minNotZero_it);
            ans *= -1;
        }

        for (auto iv = it + 1; iv != dm.end(); ++iv) {
            double original = (*iv)[pivotIndex];
            for (size_t idx = pivotIndex; idx < dm.size(); ++idx) {
                (*iv)[idx] -= original / (*it)[pivotIndex] * (*it)[idx];
            }
        }
    }


    for (size_t i = 0; i < dm.size(); ++i) {
        ans *= dm[i][i];
    }

    return static_cast<long long>(round(ans));
}

int main() {
    std::cout << determinant(std::vector<std::vector<long long> > {
        std::vector<long long> {1, 3},
            std::vector<long long> {2, 5}
    }) << "\n";
    std::cout << determinant(std::vector<std::vector<long long> > {
        std::vector<long long> {2, 5, 3},
            std::vector<long long> {1, -2, -1},
            std::vector<long long> {1, 3, 4}
    }) << "\n";

    return 0;
}