
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

void Inserttail(node* &tail,int d)
{
     node* temp = new node(d);

     tail -> next = temp ;
     temp ->prev = tail ;
     tail = temp ;

}

node* ReverseNode(node* &head)
{
     node* temp = head ;

     while(temp != NULL)
     {
          

     }




}



int main ()
{
     node* node1 = new node(10) ;
     node* head = node1 ;
     node* tail = node1 ;

     print(head);

     Inserttail(tail,20);
     print(head);

     Inserttail(tail,30);
     print(head);

     Inserttail(tail,40);
     print(head);


     return 0;
}