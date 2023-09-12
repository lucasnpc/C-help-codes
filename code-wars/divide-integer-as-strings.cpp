#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <cmath>

std::vector<std::string> divide_strings(std::string a, std::string b) {
    std::vector<int> vec;
    double mod = 0;

    if (a.size() < b.size() || (a.size() == b.size() && a < b)) {
        return std::vector<std::string>{"0", a};
    }

    for (int i = 0; i < a.size(); i++) {
        int digit = a[i] - '0';

        mod = mod * 10 + digit;

        int quo = mod / stod(b);
        vec.emplace_back(quo);

        mod = std::fmod(mod, stod(b));
    }

    bool zeroflag = 0;
    std::string quo = std::accumulate(vec.begin(), vec.end(), std::string{}, [&zeroflag](std::string acc, const int b) {
        if (b == 0 && zeroflag == 0)
        {
            return std::string{};
        }
        zeroflag = 1;
        return acc + std::to_string(b);
        });
    std::string rem = std::to_string(mod);

    std::size_t pos = rem.find_last_not_of('0');
    if (pos != std::string::npos && rem[pos] == '.') {
        pos--;
    }

    return std::vector<std::string> {quo, rem.substr(0, pos + 1)};
}

int main() {
    std::string a = "14598499948265358486";
    std::string b = "487";
    for (auto& i : divide_strings(a, b)) {
        std::cout << i << "\n";
    }
    a = "73713414537045550767556613957240347422074176722472822985928212329418599289665231075441886606582404249483210115597262171";
    b = "824184506754425441885550386902068711384244347556631637842744035808271763524468";
    for (auto& i : divide_strings(a, b)) {
        std::cout << i << "\n";
    }
    a = "96472599535598471174723621774994230277708277160050667689559972273574038713881008674036358544691299913956889106376082735039975126251450864239031789734765516947560756493728821";
    b = "665095873416432946566410341164950740222195695035507982269";
    for (auto& i : divide_strings(a, b)) {
        std::cout << i << "\n";
    }
}
