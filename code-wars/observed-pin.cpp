#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

std::vector<std::string> get_pins(std::string observed) {
    std::map<char, std::vector<std::string>> possibles = {
        {'1', {"1", "2", "4"}},
        {'2', {"1", "2", "3", "5"}},
        {'3', {"2", "3", "6"}},
        {'4', {"1", "4", "5", "7"}},
        {'5', {"2", "4", "5", "6", "8"}},
        {'6', {"3", "5", "6", "9"}},
        {'7', {"4", "7", "8"}},
        {'8', {"5", "7", "8", "9", "0"}},
        {'9', {"6", "8", "9"}},
        {'0', {"0", "8"}} };

    std::vector<std::string> result(possibles[observed[0]]);
    for (int i = 1; i < observed.size(); i++) {
        std::vector<std::string> temp;
        for (int j = 0; j < possibles[observed[i]].size(); j++) {
            for (int k = 0; k < result.size(); k++) {
                temp.emplace_back(result[k] + possibles[observed[i]][j]);
            }
        }
        result = temp;
    }
    return result;
}

int main() {
    std::vector<std::string> pins = get_pins("8");
    std::sort(pins.begin(), pins.end(), [](const auto& a, const auto& b) {
        return  a < b;
        });

    for (auto& p : pins) {
        std::cout << p << " ";
    }
    std::cout << "\n";

    pins = get_pins("11");
    std::sort(pins.begin(), pins.end(), [](const auto& a, const auto& b) {
        return  a < b;
        });

    for (auto& p : pins) {
        std::cout << p << " ";
    }
    std::cout << "\n";

    pins = get_pins("369");
    std::sort(pins.begin(), pins.end(), [](const auto& a, const auto& b) {
        return  a < b;
        });

    for (auto& p : pins) {
        std::cout << p << " ";
    }
    std::cout << "\n";
}