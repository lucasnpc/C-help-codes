#include <string>
#include <iostream>
#include <map>
#include <cstring>
#include <algorithm>

class Mix
{
public:
    static std::string mix(const std::string& s1, const std::string& s2);
};

std::string Mix::mix(const std::string& s1, const std::string& s2) {
    std::map<char, int> map, map2;
    std::string result, result2, mixedStr;

    for (auto& c : s1) {
        if (isalpha(c) && islower(c)) {
            result += c;
            map[c]++;
        }
    }
    for (auto& c : s2) {
        if (isalpha(c) && islower(c)) {
            result2 += c;
            map2[c]++;
        }
    }

    mixedStr = result + result2;

    std::string distictResult;

    for (char c : mixedStr) {
        if (distictResult.find(c) == std::string::npos && (map[c] > 1 || map2[c] > 1))
        {
            distictResult += c;
        }
    }

    std::sort(distictResult.begin(), distictResult.end(), [&map, &map2](char a, char b) {
        if (map[a] == map[b])
        {
            return map[a] < map[b];
        }
        return map[a] > map[b];
        });

    std::sort(distictResult.begin(), distictResult.end(), [&map, &map2](char a, char b) {
        if (map2[a] == map2[b])
        {
            return map2[a] < map2[b];
        }
        return map2[a] > map2[b];
        });

    std::cout << "Distinct: " << distictResult << "\n";

    result = "";

    for (auto c : distictResult) {
        if (map[c] > map2[c]) {
            result += "1:";
            for (int i = 0; i < map[c]; ++i) {
                result += c;
            }
            result += "/";
        }
        else if (map2[c] > map[c]) {
            result += "2:";
            for (int i = 0; i < map2[c]; ++i) {
                result += c;
            }
            result += "/";
        }
        else {
            result += "=:";
            for (int i = 0; i < map2[c]; ++i) {
                result += c;
            }
            result += "/";
        }
    }

    return result.substr(0, result.size() - 1);
}

int main() {
    Mix mix;
    std::cout << mix.mix("eeee bbb dd yyyyy jj ccc", "eeee bbb dd yyyyy jj ccc uuu") << "\n";
    return 0;
}