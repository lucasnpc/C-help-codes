#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <unordered_map>

class StockList
{
public:
    static std::string stockSummary(std::vector<std::string>& lstOfArt, std::vector<std::string>& categories);
};

std::string StockList::stockSummary(std::vector<std::string>& lstOfArt, std::vector<std::string>& categories) {
    std::string mountedString = "";

    if (categories.empty() || lstOfArt.empty())
    {
        return mountedString;
    }

    std::vector<std::pair<std::string, int>> booksCategories;
    for (auto& cat : categories) {
        booksCategories.emplace_back(cat, 0);
    }
    for (auto& list : lstOfArt) {
        for (auto& cat : categories) {
            if (list[0] == cat[0])
            {
                int value;
                std::string x;
                std::istringstream stream(list);
                if (stream >> x >> value)
                {
                    for (auto& it : booksCategories) {
                        if (it.first == cat)
                            it.second += value;
                    }
                }
            }
        }
    }

    auto it = booksCategories.begin();
    while (it != booksCategories.end())
    {
        mountedString.append("(").append(it->first).append(" : ").append(std::to_string(it->second)).append(")");
        ++it;
        if (it == booksCategories.end())
        {
            break;
        }

        mountedString.append(" - ");
    }
    return mountedString;
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