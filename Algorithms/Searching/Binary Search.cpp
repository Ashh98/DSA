#include <iostream>
#include <vector>
using namespace std;

bool BS_Iter(vector<int>& arr, int target) {
    int lo = 0; int hi = arr.size() - 1;
    int mid = (lo+hi)/2;
    bool res = false;
    while (lo != hi) {
        if (target == arr[mid]) {
            res = true;
            break;
        } else if (target < arr[mid]) {
            hi = mid - 1;
            mid = (lo+hi)/2;
        } else if (target > arr[mid]) {
            lo = mid + 1;
            mid = (lo+hi)/2;
        }
    }
    
    return res;
}

bool BS_Recr(vector<int>& arr, int target, int lo, int hi) {
    int mid = (lo+hi)/2;
    cout << lo << " " << hi << endl;
    bool res;
    if (target == arr[mid]) {
        res = true;
        cout << "Found it!" << endl;
    } else if (target > arr[mid]) {
        res = BS_Recr(arr, target, mid+1, hi);
    } else if (target < arr[mid]) {
        res = BS_Recr(arr, target, lo, mid-1);
    }
    return res;
}


int main() {
    // Write C++ code here
    vector<int> test = {1, 3, 5, 7};
    cout << BS_Iter(test, 3) << endl;
    cout << BS_Recr(test, 3, 0, 3) << endl;

    return 0;
}