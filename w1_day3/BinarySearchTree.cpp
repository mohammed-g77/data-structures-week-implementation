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

   

    void Inorder(Node *r) {// left->root -> right
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
        else if (key < r->data)
            return Search(r->left, key);
        else
            return Search(r->right, key);
    }

    bool Search(int key) {
        Node *result = Search(root, key);
        return result != NULL;
    }

    Node *Findmin(Node *r) {
        if (r == NULL)
            return NULL;
        else if (r->left == NULL)
            return r;
        else
            return Findmin(r->left);
    }

    Node *Findmax(Node *r) {
        if (r == NULL)
            return NULL;
        else if (r->right == NULL)
            return r;
        else
            return Findmax(r->right);
    }

    Node *Delete(Node *r, int key) {
        if (r == NULL)  // Empty Tree
            return NULL;

        if (key < r->data)//Item exists in left sub tree
            r->left = Delete(r->left, key);
        else if (key > r->data)// item exists in right sub tree
            r->right = Delete(r->right, key);
        else {
            if (r->left == NULL && r->right == NULL) {// leaf node
                delete r;
                return NULL;
            }
            else if (r->left != NULL && r->right == NULL) {// one child on 
                Node *temp = r->left;
                delete r;
                return temp;
            }
            else if (r->left == NULL && r->right != NULL) {// one child on 
                Node *temp = r->right;
                delete r;
                return temp;
            }
            else {
                Node *max = Findmax(r->left);
                r->data = max->data;
                r->left = Delete(r->left, max->data);
            }
        }
        return r;
    }

    void Delete(int key) {
        root = Delete(root, key);
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
 
    cout << "\ninorder traversal:";
    t.Inorder(t.getRoot());
    
   

    t.Delete(12);
    cout << "\n\nAfter deleting 12:\n";
    t.Inorder(t.getRoot());

    t.Delete(15);
    cout << "\n\nAfter deleting 15:\n";
    t.Inorder(t.getRoot());
    
    cout<<"\n"<<t.Search(55);

    return 0;
}
