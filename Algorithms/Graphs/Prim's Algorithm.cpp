#include <iostream>
#include <vector>
#include <utility>
#include <climits>
#include <set>
#include <unordered_set>
using namespace std;

class Graph {
  public:
    Graph(int v) {
        this->V = v;
        adjList.resize(V);
    }
    
    int find(int& node, vector<int>& parent) {
        int prnt;
        if (parent[node] == -1) prnt = node;
        else prnt = find(parent[node], parent);
        return prnt;
    }
    
    void addEdge(int v1, int v2, int weight) {
        adjList[v1].push_back(make_pair(weight, v2));
    }
    
    void prim() {
        set<pair<int, pair<int, int>>> extracted_set;
        unordered_set<int> MST;
        vector<pair<int, int>> MST_edges;
        extracted_set.insert({0, {0, 0}});
        vector<int> parent(V, -1);
        int AR1, AR2;
        int cost = 0; int node = 0; pair<int, int> edge;

        while (!extracted_set.empty()) {
            edge = extracted_set.begin()->second;
            if (edge.first != edge.second) {
                while (true) {
                    edge = extracted_set.begin()->second;
                    AR1 = find(edge.first, parent); AR2 = find(edge.second, parent);
                    if (AR1 != AR2 || (AR1 == AR2 && AR1 == -1)) break;
                    else extracted_set.erase(extracted_set.begin());
                }
                parent[AR1] = AR2;
                node = edge.second;
                MST.insert(edge.second);
                MST_edges.push_back(edge);
                cost += extracted_set.begin()->first;
                extracted_set.erase(extracted_set.begin());
            } else {
                node = edge.second;
                MST.insert(edge.second);
                extracted_set.erase(extracted_set.begin());
            }

            for (auto& i : adjList[node]) {
                if (MST.find(i.second) == MST.end()) extracted_set.insert({i.first, {node, i.second}});
            }
            if (MST.size() == V) break;
        }
        
        for (auto& i : MST) {
            cout << i << endl;
        }
        cout << "Cost = " << cost << endl;
    }
  private:
    int V;
    vector<vector<pair<int, int>>> adjList;
};

int main() {
    Graph g = Graph(6);
    
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(0, 5, 7);
    g.addEdge(1, 0, 5);
    g.addEdge(1, 2, 6);
    g.addEdge(1, 4, 4);
    g.addEdge(2, 0, 3);
    g.addEdge(2, 1, 6);
    g.addEdge(2, 3, 3);
    g.addEdge(2, 5, 8);
    g.addEdge(3, 2, 3);
    g.addEdge(3, 1, 2);
    g.addEdge(3, 4, 2);
    g.addEdge(4, 1, 4);
    g.addEdge(4, 3, 2);
    g.addEdge(5, 0, 7);
    g.addEdge(5, 2, 8);
    
    g.prim();
}