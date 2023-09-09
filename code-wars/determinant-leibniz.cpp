#include <iostream>
#include <vector>
#include <cmath>

long long determinant(std::vector<std::vector<long long> > m) {
    long long det = 0;
    if (m.size() == 1) {
        return m[0][0];
    }
    else if (m.size() == 2) {
        det = (m[0][0] * m[1][1] - m[0][1] * m[1][0]);
        return det;
    }
    else {
        for (int p = 0; p < m.size(); p++) {
            int h = 0, k = 0;
            std::vector<std::vector<long long>> temp(m.size() - 1, std::vector<long long>(m.size() - 1));
            for (int i = 1; i < m.size(); i++) {
                for (int j = 0; j < m.size(); j++) {
                    if (j == p) {
                        continue;
                    }
                    temp[h][k] = m[i][j];
                    k++;
                    if (k == m.size() - 1) {
                        h++;
                        k = 0;
                    }
                }
            }
            det += m[0][p] * pow(-1, p) * determinant(temp);
        }
        return det;
    }
}

int main() {
    std::cout << determinant(std::vector<std::vector<long long> > {
        std::vector<long long> {1, 3},
            std::vector<long long> {2, 5}
    }) << "\n";
    std::cout << determinant(std::vector<std::vector<long long> > {
        std::vector<long long> {2, 5, 3},
            std::vector<long long> {1, -2, -1},
            std::vector<long long> {1, 3, 4}
    }) << "\n";

    return 0;
}

