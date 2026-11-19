#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// DFS function
void DFS(int vertex, vector<vector<int>>& graph,
         vector<bool>& visited, int n) {

    // Mark current vertex as visited
    visited[vertex] = true;

    // Print current vertex
    cout << vertex << " ";

    // Visit all adjacent vertices
    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            DFS(i, graph, visited, n);
        }
    }
}

// BFS function
void BFS(int start, vector<vector<int>>& graph, int n) {

    vector<bool> visited(n, false);
    queue<int> q;

    // Mark starting vertex as visited
    visited[start] = true;

    // Insert starting vertex into queue
    q.push(start);

    while (!q.empty()) {

        // Remove vertex from queue
        int vertex = q.front();
        q.pop();

        // Print vertex
        cout << vertex << " ";

        // Visit all adjacent vertices
        for (int i = 0; i < n; i++) {

            if (graph[vertex][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main() {

    int n, start;

    cout << "Enter number of vertices: ";
    cin >> n;

    // Create adjacency matrix
    vector<vector<int>> graph(n, vector<int>(n));

    cout << "Enter adjacency matrix:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    cout << "Enter starting vertex (0 to " << n - 1 << "): ";
    cin >> start;

    // DFS
    vector<bool> visited(n, false);

    cout << "\nDFS Traversal: ";
    DFS(start, graph, visited, n);

    // BFS
    cout << "\nBFS Traversal: ";
    BFS(start, graph, n);

    cout<<"\nSrivek Annavarapu\n";
    cout<<"92460118171\n";
    cout<<"5-EN18\n";
    cout << endl;

    return 0;
}
