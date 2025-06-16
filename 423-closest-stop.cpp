

// https://coderun.yandex.ru/seasons/2024-summer/tracks/backend/problem/nearest-bus-stop?currentPage=1&pageSize=20


#include <iostream>
#include <string>
#include <vector>

int bin_search_with_rules(const std::vector<std::vector<int>>& stops, int target) {
    int curr = stops.size() / 2;
    int first = 0, last = stops.size() - 1;
    if (target > stops.back()[0]) {
        return stops.back()[2];
    }
    if (target < stops.front()[0]) {
        return stops.front()[1];
    }
    while (true) {
        if (target == stops[curr][0]) {
            return stops[curr][1];
        }
        else if (curr != stops.size() - 1 && target > stops[curr][0] && target < stops[curr + 1][0]) {
            return ((target - stops[curr][0]) <= (stops[curr + 1][0] - target) ? stops[curr][2] : stops[curr + 1][1]);
        }
        else if (curr != 0 && target < stops[curr][0] && target > stops[curr - 1][0]) {
            return ((target - stops[curr - 1][0]) <= (stops[curr][0] - target) ? stops[curr - 1][2] : stops[curr][1]);
        }
        else if (target > stops[curr][0]) {
            first = curr + 1;
            curr = (first + last) / 2;
        }
        else {
            last = curr - 1;
            curr = (first + last) / 2;
        }
    }
}

int main() {
    int stop_num = 0, req_num = 0;
    std::cin >> stop_num >> req_num;
    int tmp = 0, prev = 0;
    std::vector<std::vector<int>> stops;
    for (int i = 1; i <= stop_num; ++i) {
        std::cin >> tmp;
        if (i != 1 && tmp == prev) {
            stops.back()[2] = i;
        }
        else {
            stops.push_back(std::vector<int>(3));
            stops.back()[0] = tmp;
            stops.back()[1] = i;
            stops.back()[2] = i;
        }
        prev = tmp;
    }

    for (int i = 0; i < req_num; ++i) {
        std::cin >> tmp;
        std::cout << bin_search_with_rules(stops, tmp) << '\n';
    }


    return 0;
}