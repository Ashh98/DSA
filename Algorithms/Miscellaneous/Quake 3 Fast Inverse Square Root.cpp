#include <iostream>
using namespace std;

float Quake3_IFSQRT(float x) {
    long i; float x2, y;
    float threehalfs = 1.5F;
    
    x2 = x * 0.5F;
    y = x;
    i = * (long *) &y;
    i = 0x5f3759df - (i >> 1);
    y = * (float *) &i;
    y = y * (threehalfs - (x2*y*y));
    return y;
}

int main() {
    double x = 3;
    
    cout << Quake3_IFSQRT(x) << endl;

}