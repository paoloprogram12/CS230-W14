#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;


class ListGraph {
private:
    int v; // vertices
    vector<vector<int>> adjList;
    set<int> visited;

public:
    ListGraph(int vertices) { // constructor
        v = vertices;
        adjList.resize(v);
    }

    void addEdge(int u, int v) { // adds edge for each vertices (vertice, edge)
        adjList[u].push_back(v); 
        adjList[v].push_back(u);
    }

    void print() {
        for (int i = 0; i < v; i++) {
            cout << "Node " << i;
            for (int neighbor : adjList[i]) { cout <<" -> " << neighbor; }
            cout << endl;
        }
    }

    void BFS(int start, int target) {
        queue<int> q;

        q.push(start);
        visited.insert(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            if (node == target) { 
                cout << "Target found: " << node << endl;
                return;
            }

            // look at the neighbors of each node
            for (int neighbor : adjList[node]) {
                if (visited.find(neighbor) == visited.end()) { // checks if the neighbor is not visited
                    q.push(neighbor);
                    visited.insert(neighbor);
                }
            }

        }

        cout << "Target not found" << endl;
    }

    void DFS (int node, int target) { // for the first call, node would be the start
        visited.insert(node);

        if (node == target) {
            cout << "Target found: " << node << endl;
            return;
        }

        for (int i = 0; i < adjList[node].size(); i++) {
            int neighbor = adjList[node][i];
            if (visited.find(neighbor) == visited.end()) { // checks if the neighbor is not visited
                DFS(neighbor, target);
            }
        }

        cout << "Target not found" << endl;
    }

    void startBFS(int start, int target) {
        visited.clear();
        BFS(start, target);
    }

    void startDFS(int node, int target) {
        visited.clear();
        DFS(node, target);
    }
};

int main() {
    ListGraph lg(4);

    lg.addEdge(0, 1);
    lg.addEdge(0, 3);
    lg.addEdge(1, 2);
    lg.addEdge(2, 3);

    cout << "Adjacency List:" << endl;
    lg.print();

    cout << "Breadth First Search:" << endl;
    lg.startBFS(2, 0);


    cout << "Depth First Search:" << endl;
    lg.startDFS(2, 0);

    return 0;
}