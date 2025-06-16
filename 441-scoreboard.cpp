#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    int num_of_players = 0;
    std::cin >> num_of_players;

    std::unordered_map<std::string, int> players_scores;
    std::string player_name;

    for (int i = 0; i < num_of_players; i++) {
        std::cin >> player_name;
        players_scores.insert({ player_name, 0 });
    }

    int fts = 0, sts = 0;
    int num_of_scores = 0;
    std::cin >> num_of_scores >> std::ws;

    std::string tmp_s, name;
    int tmp = 0, prev_f = 0, prev_s = 0;
    for (int i = 0; i < num_of_scores; i++) {
        std::getline(std::cin, tmp_s);
        for (auto& a : tmp_s) {
            if (isdigit(a)) {
                tmp = tmp * 10 + (a - '0');
            }
            else if (a == ':') {
                fts = tmp;
                tmp = 0;
            }
            else if (isspace(a)) {
                sts = tmp;
                tmp = 0;
            }
            else {
                name.push_back(a);
            }
        }
        players_scores[name] += (fts - prev_f) + (sts - prev_s);
        name = "";
        prev_f = fts; prev_s = sts;
    }

    int maxx = players_scores.begin()->second;
    std::string ans = players_scores.begin()->first;
    for (auto i = players_scores.begin(); i != players_scores.end(); ++i) {
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


    std::cout << ans << " " << maxx;



    return 0;
}