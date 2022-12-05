#include <iostream>
#include <vector>
#include <utility>
#include <climits>
#include <set>
#include <list>
#include <unordered_map>
#include <queue>

using namespace std;

class Graph {
  public:
    Graph(int v) {
        V = v;
        adjList = new list<int>[V];
    }
    
    void addEdge(int v1, int v2) {
        adjList[v1].push_back(v2);
    }
    
    void topologicalSort() {
        unordered_map<int, int> flag;
        vector<int> in_deg(V);
        queue<int> q;
        int tmp;
        
        for (int i = 0; i < V; i++) {
            flag[i] = -1;
            in_deg[i] = 0;
        }
        
        for (int i = 0; i < V; i++) {
            for (auto j = adjList[i].begin(); j != adjList[i].end(); j++) {
                in_deg[*j]++;
            }
        }
        
        
        for (int i = 0; i < V; i++) {
            if (!in_deg[i]) {
                q.push(i);
                flag[i] = 0;
            }
        }
        
        while (!q.empty()) {
            cout << q.front() << endl;
            int tmp = q.front();
            q.pop();
            
            for (auto i = adjList[tmp].begin(); i != adjList[tmp].end(); i++) {
                if (flag[*i] == -1) {
                    in_deg[*i]--;
                    if (!in_deg[*i]) {
                        flag[*i] = 0;
                        q.push(*i);
                    }
                }
            }
        }
        

    }
  private:
    int V;
    list<int>* adjList;
};
int main() {
    Graph g = Graph(5);
    
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 2);
    g.addEdge(3, 4);
    
    g.topologicalSort();
}