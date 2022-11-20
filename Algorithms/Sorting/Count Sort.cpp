#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void countingSort(vector<int>& arr, vector<int>& res, int arrSize) {
    int k = 0; int negk = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] < negk) negk = arr[i]; 
        if (arr[i] > k) k = arr[i];
    }
    if (negk < 0) {
        negk = -negk;
        vector<int> rangePOS(k+1, 0);
        vector<int> rangeNEG(negk+1, 0);
        
        for (auto& i : arr) {
            if (i >= 0) {
                rangePOS[i]++;
            } else {
                rangeNEG[-i]++;
            }
        }
        
        for (int i = negk; i >= 0; i--) {
            for (int j = 0; j < rangeNEG[i]; j++) {
                res.push_back(-i);
            }
        }
        
        for (int i = 0; i < k+1; i++) {
            for (int j = 0; j < rangePOS[i]; j++) {
                res.push_back(i);
            }
        }
    } else {
        vector<int> range(k+1, 0);
        
        for (auto& i : arr) {
            range[i]++;
        }
        
        for (int i = 0; i < k+1; i++) {
            for (int j = 0; j < range[i]; j++) {
                res.push_back(i);
            }
        }
    }
}

int main() {
    vector<int> arr = {-1, -3, 5, 2, -2, 1, 0, 6, 3, 4};
    vector<int> res;
    countingSort(arr, res, arr.size());
    for (auto& i : res) {
        cout << i << endl;
    }

}
