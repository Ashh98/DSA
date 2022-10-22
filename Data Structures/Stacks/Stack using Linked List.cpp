#include <iostream>

using namespace std;

struct node {
  int data;
  node* next;
};

class StackLL {
  public:
    
    void push(int x) {
        if (top == NULL) {
            node* newnode = new node;
            top = newnode;
            newnode->data = x;
            newnode->next = NULL;
        } else {
            node* newnode = new node;
            newnode->next = top;
            newnode->data = x;
            top = newnode;
        }
    }
    
    void pop() {
        if (top == NULL) {
            cout << "Stack underflow!" << endl;
        } else {
            node* tmp = new node;
            tmp = top->next;
            free(top);
            top = tmp;
        }
    }
    
    void peak() {
        if (top == NULL) {
            cout << "Stack underflow!" << endl;
        } else {
            cout << "Peak value of the stack is " << top->data << endl;
        }
    }
    
    void display() {
        if (top == NULL) {
            cout << "Stack underflow!" << endl;
        } else {
            node* curr = new node;
            curr = top;
            while (true) {
                cout << curr->data << endl;
                if (curr->next == NULL) {
                    break;
                }
                curr = curr->next;
            }
        }
    }
    
  private:
    node* top = NULL;
};

int main()
{
    StackLL s1;
    
    s1.push(1);
    s1.push(2);
    s1.push(30);
    s1.peak();
    s1.display();
    s1.pop();
    s1.peak();
    s1.display();

    return 0;
}