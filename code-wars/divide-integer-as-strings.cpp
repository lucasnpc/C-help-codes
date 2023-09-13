#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <cmath>
#include <thread>
#include <chrono>

std::string calculator(std::string dividend, std::string divisor) {
    std::string remainder = "0";
    std::string quotient;
    double n1, n2;

    while (stod(dividend) > stod(divisor)) {
        auto substr = dividend.substr(0, divisor.length());
        if (stod(substr) < stod(divisor)) {
            substr = dividend.substr(0, divisor.length() + 1);
        }
        n1 = floor(stod(substr) / stod(divisor));
        std::string n1Str = std::to_string(n1);

        n2 = n1 * stod(divisor);

        auto new_value = std::to_string(floor(stod(substr) - n2));
        size_t pos = new_value.find(".");
        std::string result = new_value.substr(0, pos);
        remainder = result;

        std::string old;

        for (int i = 0; i <= result.length(); i++) {
            old += dividend[i];
        }

        pos = dividend.find(old);
        if (pos != std::string::npos) {
            dividend.replace(pos, old.length(), result);
        }
        // std::this_thread::sleep_for(std::chrono::seconds(1));
        if (dividend.length() > substr.length()) {
            quotient += n1Str.substr(0, n1Str.find("."));
        }
        else {
            quotient += "0";
            dividend.replace(dividend.begin(), dividend.end(), n1Str.substr(0, n1Str.find(".")));
            quotient += dividend;
            break;
        }
    }

    return remainder;
}

std::vector<std::string> divide_strings(std::string a, std::string b) {
    double i = stod(a);
    double j = stod(b);

    std::string quotient = std::to_string(floor(i / j));
    std::string remainder = calculator(a, b);

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
    // a = "824184506754425441885550386902068711384244347556631637842744035808271763524468";
    // b = "1240917384358273563";
    // for (auto& i : divide_strings(a, b)) {
    //     std::cout << i << "\n";
    // }
    a = "17617634995535209756";
    b = "3555707449";
    for (auto& i : divide_strings(a, b)) {
        std::cout << i << "\n";
    }
}
