#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <iomanip>
#include <string_view>

int main()
{
    std::string_view X{ "1ACCGGTCGAGTGCGCGGAAGCCGGCCGAA" };
    std::string_view Y{ "2GTCGTTCGGAATGCCGTTGCTCTGTAAA" };

    std::vector<std::vector<int>> c;
    std::vector<std::vector<int>> b; // 0 - left; 1 - up; 2- upleft

    std::vector<int> c_i(Y.size());
    std::vector<int> b_i(Y.size());

    for (auto i = 0; i < X.size(); ++i) {
        c.push_back(c_i);
        b.push_back(b_i);
    }

    for (auto i = 1; i < X.size(); ++i) {
        for (auto j = 1; j < Y.size(); ++j) {
            if (X[i] == Y[j]) {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 2;
            }
            else {
                if (c[i - 1][j] > c[i][j - 1]) {
                    c[i][j] = c[i - 1][j];
                    b[i][j] = 1;
                }
                else {
                    c[i][j] = c[i][j - 1];
                    b[i][j] = 0;
                }
            }
        }
    }

    bool iterate = true;

    int k = X.size() - 1;
    int l = Y.size() - 1;

    std::string lcs = "";

    while (iterate) {
        switch (b[k][l]) {
        case 0:
            l--;
            break;
        case 1:
            k--;
            break;
        case 2:
            lcs = X[k] + lcs;
            k--;
            l--;
            break;
           
        }
        if (k == 0 || l == 0) {
            iterate = false;
        }
    }

    for (auto i = 0; i < c.size(); ++i) {
        for (auto j = 0; j < c[i].size(); ++j) {
            std::cout <<std::setw(3)<< c[i][j];
        }
        std::cout << std::endl;
    }

    std::cout << std::endl << std::endl;

    std::cout << "X: " << X << std::endl;
    std::cout << "Y: " << Y << std::endl<< std::endl;


    std::cout << std::endl;
    std::cout << "LCS: " << lcs << std::endl << std::endl;
}

