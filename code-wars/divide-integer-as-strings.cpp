#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <cmath>

std::vector<std::string> divide_strings(std::string a, std::string b) {
    double i = stod(a);
    double j = stod(b);

    std::string quotient = std::to_string(i / j);
    std::string remainder = std::to_string(std::fmod(i, j));

    return { quotient.substr(0, quotient.find('.')), remainder.substr(0, remainder.find('.')) };
}

int main() {
    std::string a = "14598499948265358486";
    std::string b = "487";
    for (auto& i : divide_strings(a, b)) {
        std::cout << i << "\n";
    }
    // a = "73713414537045550767556613957240347422074176722472822985928212329418599289665231075441886606582404249483210115597262171";
    // b = "824184506754425441885550386902068711384244347556631637842744035808271763524468";
    // for (auto& i : divide_strings(a, b)) {
    //     std::cout << i << "\n";
    // }
    a = "17749693628473883541";
    b = "1932314054";
    for (auto& i : divide_strings(a, b)) {
        std::cout << i << "\n";
    }
}
