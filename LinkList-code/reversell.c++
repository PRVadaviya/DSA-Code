#include<iostream>
using namespace std ;

class node
{
     public :
          int data ;
          node* next ;

          node(int data)
          {
               this->data = data;
               this->next = NULL ;
          }
};

node* reversenode(node* &head)
{

     node* prev = NULL ;
     node* curr = head ;
     node* forward = NULL ;

     if(head == NULL || head->next == NULL)
     {
          return head ;
     }

     while(curr != NULL)
     {
          forward = curr -> next ;
          curr ->next = prev ;
          prev = curr ;
          curr = forward ;
     }

     return prev ;

}

void print(node* &head)
{
     node* imp = head ;

     while(imp != NULL)
     {
          cout <<"data -- "<< imp->data << "\t" ;
          imp = imp->next ;
     }

     cout << endl ;

}

void insert (node* &tail ,int d)
{
     node* temp = new node(d);
     tail -> next  = temp ;
     tail = temp ;      
}

void reverseprint(node* &head)
{
     node* present = head ;

     while(present != NULL)
     {
          cout << present->data<< "  " ;
          present = present->next ;
     }
}

int main ()
{
     node* node1 = new node(10);
     node* head = node1 ;
     node* tail = node1;
     node* joy = NULL ;

     print (tail);

     insert(head , 20);
     print(tail);

     insert(head,30);
     print(tail);

     insert(head,40);
     print(tail);

     insert(head,50);
     print(tail);

     joy = reversenode(head);
     reverseprint(joy);


     return 0;
}