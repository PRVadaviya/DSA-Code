#include<iostream>
using namespace std ;

class Node
{
     public :
               int data ;
               Node* next;
               Node* front;
               Node* back;

               Node()
               {

               }

               Node(int d)
               {
                    data = d ;
                    next = NULL;
                    front = NULL;
                    back = NULL ;
               }

               void push (int d)
               {
                    Node* nn = new Node(d);

                    if(front == NULL)
                    {
                         front = nn ;
                         back = nn ;
                         cout << "this element inserted :" << front->data << endl ;
                         return ;
                    }

                    back->next = nn ;
                    back = nn ;
                    cout << "this element inserted :" << back->data << endl ;
               }

               void pop ()
               {
                    if(front==NULL)
                    {
                         cout << "not possible to pop" << endl;
                         return ;
                    }

                    Node* temp = front ;
                    front = front -> next ;
                    temp->next = NULL ;
                    cout << "this element is deleted : " << temp->data << endl ;
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

     return 0;
}



