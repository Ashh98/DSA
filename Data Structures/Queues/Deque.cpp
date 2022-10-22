#include <iostream>
#define N 5

using namespace std;

class Deque {
  public:
    void enqueuefront(int x) {
        if (front == -1 && rear == -1) {
            front++;
            rear++;
            queue[rear] = x;
        } else if ((rear+1)%N == front) {
            cout << "Overflow condition" << endl;
        } else {
            rear++;
            queue[rear%N] = x;
        }
    }
    
    void enqueuerear(int x) {
        if (front == -1 && rear == -1) {
            front = N-1;
            rear = N-1;
            queue[front] = x;
        } else if ((front-1)%N == rear) {
            cout << "Overflow condition" << endl;
        } else {
            front--;
            if (front == -1) { front = N-1; }
            queue[front] = x;
            cout << "Front=" << front << " Rear=" << rear << endl;
        }
    }
    
    void dequeuefront() {
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
    
    void dequeuerear() {
        if (front == -1 && rear == -1) {
            cout << "Underflow condition" << endl;
        } else if (front == rear) {
            cout << "Queue is empty now!" << endl;
            front = -1;
            rear = -1;
        } else {
            rear--;
        }    
    }
    
    void peak() {
        cout << "Peak of the queue is: " << queue[rear] << endl;
    }
    
    void display() {
        int i = front;
        while (true) {
            if (i == rear) {
                cout << queue[i%N] << endl;
                break;
            } else {
                cout << queue[i%N] << " ";
            }
            i = (i+1) % N;
        }
    } 
    
    
  private:
    int front = -1;
    int rear = -1;
    int queue[N];
};

int main()
{
    Deque dq;
    
    dq.enqueuerear(1);
    dq.enqueuerear(2);
    dq.enqueuerear(3);
    dq.enqueuerear(4);
    dq.dequeuerear();
    dq.enqueuerear(5);
    dq.enqueuerear(6);
    dq.dequeuerear();
    dq.enqueuerear(7);
    dq.display();


    return 0;
}  