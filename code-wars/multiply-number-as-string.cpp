#include <iostream>
#include <string>
#include <vector>

using namespace std;

string multiply(string a, string b) {
    int len1 = a.size();
    int len2 = b.size();
    if (len1 == 0 || len2 == 0)
        return "0";

    // will keep the result number in vector
    // in reverse order
    vector<int> result(len1 + len2, 0);

    // Below two indexes are used to find positions
    // in result.
    int i_n1 = 0;
    int i_n2 = 0;

    // Go from right to left in a
    for (int i = len1 - 1; i >= 0; i--)
    {
        int carry = 0;
        int n1 = a[i] - '0';

        // To shift position to left after every
        // multiplication of a digit in b
        i_n2 = 0;

        // Go from right to left in b            
        for (int j = len2 - 1; j >= 0; j--)
        {
            // Take current digit of second number
            int n2 = b[j] - '0';

            // Multiply with current digit of first number
            // and add result to previously stored result
            // at current position.
            int sum = n1 * n2 + result[i_n1 + i_n2] + carry;

            // Carry for next iteration
            carry = sum / 10;

            // Store result
            result[i_n1 + i_n2] = sum % 10;

            i_n2++;
        }

        // store carry in next cell
        if (carry > 0)
            result[i_n1 + i_n2] += carry;

        // To shift position to left after every
        // multiplication of a digit in num1.
        i_n1++;
    }

    // ignore '0's from the right
    int i = result.size() - 1;
    while (i >= 0 && result[i] == 0)
        i--;

    // If all were '0's - means either both or
    // one of num1 or num2 were '0'
    if (i == -1)
        return "0";

    // generate the result string
    string s = "";

    while (i >= 0)
        s += std::to_string(result[i--]);

    return s;
}

int main() {
    std::cout << multiply("4", "7") << "\n"; // Output: 8
    std::cout << multiply("1020303004875647366210", "2774537626200857473632627613") << "\n"; // Output: 8
    return 0;
}