#include <iostream>
#include <string>
#include <vector>

using namespace std;

string multiply(string a, string b) {
    string res = "";
    int m = a.size(), n = b.size();
    vector<int> vals(m + n);
    for (int i = m - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; --j) {
            int mul = (a[i] - '0') * (b[j] - '0');
            int p1 = i + j, p2 = i + j + 1, sum = mul + vals[p2];
            vals[p1] += sum / 10;
            vals[p2] = sum % 10;
        }
    }
    for (int val : vals) {
        if (!res.empty() || val != 0) res.push_back(val + '0');
    }
    return res.empty() ? "0" : res;
}

int main() {
    std::cout << multiply("4", "7") << "\n"; // Output: 8
    std::cout << multiply("1020303004875647366210", "2774537626200857473632627613") << "\n"; // Output: 8
    return 0;
}