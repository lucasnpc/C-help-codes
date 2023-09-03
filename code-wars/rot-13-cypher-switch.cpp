#include <string>
#include <iostream>

std::string rot13(std::string&& msg)
{
    for (auto& c : msg) {
        switch (c) {
        case 'A'...'M': case 'a'...'m': c += 13; break;
        case 'N'...'Z': case 'n'...'z': c -= 13; break;
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