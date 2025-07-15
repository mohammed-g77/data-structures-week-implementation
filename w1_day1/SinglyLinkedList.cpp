#include <iostream>
using namespace std;


class node {
public:
    int data;
    node* next;
};


class Sll {

    node* head;
    node* tail;

public:
    Sll() {
        head = nullptr;
        tail = nullptr;
    };

    ~Sll() {
        clear();
    }

    bool isEmpty()const {
        return head == nullptr;
    }

    void Display() const {
        node* p = head;
        while (p != nullptr) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }



    void addToFirst(int element) {
        node* sNode = new node;
        sNode->data = element;
        sNode->next = nullptr;

        if (isEmpty()) {
            head = sNode;
            tail = sNode;
        }
        else {
            sNode->next = head;
            head = sNode;
        }

    }

    void addToLast(int element) {
        node* sNode = new node;
        sNode->data = element;
        sNode->next = nullptr;

        if (isEmpty()) {
            head = sNode;
            tail = sNode;
        }
        else {
            tail->next = sNode;
            tail = sNode;
        }
    }

    void addAfter(int element, int val)
    {
        node* n = new node;
        n->data = val;
        n->next = nullptr;
        node* p = search(element);
        if (p != nullptr) {
            n->next = p->next;
            p->next = n;
            if (p == tail) {
                tail = n;
            }
        }
        else {
            cout << "Element Does Not Exisit" << endl;
        }

    }

    void removeFromFirst() {
        if (isEmpty()) return;
        node* p = head;
        head = head->next;
        delete p;
        if (head == nullptr) {
            tail = nullptr;
        }
    }

    void removeFromLast() {
        if (isEmpty()) return;

        if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
            return;
        }

        node* p = head;
        while (p->next != tail) {
            p = p->next;
        }

        delete tail;
        tail = p;
        tail->next = nullptr;
    }

    node* search(int x)
    {
        node* p = head;
        node* target = nullptr;
        while (p != nullptr)
        {
            if (p->data == x)
            {
                target = p;

            }
            p = p->next;
        }
        return target;
    }



    void clear() {
        while (head != nullptr) {
            removeFromFirst();
        }
    }

    int size() const {
        int count = 0;
        node* p = head;
        while (p != nullptr) {
            count++;
            p = p->next;
        }
        return count;
    }
};




    int main()
    {
        Sll L;
        L.addToFirst(10);
        L.Display();
        L.addToLast(2); 
        L.Display();
        L.addToLast(5); 
        L.Display();
       L.addToLast(7); 
        L.Display();//10 2 5 7
        L.addAfter(2, 9);
		L.Display();// 10 9 2 5 7
        L.removeFromFirst();
        L.Display(); // 9 2 5 7
        L.removeFromLast();
        L.Display(); // 9 2 5
        L.addToFirst(3);
        L.Display(); // 3 9 2 5
        L.addToLast(8);
        L.Display(); // 3 9 2 5 8
        cout << "Size of the list: " << L.size() << endl; // 5
        L.clear();
		 
		cout << "Size of the list after clear: " << L.size() << endl; //  0
       
        

		return 0;

    }