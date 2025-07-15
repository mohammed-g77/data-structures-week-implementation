 
#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node *next ;
    node *prev;    
    
};

class DLL{
  public:
 node *head=nullptr;
 node *tail=nullptr;
 
 bool isEmpty(){
     return (head==nullptr);
 }
 
 void addElement(int Element){
     node *n=new node;
     n->data=Element; 
     n->prev=nullptr;
     n->next=nullptr;
     
     if(isEmpty()){
         head=n;
         tail=n;
     }
     else{
         tail->next=n;
         n->prev=tail;
         tail=n;
     }
    
 }
 
 void addFirst(int Element ){
     node *n=new node;
     n->data=Element; 
     n->prev=nullptr;
     n->next=nullptr;
     
     if(isEmpty()){
         head=n;
         tail=n;
     }
     else{
         head->prev=n;
         n->next=head;
         head=n;
     }
    
 }
 
 
 void Display(){
     
     node *p=head;
     while (p!=nullptr){
         cout<<p->data<<"  ";
         p=p->next;
     }
     cout<<endl;
     
 }
 
  void DisplayRev(){
     
     node *p=tail;
     while (p!=nullptr){
         cout<<p->data<<"  ";
         p=p->prev;
     }
     cout<<endl;
     
 }
 
 void deleteElement(int x){
     
     if(isEmpty()){
         cout<<"list is Empty"<<endl;
         return ;
     }
     
    if(head==tail && head->data==x){
        node *p=head;
        head=nullptr;
        tail=nullptr;
        delete p;
        return;
    }
    if(head->data==x){
        node *p=head;
        head=head->next;
        head->prev=nullptr;
        delete p;
        return;
    }
    if(tail->data==x){
        node *p=tail;
        tail=tail->prev;
        tail->next=nullptr;
        delete p;
        return;
      }
      
    node *p=head;
    while(p!=nullptr){
        if(p->data==x){
            p->prev->next=p->next;
            p->next->prev=p->prev;
            delete p;
            return;
         }
        else{
            p=p->next;
           }
      }
 }
  
  void DeleteLast(){
      if(isEmpty()){
          cout<<"list is Empty "<<endl;
      }
      
      node *p=tail;
      tail=tail->prev;
      tail->next=nullptr;
      delete p;
      return;
      
  }
  
  void clear(){
     if(isEmpty()){
          cout<<"list is Empty "<<endl;
      }
      
      node *p =head;
      
      while(p!=nullptr){
          DeleteLast();
      }

    cout << "List is cleared" << endl;
      
  }
  
  
  
  
    
};

int main()
{
    DLL L;
    L.addElement(10);
  //  L.Display();
    L.addElement(20);
  //  L.Display();
    L.addElement(30);
  //  L.Display();
    L.addElement(40);
  //  L.Display();
    L.addElement(50);
    L.Display();
   // L.DisplayRev();
    // L.deleteElement(10);
    // L.Display();
    // L.deleteElement(30);
    // L.Display();
    // L.deleteElement(50);
    // L.Display();
    L.clear();
    L.Display();
     
     
   
     
    return 0;
}