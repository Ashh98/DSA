#include <iostream>
using namespace std;

#include <iostream>
#include <vector>
#include <utility>

class DisjointSet {
    public:
        DisjointSet(int v) {
            this->V = v;
            parent.resize(V, -1);
            rank.resize(V, 0);
        }
        
        void addEdge(int v1, int v2) {
            edgeList.push_back(make_pair(v1, v2));
        }
        
        int findAR(int& index) {
            if (parent[index] == -1) {
                return index;
            } else {
                parent[index] = findAR(parent[index]);
                return parent[index];
            }
        }
        
        bool isCyclic() {
            int AR1, AR2;
            for (auto& i : edgeList) {
                //Find with path compression
                AR1 = findAR(i.first);
                AR2 = findAR(i.second);
                
                
                //Union by rank
                if (AR1 > AR2) {
                    parent[AR2] = AR1;
                    if (rank[AR1] == rank[AR2]) rank[AR1]++;
                } else if (AR1 == AR2 && AR1 != -1) return true;
                else {
                    parent[AR1] = AR2;
                    if (rank[AR1] == rank[AR2]) rank[AR2]++;
                }
            }
            return false;
        }
    private:
        int V;
        vector<pair<int, int>> edgeList;
        vector<int> parent;
        vector<int> rank;
};



int main() {
    DisjointSet ds = DisjointSet(4);
    ds.addEdge(0, 1);
    ds.addEdge(0, 3);
    ds.addEdge(2, 3);
    ds.addEdge(1, 2);
    
    cout << ds.isCyclic() << endl;
    
}
