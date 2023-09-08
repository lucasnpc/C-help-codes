#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <set>
#include <numeric>

class Mix
{
public:
    static std::string mix(const std::string& s1, const std::string& s2);
};

std::unordered_map<char, int> counter(std::string s) {
    std::unordered_map<char, int> x;
    std::sort(s.begin(), s.end());
    for (auto c : s) {
        if (isalpha(c)) {
            x[c]++;
        }
    }
    return x;
}

std::string Mix::mix(const std::string& s1, const std::string& s2) {
    std::unordered_map<char, int> set1 = counter(s1);
    std::unordered_map<char, int> set2 = counter(s2);
    std::vector<std::string> res;
    std::set<char> keys;
    for (auto& c : s1) {
        if (isalpha(c) && islower(c)) {
            keys.insert(c);
        }
    }
    for (auto& c : s2) {
        if (isalpha(c) && islower(c)) {
            keys.insert(c);
        }
    }
    for (auto& key : keys) {
        auto c1 = set1[key];
        auto c2 = set2[key];
        auto count = std::max(c1, c2);
        if (count > 1) {
            auto from = count > c1 ? '2' : count > c2 ? '1' : '=';
            auto str = std::string(count, key);
            res.emplace_back(std::string(1, from) + ":" + str);
        }
    }
    std::sort(res.begin(), res.end(), [](const auto& a, const auto& b) {
        return a.size() == b.size() ? a < b : a.size() > b.size();
        });
    return std::accumulate(res.begin(), res.end(), std::string(""), [](const auto& a, const auto& b) {
        return a.empty() ? b : a + "/" + b;
        });
}

int main() {
    Mix mix;
    std::cout << mix.mix("eeee DDE bbb rr hh dd yyyyy jj ccc", "eeee bbb rr hh dd yyyyy jj ccc uuu") << "\n";
    std::cout << mix.mix("ooo uuu", "sss") << "\n";
    std::cout << mix.mix("rr hh", "eeeee yy rr hh") << "\n";
    std::cout << mix.mix("ooo uuu nnn ii gg", "sss nnn aa dd ee gg") << "\n";
    return 0;
}