//
// Check if there is path between two nodes in directed graph
//

#include <iostream>
#include <vector>

using namespace std;

void dfs(const vector <vector <int>>& graph, vector <bool>& used, int from) {
    used[from] = true;
    for (int to = 0; to < graph.size(); ++to) {
        if (graph[from][to] != 0 and not used[to]) {
            dfs(graph, used, to);
        }
    }
}

bool HaveRoute(const vector <vector <int>>& graph, int from, int to) {
    int n = (int)graph.size();
    if (from >= n or to >= n) {
        return false;
    }
    vector <bool> used = vector <bool>(n);
    dfs(graph, used, from);
    return used[to];
}

bool Test() {
    {
        vector <vector <int>> graph = {{1, 1, 1},
                                       {0, 0, 0},
                                       {0, 0, 0}};
        if (not HaveRoute(graph, 0, 2)) {
            return false;
        }
    }
    {
        vector <vector <int>> graph = {{1, 1, 1},
                                       {0, 0, 0},
                                       {0, 0, 0}};
        if (HaveRoute(graph, 2, 1)) {
            return false;
        }
    }
    {
        vector <vector <int>> graph = {{1, 1, 1},
                                       {1, 0, 0},
                                       {1, 0, 0}};
        if (not HaveRoute(graph, 0, 2)) {
            return false;
        }
    }
    {
        vector <vector <int>> graph = {{1, 1, 1},
                                       {1, 0, 0},
                                       {1, 0, 0}};
        if (not HaveRoute(graph, 2, 0)) {
            return false;
        }
    }
    {
        vector <vector <int>> graph = {{0, 0, 1},
                                       {0, 1, 0},
                                       {0, 0, 0}};
        if (not HaveRoute(graph, 0, 2)) {
            return false;
        }
    }
    {
        vector <vector <int>> graph = {{0, 0, 1},
                                       {0, 1, 0},
                                       {0, 0, 0}};
        if (HaveRoute(graph, 2, 0)) {
            return false;
        }
    }
    return true;
}

int main() {

    cout << Test();

    return 0;
}

