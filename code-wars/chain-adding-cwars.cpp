#include <iostream>

class Adder {
public:
    Adder(int value) : sum(value) {}

    Adder operator()(int value) {
        return Adder(sum + value);
    }

    bool operator== (int n) { return sum == n; }
    int operator+ (int n) { return sum + n; }
    int operator- (int n) { return sum - n; }
    friend bool operator== (int n, const Adder& y) { return n == y.sum; }


private:
    int sum;
};
auto add(int n)
{
    return Adder(n);
}

int main() {
    std::cout << add(1)(2)(3) << "\n";
    std::cout << add(1)(2)(3)(4) << "\n";
    std::cout << add(1)(2)(3)(4)(5) << "\n";
    return 0;
}
