#include<iostream>
using namespace std ;

class node
{
     public :
               int data ;
               node* next ;

               node(int d)
               {
                    data = d ;
                    this-> next = NULL;               
               }

};

void insertnode(node* &tail , int element , int d)
{

     //when insert first element 
     if(tail == NULL)
     {
          node* curr = new node(d);
          curr->next = curr ;
          tail = curr ;
     }
     else
     {
          node* temp = tail;
          node* newnode = new node(d);

          while(element != temp->data)
          {
               temp = temp->next ;
          }

          newnode->next = temp->next;
          temp->next = newnode;

     }

}


void print(node* head)
{
     node* temp = head ;

     do
     {
          cout << head->data << "  ";
          head = head->next ;   

     } while (head != temp);

     cout << endl ;     

}

node* GetMid(node* head)
{
     node* fast = head->next ;
     node* slow = head ;

     while(fast != NULL && fast->next != NULL)
     {
          slow = slow ->next ;
          fast = fast ->next ;
     }

     return slow;
}


node* convert (node* &head)
{
     node* mid = GetMid(head);
     node* temp = mid ;

     node* secondll = mid->next ;

     //first ll is circular
     mid ->next = head ;

     //make second ll
     
}




int main ()
{
     node* head = NULL ;

     insertnode(head,5,3);
     insertnode(head,3,12);
     insertnode(head,10,7);
     insertnode(head,7,5);
     insertnode(head,3,10);
     print(head);
     
     return 0;
}