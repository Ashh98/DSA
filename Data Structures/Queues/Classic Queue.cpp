#include <iostream>
#define N 5


using namespace std;

class Queue {
  public:
      void enqueue(int x) {
          if (front == -1 && rear == -1) {
              front++;
              rear++;
              queue[rear] = x;
          } else if (rear == N-1) {
              cout << "Overflow condition!" << endl;
          } else {
              rear++;
              queue[rear] = x;
          }
      }
      
      void dequeue() {
          if (front == -1 && rear == -1) {
              cout << "Underflow condition!" << endl;
          } else if (front == rear) {
              front = -1;
              rear = -1;
          } else {
              front++;
          }
      }
      
      void peak() {
          cout << "Queue's peak is: " << queue[front] << endl;
      }
      
      void display() {
          if (front == -1 && rear == -1) {
              cout << "Queue is empty!" << endl;
          } else {
              for (int i = front; i < rear + 1; i++) {
                  if (i < rear) {
                      cout << queue[i] << " ";
                  } else {
                      cout << queue[i] << endl;
                  }
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
    Queue q;
    
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.display();
    q.peak();

    return 0;
}