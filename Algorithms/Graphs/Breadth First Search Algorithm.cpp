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
        adjacencyList = new list<int>[v];
    }
    
    void addEdge(int v1, int v2) {
        adjacencyList[v1].push_back(v2);
    }
    
    void BFS(int source) {
        unordered_map<int, int> flag;
        queue<int> q;
        int tmp;
        
        for (int i = 0; i < V; i++) {
            flag.insert({i, -1});
        }
        
        q.push(source);
        
        while (!q.empty()) {
            cout << q.front() << endl;
            tmp = q.front();
            flag[tmp] = 1;
            q.pop();
            
            for (auto i = adjacencyList[tmp].begin(); i != adjacencyList[tmp].end(); i++) {
                if (flag[*i] == -1) {
                    q.push(*i);
                    flag[*i] = 0;
                }
            }
            
        }
        
    }
  private:
    int V;
    list<int>* adjacencyList;
};

int main() {
    Graph g = Graph(7);
    g.addEdge(0, 1); g.addEdge(1, 0);
    g.addEdge(0, 3); g.addEdge(3, 0);
    g.addEdge(1, 3); g.addEdge(3, 1);
    g.addEdge(1, 2); g.addEdge(2, 1);
    g.addEdge(1, 5); g.addEdge(5, 1);
    g.addEdge(1, 6); g.addEdge(6, 1);
    g.addEdge(2, 3); g.addEdge(3, 2);
    g.addEdge(2, 5); g.addEdge(5, 2);
    g.addEdge(2, 4); g.addEdge(4, 2);
    g.addEdge(3, 4); g.addEdge(4, 3);
    g.addEdge(4, 6); g.addEdge(6, 4);
    
    g.BFS(0);
}