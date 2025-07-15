#include <iostream>
using namespace std;

class node{
public:
int data;
node *next;
};


class Stack{
public:
	node *top=nullptr;
	int size=0;

Stack() {
	top = nullptr;
	size = 0;
}
~Stack() {
	while (!isEmpty()) {
		pop();
	}
}

bool isEmpty() {
	return top == nullptr;
}

int Size() {
	return size;
}


int Top() {
	return top->data;
}

void push(int x){
	
	node *n=new node;
	n->data=x;
	n->next=nullptr;

	if(isEmpty()){
	top=n;
	size++;
	}
	else{
	n->next=top;
	top=n;
	size++;

	}
}

void pop() {

	if (isEmpty()) {
		cout << "Empty" << endl;
	}
	else {
		node* p = top;
		top = top->next;
		delete p;
		size--;
	}
}


};


int main()
{
	Stack s;
	s.push(5);
	s.push(4);
	s.push(3);
	s.push(2);
	s.push(1);

	while(!s.isEmpty()){
		cout<<s.Top()<<" ";
		s.pop();
	}
}