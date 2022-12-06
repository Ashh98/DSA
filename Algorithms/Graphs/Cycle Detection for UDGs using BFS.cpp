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
        adjList = new list<int>[v];
    }
    
    void addEdge(int v1, int v2) {
        adjList[v1].push_back(v2);
    }
    
    bool isThereACycleBFS() {
        unordered_map<int, int> flag;
        queue<int> q;
        int tmp;

        for (int i = 0; i < V; i++) {
            flag[i] = -1;
        }
        
        q.push(0);
        flag[q.front()] = 0;
        
        while (!q.empty()) {
            tmp = q.front();
            flag[tmp] = 1;
            q.pop();
            
            for (auto itr = adjList[tmp].begin(); itr != adjList[tmp].end(); itr++) {
                if (flag[*itr] == -1) {
                    q.push(*itr);
                    flag[*itr] = 0;
                } else if (flag[*itr] == 0) {
                    return true;
                }
            }
        }
        
        return false;
        
    }
        
  private:
    int V;
    list<int>* adjList;
};

int main() {
    Graph g = Graph(5);
    g.addEdge(0, 1); g.addEdge(1, 0);
    g.addEdge(0, 2); g.addEdge(2, 0);
    g.addEdge(1, 3); g.addEdge(3, 1);
    g.addEdge(1, 4); g.addEdge(4, 1);
    g.addEdge(3, 4); g.addEdge(4, 3);

    cout << g.isThereACycleBFS();
}
