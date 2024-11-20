#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
public:
    void beam_width(const vector<vector<int>>& adjMatrix, vector<bool>& visited, vector<int>& ans, int startNode) {
        queue<int> q;
        q.push(startNode);
        visited[startNode] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for (int i = 0; i < adjMatrix.size();i++) {
                if (adjMatrix[node][i] == 1 && !visited[i] && q.size()<=2) { 
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }

    vector<int> beam(const vector<vector<int>>& adjMatrix) {
        int vertexCount = adjMatrix.size();
        vector<bool> visited(vertexCount, false);
        vector<int> ans;

        cout << "Enter the starting node: " << endl;
        int startNode;
        cin >> startNode;

        beam_width(adjMatrix, visited, ans, startNode);

        return ans;
    }

};

int main() {
    int vertexCount = 10; 

    vector<vector<int>> adjMatrix = {{0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}, 
        {1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}, 
        {0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0}, 
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, 
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1}, 
        {0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0}};

    Graph g;

    vector<int> result;
    result = g.beam(adjMatrix);

    for (auto i : result) {
        cout << i << "->";
    }

    cout << "end";
    return 0;
}
