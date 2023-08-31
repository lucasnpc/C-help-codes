#include <vector>
#include <iostream>

int findOdd(const std::vector<int>& numbers) {
    int result = 0;
    for (auto& num : numbers) {
        std::cout << "Before: " << result << "\n";
        result = result ^ num;
        std::cout << "After: " << result << "\n";
    }
    return result;
}

int main() {
    std::vector<int> v1 = { 20,1,-1,2,-2,3,3,5,5,1,2,4,20,4,-1,-2,5 };
    std::cout << "Normal: " << findOdd(v1) << "\n";
    std::vector<int> vBugged = { 20,1,-1,2,-2 };
    std::cout << "\nBugged: " << findOdd(vBugged) << "\n";


    std::cout << "\nUnderstand bitwise XOR operation: " << "\n";
    int a = 8;
    int b = 3;
    int c = a ^ b;

    std::cout << c << "\n";

    return 0;
}