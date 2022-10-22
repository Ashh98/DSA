// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

int Partition(vector<int>& arr, int l, int h) {
    int i, j, tmp;
    i = l; j = h;
    while (j >= i) {
        i++; j--;
        if (arr[i] > arr[l] && arr[j] <= arr[l]) {
            if (j < i) {
                tmp = arr[j];
                arr[j] = arr[l];
                arr[l] = tmp;
            } else {
                tmp = arr[j];
                arr[j] = arr[i];
                arr[i] = tmp;
            }
        } else {
            while (arr[i] <= arr[l]) i++;
            while (arr[j] > arr[l]) j--;
            if (j < l) {
                j++;
                break;
            }
            if (j < i) {
                tmp = arr[j];
                arr[j] = arr[l];
                arr[l] = tmp;
            } else {
                tmp = arr[j];
                arr[j] = arr[i];
                arr[i] = tmp;
            }
        }

    }
    return j;
}

void QuickSort(vector<int>& arr, int l, int h) {
    if (l < h) {
        int ind = Partition(arr, l, h);
        //cout << l << " " << ind << " " << endl;
        QuickSort(arr, l, ind);
        //cout << ind+1 << " " << h << endl;
        QuickSort(arr, ind+1, h);
    }
}

int main() {
    vector<int> arr = {10, 4, 8, 10, 1, 6, 3, 9, 5,1000};
    vector<int> arr1 = {6, 5, 8, 9, 3, 10};
    
    QuickSort(arr, 0, 9);
    for (auto& x: arr) cout << x << endl;

    return 0;
}