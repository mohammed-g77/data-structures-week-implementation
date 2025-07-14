#include <iostream>
using namespace std;

class StackArray {
    int arr[100];
    int top;
public:
    StackArray()  {
        top = 0;
    }
    bool isEmpty() const {
        return top == 0;
    }

    bool isFull() const {
        return top == 100;
    }

  

    void push(int val) {
        if (isFull()) {
            cout << "Stack is Full"<<endl;
            return;
        }
        arr[top++] = val;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is Empty\n";
            return;
        }
        --top;
    }

    int peek() const {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[top - 1];
    }


    int size() const {
        return top;
    }
};

 
int main() {
    StackArray s;
    s.push(30);
    s.push(20);
    s.push(10);

    cout << "Top element: " << s.peek() << endl;
    s.pop();
    cout << "Top after pop: " << s.peek() << endl;
    cout << "Stack size: " << s.size() << endl;
    return 0;
}