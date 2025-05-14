#include <iostream>
#include <vector>
using namespace std;


class ListGraph {
private:
    int v; // vertices
    vector<vector<int>> adjList;

public:
    ListGraph(int vertices) { // constructor
        v = vertices;
        adjList.resize(v);
    }

    void addEdge(int u, int v) { // adds edge for each vertices
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
};

int main() {
    ListGraph lg(4);

    lg.addEdge(0, 1);
    lg.addEdge(0, 3);
    lg.addEdge(1, 2);
    lg.addEdge(2, 3);

    cout << "Adjacency List:" << endl;
    lg.print();

    return 0;
}