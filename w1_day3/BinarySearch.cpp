#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

class BT {
public:
    Node *root;

    BT() {
        root = NULL;
    }

    Node* Insert(Node* r, int item) {
        if (r == NULL) {
            return new Node(item);
        }

        if (r->left == NULL) {
            r->left = Insert(r->left, item);
        } else if (r->right == NULL) {
            r->right = Insert(r->right, item);
        } else {
             
            Node* N = Insert(r->left, item);
            if (N == NULL) {
                N = Insert(r->right, item);
            }
        }

        return r;
    }

    void Insert(int item) {
        root = Insert(root, item);
    }

    void Inorder(Node *r) {
        if (r == NULL)
            return;

        Inorder(r->left);
        cout << r->data << "  ";
        Inorder(r->right);
    }

    Node *Search(Node *r, int key) {
        if (r == NULL)
            return NULL;
        if (r->data == key)
            return r;

        Node *found = Search(r->left, key);
        if (found != NULL)
            return found;
        return Search(r->right, key);
    }

    bool Search(int key) {
        return Search(root, key) != NULL;
    }

    Node* getRoot() {
        return root;
    }
};

int main() {
    BT t;
    t.Insert(45);
    t.Insert(15);
    t.Insert(79);
    t.Insert(90);
    t.Insert(10);
    t.Insert(55);
    t.Insert(12);
    t.Insert(20);
    t.Insert(50);

    cout << "\nInorder traversal: ";
    t.Inorder(t.getRoot());

    cout << "\n\nSearch (1=true|0=false) : " << t.Search(55);  

    return 0;
}
