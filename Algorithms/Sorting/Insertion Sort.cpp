#include <iostream>
using namespace std;

void insertionSort(int* arr, int size) {
    int tmp, key, j;
    for (int i = 1; i < size; i++) {
        key = arr[i];
        j = i-1;
        while (j >= 0 && key < arr[j]) {
            tmp = arr[j+1];
            arr[j+1] = arr[j];
            arr[j] = tmp;
            j--;
        }
    }
}

void insertionSortSIMPLE(vector<int>& arr, int arrSize) {
    int hole;
    for (int i = 1; i < arrSize; i++) {
        hole = i;
        while (hole > 0 && arr[hole-1] > arr[hole]) {
            swap(arr[hole-1], arr[hole]);
            hole--;
        }
    }
}

int main()
{
    int arr[] = {2, 8, 4, 6, 13, 0, 66, 3, -3};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    insertionSort(arr, size);
    
    for(int i = 0; i < size; i++) {
        cout << arr[i] << endl;
    }
    return 0;
}
