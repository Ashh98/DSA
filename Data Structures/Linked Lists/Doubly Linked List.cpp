#include <iostream>
using namespace std;

struct node {
  int data;
  node* next;
  node* prev;
};

class linked_list {
  public:
  
    linked_list() {
        head = NULL;
        tail = NULL;
    }
    
    void addNode(int n) {
        node* newnode;
        node* pre;
        newnode = new node;
        if (head == NULL) {
            newnode->data = n;
            newnode->next = NULL;
            newnode->prev = NULL;
            pre = newnode;
            head = newnode;
            tail = newnode;
        } else {
            newnode->data = n;
            pre->next = newnode;
            newnode->prev = pre;
            newnode->next = NULL;
            pre = newnode;
            tail = newnode;
        }
    }
    
    void insertNode(int n, int pos) {
        if (pos > getLength()+1) {
            cout << "Invalid index!" << endl;
        } else {
            node* newnode;
            node* curr;
            int i = 0;
            newnode = new node;
            newnode->data = n;
            if (pos == 1) {
                newnode->next = head;
                head->prev = newnode;
                newnode->prev = NULL;
                head = newnode;
            } else if (pos == getLength()+1) {
                newnode->next = NULL;
                tail->next = newnode;
                newnode->prev = tail;
                newnode = tail;
            } else {
                curr = head;
                while (i < pos-2) {
                    curr = curr->next;
                    i++;
                }
                newnode->next = curr->next;
                (curr->next)->prev = newnode;
                curr->next = newnode;
                newnode->prev = curr;
            }
        }
    }
    
    void deleteNode(int pos) {
        node* curr;
        if (pos == 1) {
            head = head->next;
            free(head->prev);
            head->prev = NULL;
        } else if (pos == getLength()) {
            tail = tail->prev;
            free(tail->next);
            tail->next = NULL;
        } else {
            curr = head;
            int i = 0;
            while (i < pos-1) {
                curr = curr->next;
                i++;
            }
            (curr->prev)->next = curr->next;
            (curr->next)->prev = curr->prev;
            free(curr);
        }
    }
    
    void reverse() {
        node* curr;
        node* tmp;
        curr = head;
        if (getLength() == 0) {
            cout << "Linked list is empty!" << endl;
        } else {
            while (curr != NULL) {
                tmp = curr->next;
                
                curr->next = curr->prev;
                curr->prev = tmp;
                
                curr = tmp;
            }
            tmp = head;
            head = tail;
            tail = tmp;
        }
    }
    
    void displayfwd() {
        node* ptr = head;
        while (true) {
            if (ptr != NULL) {
                cout << ptr->data << endl;
                ptr = ptr->next;
            } else {
                break;
            }
        }
    }
    
    void displaybwd() {
        node* ptr = tail;
        while (true) {
            if (ptr != NULL) {
                cout << ptr->data << endl;
                ptr = ptr->prev;
            } else {
                break;
            }
        }
    }
    
    int getLength() {
        int length = 0;
        node* ptr = tail;
        while (true) {
            if (ptr != NULL) {
                ptr = ptr->prev;
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
    linked_list L;
    
    L.addNode(1);
    L.addNode(2);
    L.addNode(3);
    L.addNode(4);
    
    //L.reverse();
    L.displayfwd();
    

    return 0;
}

