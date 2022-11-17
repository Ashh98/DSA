#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& arr, int arrSize) {
    int tmp, iMin;
    for (int i = 0; i < arrSize-1; i++) {
        iMin = i;
        for (int j = i+1; j < arrSize; j++) {
            if (arr[j] < arr[iMin]) iMin = j;
        } 
        tmp = arr[i];
        arr[i] = arr[iMin];
        arr[iMin] = tmp;
    }
}

int main() {
    vector<int> arr = {9,8,7,6,5,4,1,2,3};
    selectionSort(arr, 9);
    for (auto& i : arr) {
        cout << i << endl;
    }
}