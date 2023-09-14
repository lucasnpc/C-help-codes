#include <iostream>
#include <vector>
#include <string>
#include <cmath>

std::vector<std::string> divide_strings(std::string a, std::string b) {
    double i = stod(a);
    double j = stod(b);
    unsigned long long max = std::numeric_limits<unsigned long long>::max();

    if (i < max && j < max)
    {
        return std::vector<std::string> {std::to_string(stoull(a) / stoull(b)), std::to_string(stoull(a) % stoull(b))};
    }

    std::string quotient = std::to_string(floor((i / j)));
    std::string remainder = std::to_string(i - (floor(i / j) * j));

    return { quotient.substr(0, quotient.find('.')), remainder.substr(0, remainder.find('.')) };
}

int main() {
    std::string a = "14598499948265358486";
    std::string b = "487";
    for (auto& i : divide_strings(a, b)) {
        std::cout << i << "\n";
    }
    a = "65321";
    b = "31";
    for (auto& i : divide_strings(a, b)) {
        std::cout << i << "\n";
    }
    a = "28906175119824210591245626458349277847809252";
    b = "3067375543061679371211619111355555580173898605";
    for (auto& i : divide_strings(a, b)) {
        std::cout << i << "\n";
    }
    a = "17617634995535209756";
    b = "3555707449";
    for (auto& i : divide_strings(a, b)) {
        std::cout << i << "\n";
    }
}
