#include <string>
#include <iostream>

std::string rot13(std::string&& msg)
{
    for (auto& c : msg) {
        if (isalpha(c)) {
            if (islower(c)) {
                c = (((c - 'a') + 13) % 26) + 'a';
            }
            else {
                c = (((c - 'A') + 13) % 26) + 'A';
            }
        }
    }
    return msg;
}

int main() {
    std::cout << rot13("test") << "\n";
    std::cout << rot13("Test") << "\n";
    std::cout << rot13("AbCd") << "\n";
    return 0;
}