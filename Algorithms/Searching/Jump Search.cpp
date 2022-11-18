#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int jumpSearch(vector<int>& arr, int arrSize, int target) {
    for (int i = 0; i < arrSize; i = i+sqrt(arrSize)) {
        if (i+sqrt(arrSize) >= arrSize) {
            if (target >= arr[i] && target <= arr[arrSize-1]) {
                for (int j = i; j < arrSize; j++) {
                    if (arr[j] == target) return target;
                }
            }
        } else {
            if (target >= arr[i] && target <= arr[i+sqrt(arrSize)]) {
                for (int j = i; j <= i+sqrt(arrSize); j++) {
                    if (arr[j] == target) return target;
                }
            }
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    
    cout << jumpSearch(arr, 6, 3) << endl;

}