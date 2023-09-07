#include <string>
#include <iostream>
#include <map>
#include <cstring>
#include <algorithm>
#include <set>

class Mix
{
public:
    static std::string mix(const std::string& s1, const std::string& s2);
};

std::string Mix::mix(const std::string& s1, const std::string& s2) {
    std::map<char, int> map, map2;
    std::set<char> set1, set2;
    std::string result;

    for (auto& c : s1) {
        if (isalpha(c) && islower(c)) {
            set1.insert(c);
            map[c]++;
        }
    }
    for (auto& c : s2) {
        if (isalpha(c) && islower(c)) {
            set2.insert(c);
            map2[c]++;
        }
    }

    std::set<char, std::function<bool(char, char)>> mixedSet([&map, &map2](char a, char b) {
        if (map[a] == map2[a] || map[a] == map[b] || map2[a] == map2[b]) {
            return a < b;
        }
        else if (map[a] > map[b] || map2[a] > map2[b]) {
            return map[a] < map[b] || map2[a] < map2[b];
        }
        return a > b;
        });

    for (auto& c : set1) {
        if (map[c] > 1) {
            mixedSet.insert(c);
        }
    }

    for (auto& c : set2) {
        if (map2[c] > 1) {
            mixedSet.insert(c);
        }
    }

    for (auto c : mixedSet) {
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
    std::cout << mix.mix("eeee bbb rr hh dd yyyyy jj ccc", "eeee bbb rr hh dd yyyyy jj ccc uuu") << "\n";
    std::cout << mix.mix("ooo uuu", "sss") << "\n";
    std::cout << mix.mix("rr hh", "eeeee yy rr hh") << "\n";
    std::cout << mix.mix("ooo uuu nnn ii gg", "sss nnn aa dd ee gg") << "\n";
    return 0;
}