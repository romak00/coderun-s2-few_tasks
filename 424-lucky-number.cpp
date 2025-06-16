

// https://coderun.yandex.ru/seasons/2024-summer/tracks/backend/problem/lucky-number?currentPage=1&pageSize=20


#include <iostream>
#include <string>
#include <vector>

void nine_prob(std::string& s, int i, int* hs) {
    while (s[i] == '9') {
        s[i] = '0';
        i--;
        *hs -= 9;
    }
    s[i] = s[i] + 1;
    *hs += 1;
}

void recalc1(std::string& s, int fhs, int shs, int n, int i) {
    int j = n - 1;
    while (shs < fhs) {
        int dif = fhs - shs;
        if (dif / 9 > 0) {
            s[j] = '9';
        }
        else {
            s[j] = (dif % 9) + '0';
        }
        shs += s[j] - '0';
        j--;
    }
    while (j > i) {
        s[j] = '0';
        j--;
    }
}

void recalc2(std::string& s, int fhs, int shs, int n) {
    int j = n - 1;
    while (shs < fhs) {
        int dif = fhs - shs;
        int tmp;
        if (dif / 9 > 0) {
            tmp = s[j] - '0';
            s[j] = '9';
            shs += 9 - tmp;
        }
        else {
            if (s[j] - '0' + dif % 9 <= 9) {
                s[j] += dif % 9;
                shs += dif % 9;
            }
            else {
                tmp = s[j] - '0';
                s[j] = '9';
                shs += 9 - tmp;
            }
        }
        j--;
    }
}

int main() {
    std::string s;
    std::cin >> s;
    int n = s.size(), first_half_sum = 0;
    for (int i = 0; i < n / 2; ++i) {
        first_half_sum += s[i] - '0';
    }
    int second_half_sum = 0;
    for (int k = n / 2; k < n; ++k) {
        second_half_sum += s[k] - '0';
    }

    if (first_half_sum == n / 2 * 9 && second_half_sum == n / 2 * 9) {
        for (int i = 0; i < n; ++i) {
            if (i == n / 2 - 1 || i == n - 1) {
                s[i] = '1';
            }
            else {
                s[i] = '0';
            }
        }
        std::cout << s;
        return 0;
    }

    second_half_sum = 0;
    int i = n / 2;
    while ((second_half_sum + (s[i] - '0') < first_half_sum) && (i < n)) {
        second_half_sum += s[i] - '0';
        ++i;
    }
    i--;
    if (i == n / 2 - 1) {
        if (s[i] == '9') {
            nine_prob(s, i, &first_half_sum);
            second_half_sum = 0;
            recalc1(s, first_half_sum, second_half_sum, n, i);
        }
        else {
            s[i] = s[i] + 1;
            first_half_sum++;
            second_half_sum = 0;
            recalc1(s, first_half_sum, second_half_sum, n, i);
        }
    }
    else if (i != n - 1) {
        if (s[i] == '9') {
            int k = i;
            while (s[k] == '9' && k >= n / 2) {
                s[k] = '0';
                k--;
                second_half_sum -= 9;
            }
            if (k == n / 2 - 1) {
                nine_prob(s, k, &first_half_sum);
            }
            else {
                s[k] = s[k] + 1;
                second_half_sum++;
            }
            recalc1(s, first_half_sum, second_half_sum, n, i);
        }
        else {
            s[i] = s[i] + 1;
            second_half_sum++;
            recalc1(s, first_half_sum, second_half_sum, n, i);
        }
    }
    else {
        recalc2(s, first_half_sum, second_half_sum, n);
    }






    std::cout << s;





    return 0;
}