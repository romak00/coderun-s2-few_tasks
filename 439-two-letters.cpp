#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include <sstream>

int main() {

    std::unordered_map<std::string, int> table;

    std::string tmp1, tmp2, a, b, key;
    while (std::getline(std::cin, tmp1)) {
        std::stringstream iss(tmp1);
        while (iss >> tmp2) {
            if (tmp2.size() >= 2) {
                for (int i = 0; i < tmp2.size() - 1; i++) {
                    a = tmp2[i];
                    b = tmp2[i + 1];
                    key = a + b;
                    if (table.find(key) != table.end()) {
                        table[key]++;
                    }
                    else {
                        table[key] = 1;
                    }
                }
            }
        }
    }
    int maxx = -1;
    std::string ans = "";
    for (auto i = table.begin(); i != table.end(); ++i) {
        if (i->second >= maxx) {
            if (i->second > maxx) {
                maxx = i->second;
                ans = i->first;
            }
            else if (i->first > ans) {
                maxx = i->second;
                ans = i->first;
            }
        }
    }
    std::cout << ans;





    return 0;
}