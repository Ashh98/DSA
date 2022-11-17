#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int>& arr, int arrSize) {
    int hi = arrSize-1;
    bool flag;
    while (true) {
        flag = false;
        for (int i = 0; i < hi; i++) {
            if (arr[i] > arr[i+1]) {
                swap(arr[i], arr[i+1]);
                flag = true;
            }
        }
        hi--;
        if (!flag) break;
    }
}

int main() {
    vector<int> arr = {9,8,7,6,5,4,3,2,1};
    bubbleSort(arr, 9);
    
    for (auto& i : arr) {
        cout << i << endl;
    }
}