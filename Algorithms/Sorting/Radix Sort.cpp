#include <iostream>
#include <vector>

using namespace std;

int getMax(vector<int>& arr) {
    int max = 0;
    for (auto& i : arr) {
        if (i > max) max = i;
    }
    return max;
}

int getPlaceValue(int n, int d) {
    return (n/d) % 10;
}

int getMaxPlaceValue(vector<int>& arr, int d) {
    int max = 0; int val = 0;
    
    for (auto& i : arr) {
        val = getPlaceValue(i, d);
        if (val > max) max = val;
    }
    
    return max;
}

int getNumberOfDigits(int n) {
    int d = 0;
    while (n) {
        n = n/10;
        d++;
    }
    
    return d;
}

vector<int> radixSort(vector<int>& arr) {
    int d = getNumberOfDigits(getMax(arr));
    int place_Val = 1;
    vector<int> res = arr;
    vector<vector<int>> bins;
    for (int i = 0; i < d; i++) {
        bins.resize(getMaxPlaceValue(res, place_Val)+1);
        for (int i = 0; i < res.size(); i++) {
            bins[getPlaceValue(res[i], d)].push_back(res[i]);
        }
        res.clear();
        for (auto& i : bins) {
            for(auto& j : i) {
                res.push_back(j);
            }
        }
        
        bins.clear();
        d *= 10;
    }
    
    return res;
    
}

int main() {
    vector<int> arr = {509, 12, 34, 1024, 123127, 28, 455, 2882, 12947};
    vector<int> res = radixSort(arr);
    
    for (auto& i : res) {
        cout << i << endl;
    }
}