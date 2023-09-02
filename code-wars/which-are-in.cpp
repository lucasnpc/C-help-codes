#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class WhichAreIn
{

public:
    static std::vector<std::string> inArray(std::vector<std::string>& array1, std::vector<std::string>& array2);
};

std::vector<std::string> WhichAreIn::inArray(std::vector<std::string>& array1, std::vector<std::string>& array2) {
    auto it = std::remove_if(array1.begin(), array1.end(), [&](std::string str) {
        for (auto str2 : array2) {
            if (str2.find(str) != std::string::npos) {
                return false;
            }
        }
        return true;
        });

    array1.erase(it, array1.end());
    std::sort(array1.begin(), array1.end());
    return array1;
}

int main() {
    std::vector<std::string> arr1 = { "arp", "live", "strong" };
    std::vector<std::string> arr2 = { "lively", "alive", "harp", "sharp", "armstrong" };

    WhichAreIn areIn;

    for (auto& c : areIn.inArray(arr1, arr2)) {
        std::cout << c << "\n";
    }

    return 0;
}