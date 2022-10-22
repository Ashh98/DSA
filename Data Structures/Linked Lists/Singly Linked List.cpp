#include <iostream>

using namespace std;

struct node {
    int data;
    node* next;
};

class linkedlist {
    public:
        linkedlist() {
            head = NULL;
            tail = NULL;
        }
        
        void addNode(int n) {
            node* newnode = new node;
            newnode->data = n;
            newnode->next = NULL;
            
            if (head == NULL) {
                head = newnode;
                tail = newnode;
            } else {
                tail->next = newnode;
                tail = newnode;
            }
        }
        
        void insertNode(int n, int pos) {
            if (pos > getLength()+1 || pos == 0) {
                cout << "Index invalid!" << endl;
            } else {
                int i = 0;
                node* newnode = new node;
                newnode->data = n;
                node* curr = head;
                if (pos == 1) {
                    newnode->next = head;
                    head = newnode;
                } else if (pos == getLength()+1) {
                    tail->next = newnode;
                    newnode->next = NULL;
                    tail = newnode;
                } else {
                    while (i < pos-2) {
                        curr = curr->next;
                        i++;
                    }
                    newnode->next = curr->next;
                    curr->next = newnode;
                }
                
            }
        }
        
        void deleteNode(int pos) {
            if (pos > getLength() || pos == 0) {
                cout << "Index invalid!" << endl;
            } else {
                node* curr = head;
                node* pre = head;
                int i = 0;
                if (pos == 1) {
                    head = curr->next;
                    free(curr);
                } else if (pos == getLength()) {
                    while (i < getLength()-2) {
                        curr = curr->next;
                        i++;
                    }
                    free(curr->next);
                    curr->next = NULL;
                    tail = curr;
                } else {
                    while (true) {
                        curr = curr->next;
                        i++;
                        if (i == pos-2) {
                            pre = curr;
                        } else if (i == pos) {
                            break;
                        }
                    }
                    free(pre->next);
                    pre->next = curr;
                }
            }
        }
        
        void reverse() {
            node* pre = head;
            node* curr = head->next;
            node* nxt = curr->next;
            while (true) {
                if (pre == head) {
                    pre->next = NULL;
                    tail = pre;
                    curr->next = pre;
                    pre = curr;
                    curr = nxt;
                    nxt = nxt->next;
                } else if (curr->next == NULL) {
                    curr->next = pre;
                    head = curr;
                    break;
                } else {
                    curr->next = pre;
                    pre = curr;
                    curr = nxt;
                    nxt = nxt->next;
                }
            }
        }      
        
        void display() {
            node* ptr = getHead();
            while (true) {
                if (ptr != NULL) {
                    cout << ptr->data << endl;
                    ptr = ptr->next;
                } else {
                    break;
                }
            }
        }
        
        int getLength() {
            int length = 0;
            node* ptr = head;
            while (true) {
                if (ptr != NULL) {
                    ptr = ptr->next;
                    length++;
                } else {
                    break;
                }
            }
            return length;
        }
        
        node* getHead() {
            return head;
        }
        
        node* getTail() {
            return tail;
        }
        
    private:
        node* head;
        node* tail;
};

int main()
{
    linkedlist L;
    
    L.addNode(1);
    L.addNode(2);
    L.addNode(3);
    L.addNode(4);
    L.addNode(5);
    L.display();
    L.reverse();
    L.display();
    
    return 0;
}



