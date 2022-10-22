#include <iostream>
#include <vector>
using namespace std;

vector<int> merge(vector<int> arr1, vector<int> arr2) {
    int i, j = 0;
    vector<int> result;
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) {
            result.push_back(arr1[i]);
            i++;
        }
        else if (arr1[i] > arr2[j]) {
            result.push_back(arr2[j]);
            j++;
        } else {
            result.push_back(arr1[i]);
            result.push_back(arr2[j]);
            i++; j++;
        }
    }
    if (i >= arr1.size() && j < arr2.size()) {
        while (j < arr2.size()) {
            result.push_back(arr2[j]);
            j++;
        }
    } else if (i < arr1.size() && j >= arr2.size()) {
        while (i < arr1.size()) {
            result.push_back(arr1[i]);
            i++;
        }
    }
    return result;
}

vector<int> mergeN(vector<int> arr, int l, int h) {
	int arrSize = arr.size();
	int mid;
	if (arrSize % 2 == 0) {
		mid = l + ((h-l)-1)/2;  
	} else {
		mid = l + (h-l)/2;
	}
	
    int i = l; int j = mid+1;
    vector<int> result;
    while (i < mid+1 && j <= h) {
        if (arr[i] < arr[j]) {
            result.push_back(arr[i]);
            i++;
        }
        else if (arr[i] > arr[j]) {
            result.push_back(arr[j]);
            j++;
        } else {
            result.push_back(arr[i]);
            result.push_back(arr[j]);
            i++; j++;
        }
    }
    if (i >= mid+1 && j <= h) {
        while (j <= h) {
            result.push_back(arr[j]);
            j++;
        }
    } else if (i < mid+1 && j > h) {
        while (i < mid+1) {
            result.push_back(arr[i]);
            i++;
        }
    }
    return result;
}

vector<int> mergeSort(vector<int> arr, int l, int h) {
    vector<int> result;
    int mid;
    vector<int> arr1, arr2;
	if (h-l <=2) {
	    return mergeN(arr, l, h);
	} else {
	    if (h % 2 != 0) {
	        mid = l + ((h-l)-1) / 2;
	    } else {
	        mid = l + ((h-l)/2);
	    }
	    arr1 = mergeSort(arr,l,mid);
	    arr2 = mergeSort(arr,mid+1,h);
	    result = merge(arr1,arr2);
	    return result;
	}
}

int main() {
    vector<int> test = {1, 3, 5, 7};
    vector<int> test1 = {2, 4, 6, 8};
    vector<int> test3 = {1, 3, 5, 7, 2, 4, 6, 8};
    vector<int> newarr = mergeSort(test3,0,7);
    for (int i = 0; i < newarr.size(); i++) {
        cout << newarr[i] << endl;
    }

    return 0;
}