#include <iostream>
#include <queue>
using namespace std;


struct node {
    int data;
    node* left;
    node* right;
};

class BST {
  public:
    node* root = NULL;
    node* ptr = NULL;
    
    node* insert(node* root, int x){
        if (root == NULL) {
            node* newnode = new node;
            root = newnode;
            root->data = x;
            root->left = root->right = NULL;
        } else {
            if (x <= root->data) {
                root->left = insert(root->left, x);
            } else {
                root->right = insert(root->right, x);
            }
        }
        return root;
    };
    
    node* search(int x, node* root) {
        if (x == root->data) {
            cout << "Data is found!" << endl;
        } else if (x != root->data && root->left == NULL && root->right == NULL) {
            cout << "Data is not found!" << endl;
        } else if (x <= root->data) {
            search(x, root->left);
        } else if (x > root->data) {
            search(x, root->right);
        }
        return root;
    }
    
    int recursive_findMin(node* root) {
        if (root == NULL) {
            cout << "BST is empty" << endl;
            return -1;
        } else if (root->left == NULL) {
            return root->data;
        }
        return recursive_findMin(root->left);
    }
    
    int iterative_findMin() {
        node* current = root;
        if (current == NULL) {
            cout << "BST is empty" << endl;
            return -1;
        }
        
        while (current->left != NULL) {
            current = current->left;
        }
        return current->data;
    }
    
    int findHeight(node* root) {
        if (root == NULL) {
            return -1;
        }
        return max(findHeight(root->left), findHeight(root->right)) + 1;
    }
    
    void BFT(node* root) {
      queue<node*> q;
      if (root == NULL) {
          cout << "Tree is empty!" << endl;
      } else {
          q.push(root);
          node* current = q.front();
          while (!q.empty()) {
              cout << current->data << endl;
              q.pop();
              if (current->left != NULL) q.push(current->left);
              if (current->right != NULL) q.push(current->right);
              current = q.front();
          }
      }
    }
      
    void DFT(node* root) {
      if (root != NULL) {
          DFT(root->left);
          cout << root->data << endl;
          DFT(root->right);
        }
    }
    
  
};


int main()
{
    BST tree;
    tree.root = tree.insert(tree.root, 15);
    tree.insert(tree.root, 10);
    tree.insert(tree.root, 20);
    tree.insert(tree.root, 8);
    tree.insert(tree.root, 12);
    tree.insert(tree.root, 17);
    tree.insert(tree.root, 24);
    tree.insert(tree.root, 19);
    cout << tree.iterative_findMin() << endl;


    return 0;
}
