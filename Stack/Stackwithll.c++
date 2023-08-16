#include<iostream>
using namespace std ;

class Node
{
     public :
               int data ;
               Node* next;
               Node* front;

               Node()
               {

               }

               Node(int d)
               {
                    data = d ;
                    next = NULL;
                    front = NULL;
               }

               void push (int d)
               {
                    Node* nn = new Node(d);

                    if(front == NULL)
                    {
                         front = nn ;
                         cout << "this element inserted :" << front->data << endl ;
                         return ;
                    }

                    nn->next = front ;       //insert at head 
                    front = nn ;
                    
                    cout << "this element inserted :" << front->data << endl ;
               }

               void pop ()
               {
                    if(front==NULL)
                    {
                         cout << "not possible to pop" << endl;
                    }

                    Node* temp = front ;
                    front  = front ->next ;
                    cout << "this element deleted :" << temp->data << endl ;
                    temp ->next = NULL ;
                    delete temp ; 

               }
};


int main ()
{
     Node n1(0) ;
     n1.push(10);
     n1.push(20);
     n1.push(30);
     n1.pop();
     n1.pop();

     return 0;
}



