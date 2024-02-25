
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

void GetLenth (node* &head)
{
     int count =0;
     node* temp = head ;
     while(temp != NULL)
     {
          count++;
          temp = temp -> next ;
     }
     cout <<"Length -- "<< count << endl ;
}

void Inserthead (node* &head , int d)
{
     node* temp = new node(d) ;
     temp -> next = head ;
     head -> prev = temp ;
     head = temp ;
}

int main ()
{
     node* node1 = new node(20) ;
     node* head = node1 ;

     print(head);

     Inserthead(head,30);
     print(head);

     Inserthead(head,40);
     print(head);

     return 0;
}