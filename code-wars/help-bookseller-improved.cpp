#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <map>

class StockList
{
public:
    static std::string stockSummary(std::vector<std::string>& lstOfArt, std::vector<std::string>& categories);
};

std::string StockList::stockSummary(std::vector<std::string>& lstOfArt, std::vector<std::string>& categories) {
    if (lstOfArt.empty() || categories.empty()) return "";

    std::map<char, int> sum;

    for (auto i : lstOfArt) {
        sum[i[0]] += std::stoi(i.substr(i.find(" ")));
    }

    std::string result = "";
    for (auto i : categories) {
        std::cout << i << "\n";
        result = result
            + (result.empty() ? "" : " - ")
            + "(" + i + " : " + std::to_string(sum[i[0]]) + ")";
    }

    return result;
}

int main() {
    std::vector<std::string> art = { "ABAR 200", "CDXE 500", "BKWR 250", "BTSQ 890", "DRTY 600" };
    std::vector<std::string> cd = { "A", "B" };

    StockList stock;

    std::cout << stock.stockSummary(art, cd) << "\n";

    art = { "BBAR 150", "CDXE 515", "BKWR 250", "BTSQ 890", "DRTY 600" };
    cd = { "A", "B", "C", "D" };

    std::cout << stock.stockSummary(art, cd) << "\n";

    return 0;
}