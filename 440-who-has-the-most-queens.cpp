#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


int main() {
    int tmp = 0, sum = 0;
    std::vector<int> queens(4);
    for (auto& q : queens) {
        std::cin >> q;
        sum += q;
    }
    std::sort(queens.begin(), queens.end());
    int ans = 0;
    if (sum < 2) {
        ans = 1;
    }
    else if (sum <= 4) {
        ans = 0;
    }
    else {
        int i = 3;
        while (sum > 4) {
            sum -= queens[i];
            ans++;
            i--;
        }
    }
    std::cout << ans;



    /*
    std::vector<int> queens(4);
    for (auto& q : queens) {
        std::cin >> q;
    }
    std::sort(queens.begin(), queens.end());
    int sum = 0, ans = 0;
    for (int i = 0; i < 4; i++) {
        if (queens[i] > 4 - sum) {
            break;
        }
        else if (queens[i] == 4 - sum) {
            sum += queens[i];
            ans++;
            break;
        }
        else {
            sum += queens[i];
            ans++;
        }
    }
    if (sum < 2) {
        ans = 3;
    }
    std::cout << 4 - ans;
    */



    return 0;
}