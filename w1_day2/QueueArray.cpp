#include <iostream>
using namespace std;

class QueueArray {
    int arr[100];
    int F_idx;
    int B_idx;
    int length;

public:
    QueueArray() {
        F_idx = 0;
        B_idx  = -1;
        length = 0;
    }

    bool isEmpty() const {
        return length == 0;
    }

    bool isFull() const {
        return length == 100;
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue is Full  " << val << endl;
            return;
        }
       B_idx= (B_idx + 1) % 100;
        arr[B_idx] = val;
        length++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty \n";
            return;
        }
        F_idx = (F_idx + 1) % 100;
        length--;
    }

    int front() const {
        if (isEmpty()) {
            cout << "Queue is empty " << endl;
            return -1;
        }
        return arr[F_idx];
    }

    int back() const {
        if (isEmpty()) {
            cout << "Queue is empty " << endl;
            return -1;
        }
        return arr[B_idx];
    }

    int Length() const {
        return length;
    }

    void display() const {
        if (isEmpty()) {
            cout << "Queue is Empty.\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = 0; i < length; ++i) {
            cout << arr[(F_idx + i) % 100] << " ";
        }
        cout << endl;
    }
};

int main() {
    QueueArray q;

     
    q.enqueue(30);
    q.enqueue(20);
    q.enqueue(10);
    q.display();
    
    q.dequeue();
    q.display();
 
 
}