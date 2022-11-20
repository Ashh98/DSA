#include <iostream>
#include <vector>
#include <climits>

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
    int place_Val = 1;
    bool neg = false;

    for (auto& i : arr) {
        if (i < 0) neg = true;
    }
    
    if (neg) {
        vector<int> resPos, resNeg;
        for (auto& i : arr) {
            if (i >= 0) resPos.push_back(i);
            else resNeg.push_back(-i);
        }
        int dNeg = getNumberOfDigits(getMax(resNeg));
        int dPos = getNumberOfDigits(getMax(resPos));
        vector<vector<int>> binsNeg, binsPos;
        
        for (int i = 0; i < dPos; i++) {
            binsPos.resize(getMaxPlaceValue(resPos, place_Val)+1);
            for (int i = 0; i < resPos.size(); i++) {
                binsPos[getPlaceValue(resPos[i], place_Val)].push_back(resPos[i]);
            }
            resPos.clear();
            for (auto& i : binsPos) {
                for(auto& j : i) {
                    resPos.push_back(j);
                }
            }
            
            binsPos.clear();
            place_Val *= 10;
        }
        
        place_Val = 1;
        for (int i = 0; i < dNeg; i++) {
            binsNeg.resize(getMaxPlaceValue(resNeg, place_Val)+1);
            for (int i = 0; i < resNeg.size(); i++) {
                binsNeg[getPlaceValue(resNeg[i], place_Val)].push_back(resNeg[i]);
            }
            resNeg.clear();
            for (int i = binsNeg.size()-1; i >= 0; i--) {
                for(auto& j : binsNeg[i]) {
                    resNeg.push_back(j);
                }
            }
            
            binsNeg.clear();
            place_Val *= 10;
        }
        
        
        for (auto& i : resNeg) {
            i = -i;
        }
        for (auto& i : resPos) {
            resNeg.push_back(i);
        }
        
        return resNeg;
        
    } else {
        vector<int> res = arr;
        int d = getNumberOfDigits(getMax(arr));
        vector<vector<int>> bins;
        for (int i = 0; i < d; i++) {
            bins.resize(getMaxPlaceValue(res, place_Val)+1);
            for (int i = 0; i < res.size(); i++) {
                bins[getPlaceValue(res[i], place_Val)].push_back(res[i]);
            }
            res.clear();
            for (auto& i : bins) {
                for(auto& j : i) {
                    res.push_back(j);
                }
            }
            
            bins.clear();
            place_Val *= 10;
        }
        
        return res;
    }
}

int main() {
    vector<int> arr = {-123, -2131, -12, -50, 509, 12, 34, 1024, 123127, 28, 455, 2882, 12947};
    vector<int> res = radixSort(arr);
    
    for (auto& i : res) {
        cout << i << endl;
    }
}
