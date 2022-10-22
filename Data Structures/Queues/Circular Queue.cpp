#include <iostream>
#define N 5

using namespace std;

class CircularQueue {
  public:
    void enqueue(int x) {
        if (front == -1 && rear == -1) {
            front++;
            rear++;
            queue[rear%N] = x;
        } else if ( (rear+1)%N == front ) {
            cout << "Overflow condition" << endl;
        } else {
            rear++;
            queue[rear%N] = x;
        }
    }
    
    void dequeue() {
        if (front == -1 && rear == -1) {
            cout << "Underflow condition" << endl;
        } else if (front == rear) {
            cout << "Queue is empty now!" << endl;
            front = -1;
            rear = -1;
        } else {
            front++;
        }
    }
    
    void peak() {
        cout << "Peak of the queue is: " << queue[rear] << endl;
    }
    
    void display() {
        for (int i = front; i < rear+1; i++) {
            if (i < rear) {
                cout << queue[i%N] << " ";
            } else {
                cout << queue[i%N] << endl;
            }
        }
    } 
    
  private:
    int front = -1;
    int rear = -1;
    int queue[N];
};

int main()
{
    CircularQueue cq;
    
    cq.enqueue(1);
    cq.enqueue(2);
    cq.enqueue(3);
    cq.dequeue();
    cq.dequeue();
    cq.enqueue(4);
    cq.enqueue(5);
    cq.enqueue(6);
    cq.enqueue(7);
    cq.enqueue(8);
    
    cq.display();

    return 0;
}

