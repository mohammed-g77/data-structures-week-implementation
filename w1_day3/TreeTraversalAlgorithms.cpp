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

class BST {
public:
    Node *root;

    BST() {
        root = NULL;
    }

    

    Node *Insert(Node *r, int item) {
        if (r == NULL) {
            Node *newnode = new Node(item);
            return newnode;
        }

        if (item < r->data)
            r->left = Insert(r->left, item);
        else
            r->right = Insert(r->right, item);

        return r;
    }

    void Insert(int item) {
        root = Insert(root, item);
    }

   void Preorder(Node *r) {// root ->left->right
        if (r == NULL)
            return;

        cout << r->data << "  ";
        Preorder(r->left);
        Preorder(r->right);
    }

    void Inorder(Node *r) {// left->root -> right
        if (r == NULL)
            return;

        Inorder(r->left);
        cout << r->data << "  ";
        Inorder(r->right);
    }

    void Postorder(Node *r) {// left-> right->root
        if (r == NULL)
            return;

        Postorder(r->left);
        Postorder(r->right);
        cout << r->data << "  ";
    }
    
    
    Node *Search(Node *r, int key) {
        if (r == NULL)
            return NULL;

        if (r->data == key)
            return r;
        else if (key < r->data)
            return Search(r->left, key);
        else
            return Search(r->right, key);
    }

    bool Search(int key) {
        Node *result = Search(root, key);
        return result != NULL;
    }

    
    Node* getRoot() {
       return root;
    }
    
    
};

int main() {
    BST t;
    t.Insert(45);
    t.Insert(15);
    t.Insert(79);
    t.Insert(90);
    t.Insert(10);
    t.Insert(55);
    t.Insert(12);
    t.Insert(20);
    t.Insert(50);
 
    cout << "Inorder traversal: ";
    t.Inorder(t.getRoot()); 
    cout << "\n\n";

    cout << "Preorder traversal: ";
    t.Preorder(t.getRoot());
    cout << "\n\n";

    cout << "Postorder traversal:  ";
    t.Postorder(t.getRoot());
    cout << "\n\n";

    return 0;
}
