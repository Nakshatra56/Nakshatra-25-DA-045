// Write a program to find the Connected Components of a graph using
// Depth First Search (DFS).

#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int numVertices;
    vector<vector<int>> adjList;

    void dfs(int vertex, vector<bool>& visited, vector<int>& component) {
        visited[vertex] = true;
        component.push_back(vertex);

        for (int neighbor : adjList[vertex]) {
            if (!visited[neighbor]) {
                dfs(neighbor, visited, component);
            }
        }
    }

public:
    Graph(int vertices) : numVertices(vertices), adjList(vertices) {}

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // undirected graph
    }

    vector<vector<int>> findConnectedComponents() {
        vector<bool> visited(numVertices, false);
        vector<vector<int>> components;

        for (int v = 0; v < numVertices; v++) {
            if (!visited[v]) {
                vector<int> component;
                dfs(v, visited, component);
                components.push_back(component);
            }
        }

        return components;
    }
};

int main() {
    // Example graph with 3 separate connected components:
    // Component 1: 0-1-2
    // Component 2: 3-4
    // Component 3: 5 (isolated)
    int numVertices = 6;
    Graph g(numVertices);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(3, 4);
    // vertex 5 has no edges

    vector<vector<int>> components = g.findConnectedComponents();

    cout << "Number of connected components: " << components.size() << endl;
    for (size_t i = 0; i < components.size(); i++) {
        cout << "Component " << i + 1 << ": ";
        for (size_t j = 0; j < components[i].size(); j++) {
            cout << components[i][j];
            if (j != components[i].size() - 1) cout << ", ";
        }
        cout << endl;
    }

    return 0;
}

/*
Sample Output:

student@labs:~/dsa$ g++ -std=c++17 -o connected_components connected_components_dfs.cpp && ./connected_components
Number of connected components: 3
Component 1: 0, 1, 2
Component 2: 3, 4
Component 3: 5
*/
