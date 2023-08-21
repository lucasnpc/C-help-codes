#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

int score(std::vector<int> dices) {
    int score = 0;
    std::sort(dices.begin(), dices.end());
    std::map<int, int> triplicatesCount;
    int previousDice = -1;
    for (auto& dice : dices)
    {
        triplicatesCount[dice] = 1;
    }
    for (auto& dice : dices) {
        if (previousDice == dice) {
            ++triplicatesCount[dice];
        }
        previousDice = dice;
    }
    for (auto& dice : triplicatesCount)
    {
        switch (dice.first)
        {
        case 1:
            if (dice.second == 3)
            {
                score += 1000;
            }
            else if (dice.second > 3) {
                score += 1000;
                for (int i = 3; i < dice.second;++i) {
                    std::cout << dice.second << "\n";
                    score += 100;
                }
            }
            else {
                for (int i = 1; i <= dice.second;++i)
                    score += 100;
            }

            break;
        case 2:
            if (dice.second >= 3)
            {
                score += 200;
            }
            break;
        case 3:
            if (dice.second >= 3)
            {
                score += 300;
            }
            break;
        case 4:
            if (dice.second >= 3)
            {
                score += 400;
            }
            break;
        case 5:
            if (dice.second == 3)
            {
                score += 500;
            }
            else if (dice.second > 3) {
                score += 500;
                for (int i = 3; i < dice.second;++i)
                    score += 50;
            }
            else {
                for (int i = 1; i <= dice.second;++i)
                    score += 50;
            }
            break;
        case 6:
            if (dice.second >= 3)
            {
                score += 600;
            }
            break;

        default:
            break;
        }
    }

    return score; // your code here
}

int main() {


    std::cout << score({ 2, 3, 4, 6, 2 }) << "\n";
    std::cout << score({ 2, 4, 4, 5, 4 }) << "\n";
    std::cout << score({ 1, 1, 1, 1, 3 }) << "\n";

    std::cin.get();

    return 0;
}