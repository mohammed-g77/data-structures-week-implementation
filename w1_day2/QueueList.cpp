
#include <iostream>
using namespace std;

class node{
  public:
  int data;
  node *next;
    
};

class QList{
  public:
  node *front=nullptr;
  node *back=nullptr;
  int length=0;
  
  
  
  bool isEmpty(){
      return front==nullptr;
  }
  
  void push(int e){
      node *n=new node;
      n->data=e;
      n->next=nullptr;
      
     if(isEmpty()){
         front=n;
         back=n;
         length++;
     }
     else{
         back->next=n;
         back=n;
         length++;
     }
      
  }
  
  void pop(){
       if(isEmpty()){
        cout<<"Queue IS  Empty" ;
        return;
     }
     
     
     if(front==back){
         node * c=front;
         front=back=nullptr;
         delete c;
         length--;
         
     }else{
          node * c=front;
         front=front->next;
         delete c;
         length--;
     }
     
     
  }
  
  int getLength(){
      return length;
  }
  
  int Front()
  {
      return front->data;
      
  }
  
  int Back(){
      return back->data;
  }
  
 void clear(){
     if(isEmpty()){
        cout<<"Queue IS  Empty" ;
        return;
     }
     
    while(front != nullptr){ 
            pop();
        }

     
 }
 
 void Display(){
       if(isEmpty()){
        cout<<"Queue IS  Empty" ;
        return;
     }
     
      node *p = front;
        while(p != nullptr){
            cout << p->data << " ";  
            p = p->next; 
        }
        cout << endl;  
    
    
 }
  
  
    
};


int main()
{
    QList q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.Display();
    q.pop();
    q.Display();
    q.clear();
    q.Display();
    return 0;
     
}