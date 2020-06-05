//
// We have pairs {phone, email} and we want to calc unique users
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void dfs(const unordered_map <int, vector <int>>& graph, unordered_set <int>& used, int from) {
    used.insert(from);
    for (const auto& to : graph.at(from)) {
        if (used.find(to) == used.end()) {
            dfs(graph, used, to);
        }
    }
}

// guess that email and phones have different unique ids
// email, phone
int GetAmountOfUniqueUsers(const vector <pair <int, int>>& data) {
    unordered_map <int, vector <int>> graph;
    for (const auto&[email, phone] : data) {
        graph[email].push_back(phone);
        graph[phone].push_back(email);
    }
    int amount = 0;
    unordered_set <int> used;
    for (const auto&[from, tos]  : graph) {
        if (used.find(from) == used.end()) {
            dfs(graph, used, from);
            ++amount;
        }
    }
    return amount;
}

bool Test() {
    {
        vector <pair <int, int>> data = {{1, 2},
                                         {1, 3},
                                         {5, 2}};
        if (GetAmountOfUniqueUsers(data) != 1) {
            return false;
        }
    }
    {
        vector <pair <int, int>> data = {{1, 2},
                                         {4, 3},
                                         {5, 2}};
        if (GetAmountOfUniqueUsers(data) != 2) {
            return false;
        }
    }
    {
        vector <pair <int, int>> data = {{1, 2},
                                         {4, 3},
                                         {5, 6}};
        if (GetAmountOfUniqueUsers(data) != 3) {
            return false;
        }
    }
    return true;
}

int main() {
    cout << Test();

    return 0;
}

