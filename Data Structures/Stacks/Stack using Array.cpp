#include <iostream>
using namespace std;

int s[10];
int top = -1;

void push() {
    int x;
    cout << "Please enter the value to be pushed:";
    cin >> x;
    if (top == (sizeof(s)/sizeof(s[0]))-1) {
        cout << "Stack overflow!" << endl;
    } else {
        top++;
        s[top] = x;
    }
}

void pop() {
    if (top == -1) {
        cout << "Stack underflow!" << endl;
    } else {
        top--;
    }
}

void peak() {
    if (top == -1) {
        cout << "Stack underflow!" << endl;
    } else {
        cout << s[top] << endl;
    }
}

void display() {
    for (int i = 0; i <= top; i++) {
        cout << s[i] << endl;
    }
}

int main()
{
    push();
    push();
    push();
    push();
    display();

    return 0;
}