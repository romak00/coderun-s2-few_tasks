#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string s1, s2, s3;
    std::cin >> s1 >> s2 >> s3;

    if (s1.size() == 0 || s2.size() == 0 || s3.size() == 0) {
        if (s1.size() == 0 && s2.size() == 0 && s3.size() == 0) {
            std::cout << "";
        }
        else {
            std::cout << "IMPOSSIBLE";
        }
        return 0;
    }

    char p1 = s1[0], p2 = s2[0], p3 = s3[0], t = s1[0];
    auto i = s1.begin(), j = s2.begin(), k = s3.begin();
    int tmp1 = 0, tmp2 =0, tmp3 =0;
    std::string ans;
    while (i != s1.end() || j!=s2.end() || k!=s3.end()) {
        if (p1 != p2 || p1 != p3 || p2 != p3) {
            std::cout << "IMPOSSIBLE";
            return 0;
        }
        while (i != s1.end() && *i == p1) {
            tmp1++;
            i++;
        }
        if (i != s1.end()) {
            p1 = *i;
        }

        while (j != s2.end() && *j == p2) {
            tmp2++;
            j++;
        }
        if (j != s2.end()) {
            p2 = *j;
        }

        while (k != s3.end() && *k == p3) {
            tmp3++;
            k++;
        }
        if (k != s3.end()) {
            p3 = *k;
        }

        int a = tmp1 + tmp2 + tmp3 - std::max(tmp1, std::max(tmp2, tmp3)) - std::min(tmp1, std::min(tmp2, tmp3));
        for (int b = 0; b < a; b++) {
            ans.push_back(t);
        }
        tmp1 = 0; tmp2 = 0; tmp3 = 0;
        t = p1;
    }
    std::cout << ans;

    return 0;
}