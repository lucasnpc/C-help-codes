#include <string>
#include <vector>
#include <iostream>

std::vector<std::string> solution(const std::string& s)
{
    std::vector<std::string> vec;
    int n = s.length();
    int d = s[1] - s[0];
    int i = 0;
    while (i < n) {
        std::string str = "";
        str += s[i];
        i++;
        if (i < n) {
            str += s[i];
            i++;
        }
        else {
            str += "_";
        }
        vec.emplace_back(str);
        d += d;
    }

    return vec;
}

int main() {

    auto solution1 = solution("HelloWorld");
    auto solution2 = solution("abcdef");
    std::cout << "Solution 1" << "\n";
    for (auto& i : solution1)
    {
        std::cout << i << "\n";
    }
    std::cout << "\nSolution 2" << "\n";
    for (auto& i : solution2)
    {
        std::cout << i << "\n";
    }


    return 0;
}