#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void shellSort(vector<int>& arr) {
    for (int i = arr.size()/2; i > 0; i /= 2) {
        for (int j = i; j < arr.size(); j++) {
            int hole = j;
            while (hole > 0 && arr[hole] < arr[hole-i]) {
                swap(arr[hole], arr[hole-i]);
                hole -= i;
            }
        }
    }

}

int main() {
    vector<int> arr = {-123, -2131, -12, -50, 509, 12, 34, 1024, 123127, 28, 455, 2882, 12947};
    shellSort(arr);
    
    for (auto& i : arr) {
        cout << i << endl;
    }
}