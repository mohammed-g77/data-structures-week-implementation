#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node* prev;
};

class CDLL { 
public:
    node* head = nullptr;
    node* tail = nullptr;

    bool isEmpty() {
        return (head == nullptr);
    }

    void addElement(int Element) {
        node* n = new node;
        n->data = Element;

        if (isEmpty()) {
            head = n;
            tail = n;
            head->next = head;  
            head->prev = head;  
        } else {
            tail->next = n;
            n->prev = tail;
            n->next = head; 
            head->prev = n;  
            tail = n;
        }
    }

    void addFirst(int Element) {
        node* n = new node;
        n->data = Element;

        if (isEmpty()) {
            head = n;
            tail = n;
            head->next = head;
            head->prev = head;
        } else {
            head->prev = n;
            n->next = head;
            n->prev = tail;  
            tail->next = n;  
            head = n;
        }
    }

     void Display() {
        if (isEmpty()) {
            cout << "List is Empty" << endl;
            return;
        }
        node* p = head;
        if (p != nullptr) {  
            while (true) {  
                cout << p->data << " ";
                p = p->next;
                if (p == head) { 
                    break;
                }
            }
        }
        cout << endl;
    }

    
    void DisplayRev() {
        if (isEmpty()) {
            cout << "List is Empty" << endl;
            return;
        }
        node* p = tail;
        if (p != nullptr) {  
            while (true) {  
                cout << p->data << " ";
                p = p->prev;
                if (p == tail) { 
                    break;
                }
            }
        }
        cout << endl;
    }

    void deleteElement(int x) {
        if (isEmpty()) {
            cout << "List is Empty" << endl;
            return;
        }

        
        if (head == tail && head->data == x) {
            delete head;
            head = nullptr;
            tail = nullptr;
            return;
        }

        node* p = head;
        bool found = false;

        if (p != nullptr) {  
            while (true) {
                if (p->data == x) {
                    found = true;
                    
                    if (p == head) {
                        head = head->next;
                        head->prev = tail;
                        tail->next = head;
                    }
                  
                    else if (p == tail) {
                        tail = tail->prev;
                        tail->next = head;
                        head->prev = tail;
                    }
                    
                    else {
                        p->prev->next = p->next;
                        p->next->prev = p->prev;
                    }
                    delete p;
                    break;  
                }
                p = p->next;
                if (p == head) {  
                    break;
                }
            }
        }
        
        if (!found) {
            cout << "Element " << x << " Does not exist in the list." << endl;
        }
    }

    void DeleteLast() {
        if (isEmpty()) {
            cout << "List is Empty " << endl;
            return;
        }
       
        if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
            return;
        }

        node* p = tail;
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
        delete p;
    }

    void clear() {
        if (isEmpty()) {
            cout << "List is Empty " << endl;
            return;
        }

  while (!isEmpty()) {
            DeleteLast();
        }
        cout << "List cleared." << endl;  
    }
};

int main() {
     CDLL L;
     L.addElement(10);
     L.addElement(20);
     L.addElement(30);
     L.addElement(40);
     L.addElement(50);
     L.Display();
     L.DisplayRev();
     L.deleteElement(10);
     L.Display();
     L.deleteElement(30);
     L.Display();
     L.deleteElement(50);
     L.Display();
     L.addFirst(5);
     L.Display();
     L.DeleteLast();
     L.Display();
     L.clear();
     L.Display();  

  
    return 0;
}