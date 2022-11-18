#include <iostream>
#include <vector>
using namespace std;

int LinearSearch(vector<int>& arr, int arrSize, int target) {
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] == target) return target;
    }
    return -1;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    
    cout << LinearSearch(arr, 6, 6) << endl;

}