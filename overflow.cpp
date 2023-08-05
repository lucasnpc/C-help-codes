#include <iostream>

void MyFunc()
{
    int k = 3;
    std::cout << "k:" << &k << "\n";
    MyFunc();
}

int main()
{
    int i = 1;
    std::cout << "i:" << &i << "\n";

    int j = 2;
    std::cout << "j:" << &j << "\n";

    MyFunc();

    int l = 4;
    std::cout << "l:" << &l << "\n";

    return 0;
}