#include <iostream>
using namespace std;

#include <iostream>
#include <vector>
#include <utility>

class DisjointSet {
  public:
    DisjointSet(int v) {
        V = v;
        parent.resize(V, -1);
    }
    
    void addEdge(int v1, int v2) {
        edge_list.push_back(make_pair(v1, v2));
    }
    
    bool isCyclic() {
        int AR1, AR2;
        for (auto& i : edge_list) {
            AR1 = i.first; AR2 = i.second;
            
            //FIND
            while (true) {
                if (parent[AR1] == -1) break;
                else AR1 = parent[AR1];
            }
            while (true) {
                if (parent[AR2] == -1) break;
                else AR2 = parent[AR2];
            }
            
            //UNION
            if (AR1 != AR2) parent[AR1] = AR2;
            else return true;
        }
        
        return false;
    }
  
  private:
    vector<pair<int, int>> edge_list;
    vector<int> parent;
    int V;
};



int main() {
    DisjointSet ds = DisjointSet(4);
    ds.addEdge(0, 1);
    ds.addEdge(0, 3);
    ds.addEdge(2, 3);
    ds.addEdge(1, 2);
    
    cout << ds.isCyclic() << endl;
    
}