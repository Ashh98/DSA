#include <iostream>
#include <vector>
#include <utility>
#include <climits>
#include <set>
using namespace std;

class Graph {
  public:
    Graph(int v) {
        V = v;
        adjList.resize(V);
    }
    
    void addEdge(int v1, int v2, int weight) {
        adjList[v1].push_back(make_pair(v2, weight));
    }
    
    vector<int> Dijkstra(int s) {
        set<pair<int, int>> extracted_set;
        extracted_set.insert({0, s});
        vector<int> distances(V, INT_MAX);
        distances[s] = 0;
        
        while (!extracted_set.empty()) {
            int ptr = extracted_set.begin()->second;
            extracted_set.erase(extracted_set.begin());
            for (auto& i : adjList[ptr]) {
                if (distances[i.first] > distances[ptr] + i.second) {
                    if (distances[i.first] != INT_MAX) extracted_set.erase(extracted_set.find(make_pair(distances[i.first], i.first)));
                    distances[i.first] = distances[ptr] + i.second;
                    extracted_set.insert({distances[i.first], i.first});
                }
            }
        }
        return distances;
    }
    
  private:
    int V;
    vector<vector<pair<int, int>>> adjList;
};

int main() {
    Graph g1 = Graph(6);
    
    g1.addEdge(0, 1, 2);
    g1.addEdge(0, 2, 4);
    g1.addEdge(1, 2, 1);
    g1.addEdge(1, 3, 7);
    g1.addEdge(2, 4, 3);
    g1.addEdge(3, 5, 1);
    g1.addEdge(4, 3, 2);
    g1.addEdge(4, 5, 5);
    
    vector<int> dijkstra = g1.Dijkstra(0);
    
    for (auto& i : dijkstra) {
        cout << i << endl;
    }
    
    
    return 0;
}