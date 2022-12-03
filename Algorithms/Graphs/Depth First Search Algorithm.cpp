#include <iostream>
#include <vector>
#include <utility>
#include <climits>
#include <set>
#include <list>
#include <unordered_map>
#include <stack>

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
    
    
    void DFS(int source) {
        unordered_map<int, int> flag;
        stack<int> s1;
        
        for (int i = 0; i < V; i++) {
            flag[i] = -1;
        }
        
        dfsOperation(source, flag, s1);
    }
    
    void dfsOperation(int source, unordered_map<int, int>& flag, stack<int>& s1) {
        s1.push(source);
        cout << s1.top() << endl;
        flag[s1.top()] = 0;
        
        for (auto i = adjacencyList[s1.top()].begin(); i != adjacencyList[s1.top()].end(); i++) {
            if (flag[*i] == -1) {
                flag[*i] = 0;
                dfsOperation(*i, flag, s1);
            }
        }
            
        flag[s1.top()] = 1;
        s1.pop();

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
    
    g.DFS(0);
}