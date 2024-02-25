
#include<iostream>
using namespace std ;

class node 
{
     public :
               int data ;
               node* prev  ;
               node* next  ;

               node(int d)
               {
                    data = d ;
                    this-> prev = NULL;
                    this-> next = NULL;               
               }
};

void print(node* &head)
{
     node* temp = head ;

     while(temp != NULL)
     {
          cout <<"data -- "<< temp->data << "\t" ;
          temp = temp->next ;
     }

     cout << endl ;

}

void Inserttail (node* &tail , int d)
{
     node* temp = new node(d);
     temp ->prev = tail ;
     tail-> next = temp ;
     tail = temp ;

}

int main ()
{
     node* node1 = new node(20) ;
     
     node* tail = node1 ;
     node* head = node1 ;

     print(head);

     Inserttail(tail,30);
     print(head);

     Inserttail(tail,40);
     print(head);

     return 0;
}