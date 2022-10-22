#include <iostream>

using namespace std;

struct node {
    int data;
    node* next;
};

class LQueueLL {
  public:
    void enqueue(int x) {
        if (front == NULL && rear == NULL) {
            node* newnode = new node;
            newnode->data = x;
            newnode->next = NULL;
            front = newnode;
            rear = newnode;
        } else {
            node* newnode = new node;
            newnode->data = x;
            rear->next = newnode;
            newnode->next = NULL;
            rear = newnode;
        }
    }
    
    void dequeue() {
        node* tmp = front;
        front = front->next;
        free(tmp);
    }
    
    void display() {
        node* tmp;
        tmp = front;
        while (tmp != NULL) {
            if (tmp->next != NULL) {
                cout << tmp->data << " ";
            } else {
                cout << tmp->data << endl;
            }
            tmp = tmp->next;
        }
    }
  private:
    node* front = NULL;
    node* rear = NULL;
};

int main()
{
    LQueueLL q;
    
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.dequeue();
    q.display();

    return 0;
}