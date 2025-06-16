#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

constexpr int mgcd(int a, int b) {
    while (a > 0 && b > 0) {
        if (a > b) {
            a = a % b;
        }
        else {
            b = b % a;
        }
    }
    if (a == 0) {
        return b;
    }
    return a;
}

void min_remainder_table(std::vector<long long>& vec, const std::vector<long long>& b) {
    vec[0] = 0;
    for (int i = 1; i < b.size(); i++) {
        int d = mgcd(b[0], b[i]);
        for (int j = 0; j < d; j++) {
            long long min_remainder;
            bool found, first;
            found = false;
            first = true;
            for (int k = j; k < b[0]; k += d) {
                if (vec[k] != -1) {
                    found = true;
                    if (first) {
                        min_remainder = vec[k];
                        first = false;
                    }
                    min_remainder = std::min(min_remainder, vec[k]);
                }
            }
            if (found) {
                for (int k = 0; k < b[0] / d; k++) {
                    min_remainder = min_remainder + b[i];
                    long long r = min_remainder % b[0];
                    min_remainder = (vec[r] == -1 ? min_remainder : std::min(min_remainder, vec[r]));
                    vec[r] = min_remainder;
                }
            }
        }
    }
}


int main() {
    long long recipes_num = 0;
    std::cin >> recipes_num;
    std::vector<long long> buttons(3);
    std::cin >> buttons[0] >> buttons[1] >> buttons[2];
    std::sort(buttons.begin(), buttons.end());
    if (recipes_num <= buttons[0]) {
        std::cout << 1;
        return 0;
    }
    std::vector<long long> vec(buttons[0], -1);
    min_remainder_table(vec, buttons);
    long long sum = recipes_num;
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] > -1) {
            if (recipes_num <= vec[i]) {
                sum -= recipes_num / buttons[0];
                if (i < recipes_num % buttons[0]) {
                    sum--;
                }
            }
            else {
                sum -= vec[i] / buttons[0];
            }
        }
        else {
            if (i < recipes_num % buttons[0]) {
                sum--;
            }
            sum -= recipes_num / buttons[0];
        }
    }
    std::cout << sum;


    return 0;
}