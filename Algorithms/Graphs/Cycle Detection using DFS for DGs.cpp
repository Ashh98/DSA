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
        adjList = new list<int>[v];
    }
    
    void addEdge(int v1, int v2) {
        adjList[v1].push_back(v2);
    }
    
    bool isThereACycleDFS() {
        unordered_map<int, int> flag;
        stack<int> stck;
        bool dec = false;
        
        for (int i = 0; i < V; i++) {
            flag[i] = -1;
        }
        
        DFS(0, flag, stck, dec);
        
        return dec;
        
        
    }
    
    void DFS(int source, unordered_map<int, int>& flag, stack<int>& stck, bool& dec) {
        stck.push(source);
        flag[stck.top()] = 0;
        for (auto itr = adjList[stck.top()].begin(); itr != adjList[stck.top()].end(); itr++) {
            if (flag[*itr] == -1) {
                DFS(*itr, flag, stck, dec);
            } else if (flag[*itr] == 0) {
                dec = true;
            }
        }
        
        flag[stck.top()] = 1;
        stck.pop();
    } 
  private:
    int V;
    list<int>* adjList;
};

int main() {
    Graph g = Graph(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 2);
    g.addEdge(3, 4);
    g.addEdge(4, 1);
    
    cout << g.isThereACycleDFS();
}