#include<iostream>
#include <cmath>
#include <chrono>
#include <vector>

long countDivisors(const long& n) {
    long sum = 0;
    long sqrt_n = std::sqrt(n);

    for (long i = 1; i <= sqrt_n; ++i) {
        sum += n / i;
    }

    for (long i = sqrt_n + 1; i <= n; ++i) {
        sum += n / i;
    }

    return sum;
}

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    std::cout << countDivisors(1) << "\n";
    std::cout << countDivisors(2) << "\n";
    std::cout << countDivisors(3) << "\n";
    std::cout << countDivisors(4) << "\n";
    std::cout << countDivisors(5) << "\n";
    std::cout << countDivisors(6) << "\n";
    std::cout << countDivisors(10) << "\n";
    // std::cout << countDivisors(13234254043) << "\n";
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "Time taken by function: " << duration.count() << " microseconds" << std::endl;
}