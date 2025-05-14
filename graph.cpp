#include <iostream>
#include <vector>
using namespace std;

// graphs are abstract data structures used to represent relationships or connections between entitites
// they're made up of vertices, which represent entities, and edges, which represent connections between those entities

int main() {


    // Adjacency List
    int V = 4; // number of vertices
    vector<vector<int>> listGraph(V);

    // edges for vertices
    listGraph[0].push_back(1);
    listGraph[0].push_back(3);
    listGraph[1].push_back(0);
    listGraph[1].push_back(2);
    listGraph[2].push_back(1);
    listGraph[2].push_back(3);
    listGraph[3].push_back(0);
    listGraph[3].push_back(2);

    cout << "Adjacency List:" << endl;

    for (int i = 0; i < V; ++i) {
        cout << "Node " << i << ": ";
        for (int neighbor : listGraph[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }

    // Adjacency Matrix
    int matrixGraph[4][4] = {
    {0, 1, 0, 1},
    {1, 0, 1, 0},
    {0, 1, 0, 1},
    {1, 0, 1, 0}
    };

    cout << "Adjacency Matrix:" << endl;

    for (int i = 0; i < 4; i++) {
        cout << "Node " << i << ": ";
        for (int j = 0; j < 4; j++) {
            cout << matrixGraph[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}