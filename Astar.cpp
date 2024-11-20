#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class graph {
public:
    void Astar(vector<int> h, vector<vector<int>>& adjmatrix) {
        int n = adjmatrix.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> open;
        vector<int> parent(n, -1);
        vector<int> g(n, INT_MAX);
        vector<int> f(n, INT_MAX);
        vector<bool> visited(n, false);

        int snode = 0;  
        int gnode = 9;  

        g[snode] = 0;
        f[snode] = h[snode];
        open.push({f[snode], snode});
        
        visited[snode] = true;

        while (!open.empty()) {
            int bestnode = open.top().second;
            open.pop();

            if (bestnode == gnode) {
                cout << "The path is: " << endl;
                printPath(parent, gnode);
                return;
            }

            for (int i = 0; i < n; i++) {
                if (adjmatrix[bestnode][i] != 0) {
                    int newgvalue = g[bestnode] + adjmatrix[bestnode][i];
                    if (newgvalue < g[i]) {
                        g[i] = newgvalue;
                        f[i] = g[i] + h[i];
                        parent[i] = bestnode;
                        if (!visited[i]) {
                            open.push({f[i], i});
                            visited[i] = true;
                        
                    }
                }
            }
            }
        }
    }

private:
    void printPath(const vector<int>& parent, int node) {
        if (parent[node] == -1) {
            cout << node << " ";
            return;
        }
        printPath(parent, parent[node]);
        cout << node << " ";
    }
};

int main() {
    vector<vector<int>> adjmatrix = {
        {0, 6, 3, 1, 0, 0, 0, 0, 0, 0},
        {6, 0, 2, 6, 3, 4, 0, 0, 0, 0},
        {3, 2, 0, 0, 4, 5, 0, 0, 0, 0},
        {1, 6, 0, 0, 7, 8, 9, 0, 0, 0},
        {0, 3, 4, 7, 0, 6, 9, 9, 0, 0},
        {0, 4, 5, 8, 6, 0, 8, 9, 0, 0},
        {0, 0, 0, 9, 9, 8, 0, 11, 12, 14},
        {0, 0, 0, 0, 9, 9, 11, 0, 14, 15},
        {0, 0, 0, 0, 0, 0, 12, 14, 0, 0},
        {0, 0, 0, 0, 0, 0, 14, 15, 0, 0}
    };

    vector<int> h = {15, 13, 13, 12, 10, 9, 7, 6, 5};
    graph g;
    g.Astar(h, adjmatrix);

    return 0;
}