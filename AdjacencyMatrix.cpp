#include <iostream>
using namespace std;

int main() {
    int graph[4][4] {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0}
    };

    for (int i = 0; i < 4; i++) {
        cout << "Node " << i << ": ";
        for (int j = 0; j < 4; j++) { cout << graph[i][j] << " "; }
        cout << endl;
    }

    return 0;
}